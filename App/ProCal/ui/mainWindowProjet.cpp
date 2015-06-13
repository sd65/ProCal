#include <QDebug>

#include "core/headers/projet.h"

#include "ui/headers/mainWindowProjet.h"
#include "ui_mainWindowProjet.h"
#include "headers/ajouterTacheUnitaire.h"
#include "ui_ajouterTacheUnitaire.h"
#include "headers/ajouterTacheComposite.h"
#include "ui_ajouterTacheComposite.h"
#include "headers/programmerUneTache.h"
#include "ui_programmerUneTache.h"


MainWindowProjet::MainWindowProjet(QWidget *parent, QString pprojetName) :
    QMainWindow(parent),
    ui(new Ui::MainWindowProjet)
{
    ui->setupUi(this);

    ProjetManager& myProjetManager = ProjetManager::getInstance();
    projet = myProjetManager.getProjets()->value(pprojetName);

    connect(ui->tree, SIGNAL (itemClicked(QTreeWidgetItem*,int)), this, SLOT (updateDetailTache()));
    connect(ui->tree, SIGNAL (itemSelectionChanged()), this, SLOT (updateDetailTache()));
    connect(ui->addUnitaire, SIGNAL (clicked()), this, SLOT (boutonAddUnitaire()));
    connect(ui->addComposite, SIGNAL (clicked()), this, SLOT (boutonAddComposite()));
    connect(ui->addProg, SIGNAL (clicked()), this, SLOT (boutonProgrammerTache()));

    this->updateListeTache();
}

MainWindowProjet::~MainWindowProjet()
{
    delete ui;
}

/*!
  Click capture event
 */
void MainWindowProjet::updateDetailTache()
{
    Tache * t1 = projet->getTaches()->value(ui->tree->currentItem()->text(0));
    ui->detailTache->setHtml(t1->toHtml());
}

/*!
  Click capture event
 */
void MainWindowProjet::boutonAddUnitaire()
{
    ajouterTacheUnitaire a(this, projet);
    a.exec();
    this->updateListeTache();
}

/*!
  Click capture event
 */
void MainWindowProjet::boutonAddComposite()
{
    ajouterTacheComposite a(this, projet);
    a.exec();
    this->updateListeTache();
}

/*!
  Click capture event
 */
void MainWindowProjet::boutonProgrammerTache()
{
    if(ui->tree->currentItem() != nullptr)
    {
        Tache* ptache = projet->getTaches()->value(ui->tree->currentItem()->text(0));
        if(ptache->isUnitaire())
        {
            programmerUneTache a(this, ptache);
            a.exec();
            this->updateListeTache();
        }
    }
}

void MainWindowProjet::updateListeTache()
{
    ui->tree->clear();
    QMap<Tache*, QTreeWidgetItem *> alreadyInTable;
    int nbInserted = 0;
    const int nbTotal = (projet->getTaches())->size();
    QTreeWidgetItem * t;
    while(nbInserted != nbTotal)
    {
        foreach(Tache* tache, *projet->getTaches())
        {
            if (!alreadyInTable.contains(tache))
            {
                if(tache->getParent() == nullptr)
                {
                    t = new QTreeWidgetItem();
                    this->insertTacheInTree(t, tache, &alreadyInTable);
                    ui->tree->addTopLevelItem(t);
                    nbInserted++;
                }
                else if (alreadyInTable.contains(tache->getParent()))
                {
                    t = new QTreeWidgetItem(alreadyInTable.value(tache->getParent()));
                    this->insertTacheInTree(t, tache, &alreadyInTable);
                    nbInserted++;
                }
            }
        }
    }
    ui->tree->expandAll();
}

/*!
  Insert a tache in the tree view of a projet editor
   \param QTreeWidgetItem * t The item
   \param Tache* tache The tache
   \param QTreeWidgetItem *>*  alreadyInTable Table to save what's already in the tree
 */
void MainWindowProjet::insertTacheInTree(QTreeWidgetItem * t, Tache* tache, QMap<Tache*, QTreeWidgetItem *>* alreadyInTable)
{
    t->setText(0, tache->getNom());
    if (tache->getPred() != nullptr)
        t->setText(1, tache->getPred()->getNom());
    else
        t->setText(1, "✘ Aucune");
    if(tache->getDebut().isNull())
        t->setText(2, "✘");
    else
        t->setText(2, "✔");
    t->setTextAlignment(1, Qt::AlignHCenter);
    t->setTextAlignment(2, Qt::AlignHCenter);
    alreadyInTable->insert(tache, t);
}
