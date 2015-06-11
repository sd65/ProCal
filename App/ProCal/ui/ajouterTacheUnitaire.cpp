#include "ui/headers/ajouterTacheUnitaire.h"
#include "ui_ajouterTacheUnitaire.h"

#include "core/headers/projet.h"

#include <QMessageBox>
#include <QRadioButton>


ajouterTacheUnitaire::ajouterTacheUnitaire(QWidget *parent, Projet* pprojet) :
    QDialog(parent),
    ui(new Ui::ajouterTacheUnitaire)
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



}

ajouterTacheUnitaire::~ajouterTacheUnitaire()
{
    delete ui;
}

void ajouterTacheUnitaire::accept() {
    bool statusOk = true;
    QString message;

    if(ui->nom->text().isEmpty())
    {
        message += "Remplissez le titre du de la tache !";
        statusOk = false;
    }

    if(ui->duree->time() < QTime(0,1))
    {
        message += "\nLa durée est invalide !";
        statusOk = false;
    }

    if(ui->duree->time().hour() > 12)
    {
        message += "\nLa durée ne peut dépasser 12 heures !";
        statusOk = false;
    }

    if(ui->disponibilite->date() > ui->echeance->date())
    {
        message += "\nL'échéance est antérieure à la date de disponibilité !";
        statusOk = false;
    }

    if(statusOk)
    {
        Tache* pred = nullptr;
        if(ui->constraitsToogle->isChecked())
            pred = projet->getTaches()->value(ui->listeTachesPred->currentItem()->text());
        projet->creerTacheUnitaire(ui->nom->text(), ui->duree->time(), ui->preemptive->isChecked(), pred, ui->disponibilite->date(), ui->echeance->date());
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
