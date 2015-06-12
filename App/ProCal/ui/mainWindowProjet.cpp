#include "ui/headers/mainWindowProjet.h"
#include "ui_mainWindowProjet.h"

#include "headers/ajouterTacheUnitaire.h"
#include "ui_ajouterTacheUnitaire.h"

#include "headers/ajouterTacheComposite.h"
#include "ui_ajouterTacheComposite.h"

#include "headers/programmerUneTache.h"
#include "ui_programmerUneTache.h"

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
    connect(ui->addProg, SIGNAL (clicked()), this, SLOT (boutonProgrammerTache()));

    this->updateListeTache();
}

MainWindowProjet::~MainWindowProjet()
{
    delete ui;
}

void MainWindowProjet::updateDetailTache(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);
    Tache * t1 = projet->getTaches()->value(item->text(0));
    ui->detailTache->setHtml(t1->toHtml());
}

void MainWindowProjet::boutonAddUnitaire()
{
    ajouterTacheUnitaire a(this, projet);
    a.exec();
    this->updateListeTache();
}

void MainWindowProjet::boutonAddComposite()
{
    ajouterTacheComposite a(this, projet);
    a.exec();
    this->updateListeTache();
}

void MainWindowProjet::boutonProgrammerTache()
{
    Tache* ptache = projet->getTaches()->value(ui->tree->currentItem()->text(0));
    programmerUneTache a(this, ptache);
    a.exec();
}

void MainWindowProjet::updateListeTache()
{
    ui->tree->clear();
    QMap<Tache*, QTreeWidgetItem *> alreadyInTable;
    QTreeWidgetItem * t;
    int nbInserted = 0;
    const int nbTotal = (projet->getTaches())->size();

    while(nbInserted != nbTotal)
    {
        foreach(Tache* tache, *projet->getTaches())
        {
            if (!alreadyInTable.contains(tache))
            {
                if(tache->getParent() == nullptr)
                {
                    t = new QTreeWidgetItem();
                    t->setText(0, tache->getNom());
                    if (tache->getPred() != nullptr)
                        t->setText(1, tache->getPred()->getNom());
                    else
                        t->setText(1, "✘ Aucune");
                    ui->tree->addTopLevelItem(t);
                    alreadyInTable.insert(tache, t);
                    nbInserted++;
                }
                else if (alreadyInTable.contains(tache->getParent()))
                {
                    t = new QTreeWidgetItem(alreadyInTable.value(tache->getParent()));
                    t->setText(0, tache->getNom());
                    if (tache->getPred() != nullptr)
                        t->setText(1, tache->getPred()->getNom());
                    else
                        t->setText(1, "✘ Aucune");
                    alreadyInTable.insert(tache, t);
                    nbInserted++;
                }
            }
        }
    }
    ui->tree->expandAll();
}
