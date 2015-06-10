#include "ui/headers/ajouteractivite.h"
#include "ui_ajouteractivite.h"

#include <QDebug>
#include <QCloseEvent>

ajouterActivite::ajouterActivite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouterActivite)
{
    ui->setupUi(this);
}

ajouterActivite::~ajouterActivite()
{
    delete ui;
}

void ajouterActivite::closeEvent(QCloseEvent *event)
{
    qDebug() << ui->label->text();
    qDebug() << "DONE !";
    event->accept();
}

void ajouterActivite::accept() {
    this->close();
}



