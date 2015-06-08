#include <algorithm>

#include <QApplication>
#include  <QDebug>
#include  <QDate>


#include "ui/headers/mainwindow.h"
#include "core/headers/projet.h"

int main(int argc, char *argv[])
{
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


    /* /// UI ///
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */
}
