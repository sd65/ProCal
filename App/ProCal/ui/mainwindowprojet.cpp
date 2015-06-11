#include "ui/headers/mainwindowprojet.h"
#include "ui_mainwindowprojet.h"

#include "core/headers/projet.h"

#include <QDebug>

MainWindowProjet::MainWindowProjet(QWidget *parent, QString pprojetName) :
    QMainWindow(parent),
    ui(new Ui::MainWindowProjet)
{
    ui->setupUi(this);
    nomProjet = pprojetName;

    ProjetManager& myProjetManager = ProjetManager::getInstance();
    Projet* p1 = myProjetManager.getProjets()->value(nomProjet);
    /*
    QMap<QString, Tache*>::iterator i = p1->getTaches()->begin();
    bool canExit = false;
    while(!canExit)
    {
        **i.getPred();
        canExit = true;
        if (*igetPred().isEmpty())
        {
            qDebug() << "INSERT NORMAL" << tache->toString();
            QTreeWidgetItem * t = new QTreeWidgetItem();
            t->setText(0, tache->getNom());
            ui->tree->addTopLevelItem(t);
            canExit = false;
        }
        else if (! ui->tree->findItems(tache->getPred()->getNom(), Qt::MatchExactly).isEmpty()) // Si on trouve son pred dans la liste
        {
            qDebug() << "INSERT TWO" << tache->toString();
            //            QTreeWidgetItem * t = new QTreeWidgetItem();
            //            t->setText(0, tache->getNom());

            //            ui->tree->addTopLevelItem(t);
            canExit = false;
        }

        // Loop forever
        if (i == *p1->getTaches()->end())
            i = p1->getTaches()->begin();
        i++;
    }   */


}

MainWindowProjet::~MainWindowProjet()
{
    delete ui;
}
