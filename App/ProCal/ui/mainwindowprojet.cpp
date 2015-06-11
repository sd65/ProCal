#include "ui/headers/mainwindowprojet.h"
#include "ui_mainwindowprojet.h"

#include "headers/ajouterTacheUnitaire.h"
#include "ui_ajouterTacheUnitaire.h"


#include "core/headers/projet.h"

#include <QDebug>

MainWindowProjet::MainWindowProjet(QWidget *parent, QString pprojetName) :
    QMainWindow(parent),
    ui(new Ui::MainWindowProjet)
{
    ui->setupUi(this);

    ProjetManager& myProjetManager = ProjetManager::getInstance();
    projet = myProjetManager.getProjets()->value(pprojetName);

    connect(ui->tree, SIGNAL (itemClicked(QTreeWidgetItem*,int)), this, SLOT (updateDetailTache(QTreeWidgetItem*,int)));
    connect(ui->addUnitaire, SIGNAL (clicked()), this, SLOT (boutonAddUnitaire()));
    connect(ui->addComposite, SIGNAL (clicked()), this, SLOT (boutonAddComposite()));

    this->updateListeTache();
}

MainWindowProjet::~MainWindowProjet()
{
    delete ui;
}

void MainWindowProjet::updateDetailTache(QTreeWidgetItem *item, int column)
{
    qDebug() << "UPD" << item->text(0);
    Tache * t1 = projet->getTaches()->value(item->text(0));
    ui->detailTache->setPlainText(t1->toString());
}

void MainWindowProjet::boutonAddUnitaire()
{
    ajouterTacheUnitaire a(this, projet);
    a.exec();
    this->updateListeTache();
}

void MainWindowProjet::boutonAddComposite()
{

}

void MainWindowProjet::updateListeTache()
{
    ui->tree->clear();
    foreach(Tache* tache, *projet->getTaches())
    {
        QTreeWidgetItem * t = new QTreeWidgetItem();
        t->setText(0, tache->getNom());
        ui->tree->addTopLevelItem(t);
    }
}
