#include <algorithm>

#include <QApplication>
#include <QDebug>
#include <QDate>

#include "ui/headers/mainwindow.h"
#include "core/headers/projet.h"
#include "core/headers/programmation.h"

#define creerTacheConteneur( nom, ... )  QList<Tache*> * nom = new QList<Tache*> __VA_ARGS__;

int main(int argc, char *argv[])
{

    ////////////////
    // Create Projet

    ProjetManager& myProjetManager = ProjetManager::getInstance();
    myProjetManager.creerProjet("Projet un");
    myProjetManager.creerProjet("Projet deux", QDate(2020,1,1));
    myProjetManager.creerProjet("Projet trois", QDate(2030,1,1), QDate(2030,1,2));
/*
    // For each
    foreach(Projet* projet, myProjetManager.getProjets())
        qDebug() << projet->toString();


    // Select one
    Projet* p1 = myProjetManager.getProjets().value("Projet un");
    qDebug() << p1->toString();

    ///////////////
    // Create Taches

    p1->creerTacheUnitaire("Tache1");
    p1->creerTacheUnitaire("Tache3");


    foreach(Tache* tache, p1->getTaches())
        qDebug() << tache->toString();

    Tache* t1 = p1->getTaches().value("Tache1");
    Tache* t3 = p1->getTaches().value("Tache3");

    creerTacheConteneur(pred, {t1});
    creerTacheConteneur(succ, {t3});
    p1->creerTacheUnitaire("Tache2", 10, false, *pred, *succ);
    Tache* t2 = p1->getTaches().value("Tache2");
    qDebug() << t2->toString();

    creerTacheConteneur(compo, {t1, t2, t3});
    p1->creerTacheComposite("TacheComposite1", *compo);
    qDebug() << p1->getTaches().value("TacheComposite1")->toString();

    /////////////
    // Activite
*/
    ActiviteManager& myActiviteManager = ActiviteManager::getInstance();
    myActiviteManager.creerActivite("Activité un", "Balancoire");
    myActiviteManager.creerActivite("Activité deux", "RDV galant");
/*
    // For each
    foreach(Activite* activite, myActiviteManager.getActivites())
        qDebug() << activite->toString();

    Activite* a1 = myActiviteManager.getActivites().value("Activité un");
    qDebug() << a1->toString();
    Activite* a2 = myActiviteManager.getActivites().value("Activité deux");


    /////////////////
    // Programmation

    Programmation& myProgrammation = Programmation::getInstance();
    myProgrammation.programmer(a1, QDateTime::currentDateTime().addSecs(3600), QDateTime::currentDateTime().addSecs(10000));
    myProgrammation.programmer(a2, QDateTime::currentDateTime().addMonths(1), QDateTime::currentDateTime().addMonths(1).addSecs(3600));

    myProgrammation.programmer(t2, QDateTime::currentDateTime().addMonths(2), QDateTime::currentDateTime().addMonths(2).addSecs(3600));

    foreach(Evenement* evenement, myProgrammation.getProgrammation())
        qDebug() << evenement->toString();
    */

    ////////
    // UI

    bool launchUI = true;
    if(launchUI) {
        QApplication a(argc, argv);
        MainWindow w;
        w.showMaximized();
        return a.exec();
     }
}
