#include <algorithm>

#include <QApplication>
#include  <QDebug>
#include  <QDate>


#include "ui/headers/mainwindow.h"
#include "core/headers/projet.h"

int main(int argc, char *argv[])
{
    ////////////////
    // Create Projet

    ProjetManager& myProjetManager = ProjetManager::getInstance();
    myProjetManager.creerProjet("Projet un");
    myProjetManager.creerProjet("Projet deux", QDate(2020,1,1));
    myProjetManager.creerProjet("Projet trois", QDate(2030,1,1), QDate(2030,1,2));

    // For each
    foreach(Projet* projet, myProjetManager.getProjets())
    {
        qDebug() << projet->getNom() << projet->getDisponibilite() << projet->getEcheance();
    }

    // Select one
    Projet* p1 = myProjetManager.getProjets().value("Projet un");
    qDebug() << p1->getNom();

    ///////////////
    // Create Taches

    p1->creerTacheUnitaire("Tache1");
    p1->creerTacheUnitaire("Tache3");


    foreach(Tache* tache, p1->getTaches())
    {
        qDebug() << tache->toString();
    }

    Tache* t1 = p1->getTaches().value("Tache1");
    Tache* t3 = p1->getTaches().value("Tache3");

    QList<Tache*> * pred = new QList<Tache*> {t1};
    QList<Tache*> * succ = new QList<Tache*> {t3};
    p1->creerTacheUnitaire("Tache2", 20, false, *pred, *succ);
    qDebug() << p1->getTaches().value("Tache2")->toString();












    /* /// UI ///
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */
}
