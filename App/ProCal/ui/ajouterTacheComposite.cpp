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
    ui->echeance->setDate(QDate::currentDate().addMonths(1));
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
        it->setFlags(it->flags() | Qt::ItemIsUserCheckable); // set checkable flag
        it->setCheckState(Qt::Unchecked); // AND initialize check state
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

    if(statusOk)
    {
//        Tache* pred = nullptr;
//        if(ui->constraitsToogle->isChecked())
//            pred = projet->getTaches()->value(ui->listeTachesPred->currentItem()->text());
//        projet->creerTacheUnitaire(ui->nom->text(), ui->duree->time(), ui->preemptive->isChecked(), pred, ui->disponibilite->date(), ui->echeance->date());
//        this->close();
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
