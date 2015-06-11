#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

#include "headers/ajouteractivite.h"
#include "ui_ajouteractivite.h"

#include "headers/ajouterprojet.h"
#include "ui_ajouterprojet.h"

#include "core/headers/evenement.h"
#include "core/headers/projet.h"

#include "core/headers/programmation.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->updateListeActivites();
    this->updateListeProjets();
    this->updateVueHebdomadaire();

    connect(ui->ajouterActivite, SIGNAL (clicked()), this, SLOT (boutonajouterActivite()));
    connect(ui->ajouterProjet, SIGNAL (clicked()), this, SLOT (boutonajouterProjet()));
    connect(ui->calendrier, SIGNAL (clicked(QDate)), this, SLOT (updateLundiCourant(QDate)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::boutonajouterActivite()
{
    ajouterActivite a;
    a.exec();
    this->updateListeActivites();
}

void MainWindow::boutonajouterProjet()
{
    ajouterProjet a;
    a.exec();
}

void MainWindow::updateListeActivites()
{
    while(ui->listeActivites->count()>0)
      ui->listeActivites->takeItem(0);

    QFont wantedFont;
    wantedFont.setPointSize(20);

    ActiviteManager& myActiviteManager = ActiviteManager::getInstance();
    foreach(Activite* activite, *myActiviteManager.getActivites())
    {
        QListWidgetItem * item = new  QListWidgetItem(activite->getNom());
        item->setFont(wantedFont);
        ui->listeActivites->addItem(item);
    }
    ui->listeActivites->sortItems();
}

void MainWindow::updateLundiCourant(const QDate & date)
{
    jourSelectionne = date;
}

void MainWindow::updateVueHebdomadaire()
{
   //Mise à jour des labels horizontaux
    QStringList listeJours(getSelectedMonday().toString());
    int i;
    for(i=0;i<7;i++){
        listeJours << getSelectedMonday().addDays(i).toString();
    }
    ui->vueHebdomadaire->setHorizontalHeaderLabels(listeJours);

    qDebug() << getSelectedMonday().toString();

   //Mise à jour des labels Verticaux
    QStringList listeHeures;
    QTime h(8,0) ;
    for(i=1; i<=48; i++){
        listeHeures << h.toString();
        h = h.addSecs(60 * 15);
    }
    ui->vueHebdomadaire->setVerticalHeaderLabels(listeHeures);

   //Mise à jour des evenements de la semaine

    Programmation& myProgrammation = Programmation::getInstance();

    foreach(Evenement* evenement, *myProgrammation.getWeekEvents(getSelectedMonday()))
        qDebug() << evenement->getNom();

}

void MainWindow::updateListeProjets()
{
    while(ui->listeProjets->count()>0)
      ui->listeProjets->takeItem(0);

    QFont wantedFont;
    wantedFont.setPointSize(20);

    ProjetManager& myProjetManager = ProjetManager::getInstance();
    foreach(Projet* projet, *myProjetManager.getProjets())
    {
        QListWidgetItem * item = new  QListWidgetItem(projet->getNom());
        item->setFont(wantedFont);
        ui->listeProjets->addItem(item);
    }
    ui->listeProjets->sortItems();
}
