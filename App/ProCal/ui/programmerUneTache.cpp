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

    QDateTime fin = QDateTime(ui->debut->date(), ui->debut->time().addSecs(tache->getDuree()->second() + tache->getDuree()->hour() * 3600 + tache->getDuree()->minute() * 60));

    Programmation& myProgrammationManager = Programmation::getInstance();
    Evenement* e = myProgrammationManager.progExistanteEntre(ui->debut->dateTime(), fin);
    if( e != nullptr)
    {
        message += "\nIl y a déjà '" + e->getNom() + "' de prévu à ce moment !";
        statusOk = false;
    }

    if(tache->getPred() != nullptr && *tache->getPred()->getFin() > ui->debut->dateTime())
    {
        message += "\nLa fin la tache prédente de cette tache est programée pour après le début de cette tache !";
        statusOk = false;
    }

    if(statusOk)
    {
        myProgrammationManager.programmer(tache,ui->debut->dateTime(), fin);
        this->close();
    }
    else
        if (showErrorsAndAskWhatToDo(message))
            this->close();
}
