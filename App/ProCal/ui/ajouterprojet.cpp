#include "ui/headers/ajouterprojet.h"
#include "ui_ajouterprojet.h"

ajouterProjet::ajouterProjet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouterProjet)
{
    ui->setupUi(this);
}

ajouterProjet::~ajouterProjet()
{
    delete ui;
}
