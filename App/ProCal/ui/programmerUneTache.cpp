#include <QMessageBox>
#include <QRadioButton>

#include "core/headers/programmation.h"

#include "ui/headers/programmerUneTache.h"
#include "ui_programmerUneTache.h"
#include "ui/headers/uiHelpers.h"

programmerUneTache::programmerUneTache(QWidget *parent, Tache *ptache) :
    QDialog(parent),
    ui(new Ui::programmerUneTache)
{
    ui->setupUi(this);
    tache = ptache;

    ui->debut->setDateTime(QDateTime::currentDateTime());
    ui->debut->setMinimumDate(tache->getDisponibilite());
    ui->debut->setMaximumDate(tache->getEcheance());

    ui->fin->setDateTime(QDateTime::currentDateTime().addSecs(3600 * 2));
    ui->fin->setMinimumDate(tache->getDisponibilite());
    ui->fin->setMaximumDate(tache->getEcheance());

    ui->resume->setHtml(tache->toHtml());

}

programmerUneTache::~programmerUneTache()
{
    delete ui;
}

/*!
  Override default behaviour of accept buttons or enter key. Performs checks before insert datas.
 */

void programmerUneTache::accept() {
    bool statusOk = true;
    QString message;

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
        myProgrammationManager.programmer(tache,ui->debut->dateTime(),ui->fin->dateTime());
        this->close();
    }
    else
        if (showErrorsAndAskWhatToDo(message))
            this->close();
}
