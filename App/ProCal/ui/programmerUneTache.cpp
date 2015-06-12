#include "ui/headers/programmerUneTache.h"
#include "ui_programmerUneTache.h"

#include "core/headers/programmation.h"

#include <QMessageBox>
#include <QRadioButton>


programmerUneTache::programmerUneTache(QWidget *parent, Tache *ptache) :
    QDialog(parent),
    ui(new Ui::programmerUneTache)
{
    ui->setupUi(this);
    tache = ptache;

    ui->debut->setDateTime(QDateTime::currentDateTime());
    ui->debut->setMinimumDate(tache->getDisponibilite());
    ui->debut->setMaximumDate(tache->getEcheance());

    ui->fin->setDateTime(QDateTime::currentDateTime().addDays(1));
    ui->fin->setMinimumDate(tache->getDisponibilite());
    ui->fin->setMaximumDate(tache->getEcheance());

    ui->resume->setHtml(tache->toHtml());

}

programmerUneTache::~programmerUneTache()
{
    delete ui;
}

void programmerUneTache::accept() {
    bool statusOk = true;
    QString message;

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
        myProgrammationManager.programmer(tache,ui->debut->dateTime(),ui->fin->dateTime());
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
