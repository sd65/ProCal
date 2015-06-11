#include "ui/headers/ajouterTacheComposite.h"
#include "ui_ajouterTacheComposite.h"

ajouterTacheComposite::ajouterTacheComposite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouterTacheComposite)
{
    ui->setupUi(this);
}

ajouterTacheComposite::~ajouterTacheComposite()
{
    delete ui;
}
