#include <QCloseEvent>
#include <QMessageBox>

#include "core/headers/programmation.h"
#include "core/headers/evenement.h"

#include "ui/headers/ajouterActivite.h"
#include "ui_ajouterActivite.h"
#include "ui/headers/uiHelpers.h"

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

/*!
  Override default behaviour of accept buttons or enter key. Performs checks before insert datas.
 */
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
    Evenement* e = myProgrammationManager.progExistanteEntre(ui->debut->dateTime(), ui->fin->dateTime());
    if( e != nullptr)
    {
        message += "\nIl y a déjà '" + e->getNom() + "' de prévu à ce moment !";
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
        if (showErrorsAndAskWhatToDo(message))
            this->close();
}



