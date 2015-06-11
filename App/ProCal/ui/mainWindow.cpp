#include "headers/mainWindow.h"
#include "ui_mainwindow.h"

#include "headers/ajouterActivite.h"
#include "ui_ajouteractivite.h"

#include "headers/ajouterProjet.h"
#include "ui_ajouterprojet.h"

#include "headers/mainWindowProjet.h"
#include "ui_mainwindowprojet.h"

#include "core/headers/evenement.h"
#include "core/headers/projet.h"

#include "core/headers/programmation.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    jourSelectionne = QDate::currentDate();
    this->updateListeActivites();
    this->updateListeProjets();
    this->updateVueHebdomadaire();

    connect(ui->ajouterActivite, SIGNAL (clicked()), this, SLOT (boutonajouterActivite()));
    connect(ui->ajouterProjet, SIGNAL (clicked()), this, SLOT (boutonajouterProjet()));
    connect(ui->calendrier, SIGNAL (clicked(QDate)), this, SLOT (updateJourSelectionne(QDate)));
    connect(ui->listeProjets, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(projetClic(QListWidgetItem*)));

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
    this->updateListeProjets();
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

void MainWindow::updateJourSelectionne(const QDate & date)
{
    jourSelectionne = ui->calendrier->selectedDate();
}

void MainWindow::projetClic(QListWidgetItem *projet)
{
    MainWindowProjet * a = new MainWindowProjet(this, projet->text());
    a->setAttribute(Qt::WA_DeleteOnClose);
    a->show();
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
        item->setIcon(QIcon(":/edit-find.svg"));
        ui->listeProjets->addItem(item);
    }
    ui->listeProjets->sortItems();
}
