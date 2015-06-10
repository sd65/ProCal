#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

#include "headers/ajouteractivite.h"
#include "ui_ajouteractivite.h"

#include "headers/ajouterprojet.h"
#include "ui_ajouterprojet.h"

#include "core/headers/evenement.h"
#include "core/headers/projet.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Fake activites
    ActiviteManager& myActiviteManager = ActiviteManager::getInstance();

    QFont wantedFont;
    wantedFont.setPointSize(20);

    // For each add
    foreach(Activite* activite, myActiviteManager.getActivites())
    {
        QListWidgetItem * item = new  QListWidgetItem(activite->getNom());
        item->setFont(wantedFont);
        ui->listeActivites->addItem(item);
    }

    //Fake activites
    ProjetManager& myProjetManager = ProjetManager::getInstance();

    // For each add
    foreach(Projet* projet, myProjetManager.getProjets())
    {
        QListWidgetItem * item = new  QListWidgetItem(projet->getNom());
        item->setFont(wantedFont);
        ui->listeProjets->addItem(item);
    }

    connect(ui->ajouterActivite, SIGNAL (clicked()), this, SLOT (boutonajouterActivite()));
    connect(ui->ajouterProjet, SIGNAL (clicked()), this, SLOT (boutonajouterProjet()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::boutonajouterActivite()
{
    ajouterActivite a;
    a.exec();
}

void MainWindow::boutonajouterProjet()
{
    ajouterProjet a;
    a.exec();
}
