#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

#include "headers/ajouteractivite.h"
#include "ui_ajouteractivite.h"

#include "core/headers/evenement.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Fake activites
    ActiviteManager& myActiviteManager = ActiviteManager::getInstance();
    myActiviteManager.creerActivite("Activité un", "Balancoire");
    myActiviteManager.creerActivite("Activité deux", "RDV galant");

    QFont wantedFont;
    wantedFont.setPointSize(20);

    // For each add
    foreach(Activite* activite, myActiviteManager.getActivites())
    {
        QListWidgetItem * item = new  QListWidgetItem(activite->getNom());
        item->setFont(wantedFont);
        ui->listeActivites->addItem(item);
    }

    connect(ui->ajouterActivite, SIGNAL (clicked()), this, SLOT (boutonajouterActivite()));
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
