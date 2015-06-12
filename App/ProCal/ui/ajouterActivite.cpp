#include <QDebug>
#include <QCloseEvent>
#include <QMessageBox>

#include "ui/headers/ajouterActivite.h"
#include "ui_ajouterActivite.h"

#include "core/headers/programmation.h"

#include "core/headers/evenement.h"

ajouterActivite::ajouterActivite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouterActivite)
{
    ui->setupUi(this);
    ui->debut->setDateTime(QDateTime::currentDateTime());
    ui->fin->setDateTime(QDateTime::currentDateTime().addSecs(3600));
}

ajouterActivite::~ajouterActivite()
{
    delete ui;
}

void ajouterActivite::accept() {
    bool statusOk = true;
    QString message;

    if(ui->nom->text().isEmpty() || ui->description->toPlainText().isEmpty())
    {
        message += "Remplissez tous les champs !";
        statusOk = false;
    }

    if(ui->debut->dateTime() > ui->fin->dateTime())
    {
        message += "\nLa fin est antérieure au début !";
        statusOk = false;
    }

    Programmation& myProgrammationManager = Programmation::getInstance();
    if(myProgrammationManager.progExistanteEntre(ui->debut->dateTime(), ui->fin->dateTime()))
    {
        message += "\nIl y a déjà quelque chose de prévu à ce moment !";
        statusOk = false;
    }

    if(statusOk)
    {
        ActiviteManager& myActiviteManager = ActiviteManager::getInstance();
        Activite * myActivite = myActiviteManager.creerActivite(ui->nom->text(), ui->description->toPlainText());

        myProgrammationManager.programmer(myActivite,ui->debut->dateTime(),ui->fin->dateTime());

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



