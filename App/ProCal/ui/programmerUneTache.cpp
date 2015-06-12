#include "ui/headers/programmerUneTache.h"
#include "ui_programmerUneTache.h"

programmerUneTache::programmerUneTache(QWidget *parent, Tache *ptache) :
    QDialog(parent),
    ui(new Ui::programmerUneTache)
{
    ui->setupUi(this);
    tache = ptache;

    ui->debut->setDate(QDate::currentDate());
    ui->debut->setMinimumDate(tache->getDisponibilite());
    ui->debut->setMaximumDate(tache->getEcheance());

    ui->fin->setDate(QDate::currentDate().addDays(1));
    ui->fin->setMinimumDate(tache->getDisponibilite());
    ui->fin->setMaximumDate(tache->getEcheance());

    ui->resume->setHtml(tache->toHtml());

}

programmerUneTache::~programmerUneTache()
{
    delete ui;
}
