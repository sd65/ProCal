#include <algorithm>

#include <QApplication>
#include <QDebug>
#include <QDate>

#include "ui/headers/mainwindow.h"
#include "core/headers/projet.h"

#define creerTacheConteneur( nom, ... )  QList<Tache*> * nom = new QList<Tache*> __VA_ARGS__;

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


    bool launchUI = false;
    if(launchUI) {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();

        return a.exec();
     }
}
