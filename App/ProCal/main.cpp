/**
@file main.cpp
*/

// Do you want the GUI ?
#define launchGUI true

#include <algorithm>

#include <QApplication>
#include <QDebug>
#include <QDate>

#include "core/headers/projet.h"
#include "core/headers/programmation.h"

#include "core/headers/exportManager.h"

#if launchGUI
#include "ui/headers/mainWindow.h"
#include "ui_mainWindow.h"
#endif

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

#if launchGUI
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    return a.exec();
#else
    return 0;
#endif

}

/*!
  This function can populate some data before entering the gui. Useful for debug or presentation purposes.
  NOTES : this rely on the current time to set some schedule. So if you're opening the program in the evening, you won't see anything since the calendat is from 8 am to 8 pm !
   \return none
 */
void initWithSomeData ()
{
    ////////////////
    // Projets

    ProjetManager& myProjetManager = ProjetManager::getInstance();

    myProjetManager.creerProjet("Recette de Spaghettis à la ricotta", QDate::currentDate(), QDate::currentDate().addMonths(6));
    myProjetManager.creerProjet("Partir en vacances", QDate::currentDate(), QDate::currentDate().addDays(10));



    ///////////////
    // Recette de Spaghettis à la ricotta

    Projet* p1 = myProjetManager.getProjets()->value("Recette de Spaghettis à la ricotta");
    p1->creerTacheUnitaire("Aller en Italie");
    Tache* t1 = p1->getTaches()->value("Aller en Italie");

    p1->creerTacheUnitaire("Acheter de bonnes pates fraiches", QTime(0,10), false, t1);
    Tache* t2 = p1->getTaches()->value("Acheter de bonnes pates fraiches");

    creerTacheConteneur(compo, {t1, t2});
    p1->creerTacheComposite("1 - Un bon début", *compo);
    Tache* tc1 = p1->getTaches()->value("1 - Un bon début");

    p1->creerTacheUnitaire("Aller à Va Piano !", QTime(1,0), false, tc1);
    Tache* t3 = p1->getTaches()->value("Aller à Va Piano !");

    creerTacheConteneur(compo2, {t3});
    p1->creerTacheComposite("2 - Tout laisser tomber et...", *compo2 ,tc1);

    ///////////////
    // Partir en vacances

    Projet* p2 = myProjetManager.getProjets()->value("Partir en vacances");

    p2->creerTacheUnitaire("Faire ses valises", QTime(1,0), false);
    Tache* t10 = p2->getTaches()->value("Faire ses valises");

    p2->creerTacheUnitaire("Réaliser que l'on n'est pas en vacances", QTime(1,0), false, t10);
    Tache* t11 = p2->getTaches()->value("Réaliser que l'on n'est pas en vacances");

    /////////////
    // Activites

    ActiviteManager& myActiviteManager = ActiviteManager::getInstance();

    myActiviteManager.creerActivite("Aller voir sa grand mère", "Pour avoir un peu d'argent de poche ?");
    Activite* a1 = myActiviteManager.getActivites()->value("Aller voir sa grand mère");

    myActiviteManager.creerActivite("RDV galant", "Ne pas oublier de se mettre sur son 31.");
    Activite* a2 = myActiviteManager.getActivites()->value("RDV galant");


    /////////////////
    // Programmation

    Programmation& myProgrammation = Programmation::getInstance();

    myProgrammation.programmer(a1, QDateTime::currentDateTime().addSecs(3600), QDateTime::currentDateTime().addSecs(3600*3));

    myProgrammation.programmer(a2, QDateTime::currentDateTime().addDays(1), QDateTime::currentDateTime().addDays(1).addSecs(3600));

    myProgrammation.programmer(t10, QDateTime::currentDateTime().addDays(3), QDateTime::currentDateTime().addDays(3).addSecs(3600));

    myProgrammation.programmer(t11, QDateTime::currentDateTime().addDays(3).addSecs(3600*3), QDateTime::currentDateTime().addDays(3).addSecs(3600*4));

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
