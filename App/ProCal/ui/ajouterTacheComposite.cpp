#include "ui/headers/ajouterTacheComposite.h"
#include "ui_ajouterTacheComposite.h"

#include "core/headers/projet.h"

#include <QMessageBox>
#include <QRadioButton>

ajouterTacheComposite::ajouterTacheComposite(QWidget *parent, Projet* pprojet) :
    QDialog(parent),
    ui(new Ui::ajouterTacheComposite)
{
    ui->setupUi(this);
    projet = pprojet;

    ui->disponibilite->setDate(QDate::currentDate());
    ui->disponibilite->setMinimumDate(projet->getDisponibilite());
    ui->disponibilite->setMaximumDate(projet->getEcheance());

    ui->echeance->setDate(QDate::currentDate().addMonths(1));
    ui->echeance->setMinimumDate(projet->getDisponibilite());
    ui->echeance->setMaximumDate(projet->getEcheance());

    ui->boxconst->setDisabled(true);

    QListWidgetItem *it;
    foreach(Tache* tache, *projet->getTaches())
    {
        it= new QListWidgetItem(tache->getNom());
        ui->listeTachesPred->addItem(it);
    }

    foreach(Tache* tache, *projet->getTaches())
    {
        it = new QListWidgetItem(tache->getNom());
        it->setFlags(it->flags() | Qt::ItemIsUserCheckable);
        it->setCheckState(Qt::Unchecked);
        ui->listeContient->addItem(it);
    }


}

ajouterTacheComposite::~ajouterTacheComposite()
{
    delete ui;
}


void ajouterTacheComposite::accept() {
    bool statusOk = true;
    QString message;

    if(ui->nom->text().isEmpty())
    {
        message += "Remplissez le titre du de la tache !";
        statusOk = false;
    }


    if(ui->disponibilite->date() > ui->echeance->date())
    {
        message += "\nL'échéance est antérieure à la date de disponibilité !";
        statusOk = false;
    }

    if(ui->constraitsToogle->isChecked() && ui->echeance->date() < projet->getTaches()->value(ui->listeTachesPred->currentItem()->text())->getEcheance())
    {
        message += "\nL'échéance de votre tache précédente est supérieure à la date d'échance de cette tache !";
        statusOk = false;
    }

    QList<Tache *> contientTache;
    if(statusOk)
    {
        for(int i = 0; i < ui->listeContient->count(); ++i)
        {
            QListWidgetItem* item = ui->listeContient->item(i);
            if(item->checkState())
             {
                if(ui->echeance->date() < projet->getTaches()->value(item->text())->getEcheance())
                {
                    message += "\nL'échéance de la tache '" + projet->getTaches()->value(item->text())->getNom() + "' est supérieure à la date d'échance de cette tache !";
                    statusOk = false;
                }
                else if (statusOk)
                    contientTache.append(projet->getTaches()->value(item->text()));
             }
        }

    }

    if(statusOk)
    {
        Tache* pred = nullptr;
        if(ui->constraitsToogle->isChecked())
            pred = projet->getTaches()->value(ui->listeTachesPred->currentItem()->text());

        projet->creerTacheComposite(ui->nom->text(), contientTache, pred, ui->disponibilite->date(), ui->echeance->date());
        this->close();
    }
    else
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Attention !", message + "\n\nRééssayer ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::No) {
            this->close();
        }
    }
}
