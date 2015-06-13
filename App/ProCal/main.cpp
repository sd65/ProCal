/**
@file main.cpp
*/

#include <algorithm>

#include <QApplication>
#include <QDebug>
#include <QDate>

#include "core/headers/projet.h"
#include "core/headers/programmation.h"

#include "ui/headers/mainWindow.h"
#include "ui_mainWindow.h"


#define creerTacheConteneur( nom, ... ) QList<Tache*> * nom = new QList<Tache*> __VA_ARGS__;

void initWithSomeData();

/*!
    The main function of the program
   \param argc Unused
   \param argv Unused
   \return exec status code
 */
int main(int argc, char *argv[])
{

    initWithSomeData();

    bool launchUI = true;
    if(launchUI) {
        QApplication a(argc, argv);
        MainWindow w;
        w.showMaximized();
        return a.exec();
    }

}

/*!
  This function can populate some data before entering the gui. Useful for debug or presentation purposes.
   \return none
 */
void initWithSomeData ()
{
    ////////////////
    // Projets

    ProjetManager& myProjetManager = ProjetManager::getInstance();

    myProjetManager.creerProjet("Projet un");
    myProjetManager.creerProjet("Projet deux", QDate(2020,1,1));
    myProjetManager.creerProjet("Projet trois", QDate(2030,1,1), QDate(2030,1,2));

    Projet* p1 = myProjetManager.getProjets()->value("Projet un");

    ///////////////
    // Taches

    p1->creerTacheUnitaire("Tache1");
    Tache* t1 = p1->getTaches()->value("Tache1");

    p1->creerTacheUnitaire("Tache3");

    p1->creerTacheUnitaire("Tache2", QTime(0,10), false, t1 , QDate::currentDate().addDays(1), QDate::currentDate().addDays(2));
    Tache* t2 = p1->getTaches()->value("Tache2");

    p1->creerTacheUnitaire("TacheInside1");
    Tache* ti1 = p1->getTaches()->value("TacheInside1");

    p1->creerTacheUnitaire("TacheInside2");
    Tache* ti2 = p1->getTaches()->value("TacheInside2");

    creerTacheConteneur(compo, {ti1, ti2});
    p1->creerTacheComposite("TacheCompositeInside", *compo);
    Tache* tc0 = p1->getTaches()->value("TacheCompositeInside");

    creerTacheConteneur(compo2, {t1, t2, tc0});
    p1->creerTacheComposite("TacheComposite1", *compo2);


    /////////////
    // Activites

    ActiviteManager& myActiviteManager = ActiviteManager::getInstance();

    myActiviteManager.creerActivite("Activité un", "Balancoire");
    Activite* a1 = myActiviteManager.getActivites()->value("Activité un");

    myActiviteManager.creerActivite("Activité deux", "RDV galant");
    Activite* a2 = myActiviteManager.getActivites()->value("Activité deux");


    /////////////////
    // Programmation

    Programmation& myProgrammation = Programmation::getInstance();

    myProgrammation.programmer(a1, QDateTime::currentDateTime().addSecs(3600), QDateTime::currentDateTime().addSecs(3600*3));

    myProgrammation.programmer(a2, QDateTime::currentDateTime().addDays(1), QDateTime::currentDateTime().addDays(1).addSecs(3600));

    myProgrammation.programmer(t2, QDateTime::currentDateTime().addDays(12), QDateTime::currentDateTime().addDays(13).addSecs(3600));

}

/* Some exemples foreach

foreach(Projet* projet, *myProjetManager.getProjets())
    qDebug() << projet->toString();



qDebug() << p1->toString() << p1->getCouleur();

qDebug() << p1->getTaches()->value("TacheComposite1")->toString();

foreach(Tache* tache, *p1->getTaches())
    if(tache->getParent() == nullptr)

qDebug() << tache->getNom() << p1->getParent(tache);

foreach(Tache* tache, *p1->getTaches())
qDebug() << tache->toString();

// For each
foreach(Activite* activite, *myActiviteManager.getActivites())
    qDebug() << activite->toString();


foreach(Evenement* evenement, *myProgrammation.getProgrammation())
    qDebug() << evenement->toString();

foreach(Evenement* evenement, *myProgrammation.getWeekEvents(QDate::currentDate()))
    qDebug() << evenement->toString(); ou ->getColor();

*/
