#include "headers/mainWindow.h"
#include "ui_mainWindow.h"

#include "headers/ajouterActivite.h"
#include "ui_ajouterActivite.h"

#include "headers/ajouterProjet.h"
#include "ui_ajouterProjet.h"

#include "headers/mainWindowProjet.h"
#include "ui_mainWindowProjet.h"

#include "core/headers/evenement.h"
#include "core/headers/projet.h"

#include "core/headers/programmation.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    jourSelectionne = QDate::currentDate();

    // Style calendar
    ui->calendrier->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    QTextCharFormat weekendFormat;
    weekendFormat.setForeground(QBrush(QColor("pink"), Qt::SolidPattern));
    ui->calendrier->setWeekdayTextFormat(Qt::Saturday, weekendFormat);
    ui->calendrier->setWeekdayTextFormat(Qt::Sunday, weekendFormat);
    QTableView *view = ui->calendrier->findChild<QTableView*>("qt_calendar_calendarview");
    if (view)
    {
        QPalette pal = view->palette();
        pal.setColor(QPalette::Highlight, QColor("pink"));
        view->setPalette(pal);
    }

    this->updateListeActivites();
    this->updateListeProjets();
    this->updateVueHebdomadaire();


    connect(ui->ajouterActivite, SIGNAL (clicked()), this, SLOT (boutonajouterActivite()));
    connect(ui->ajouterProjet, SIGNAL (clicked()), this, SLOT (boutonajouterProjet()));
    connect(ui->calendrier, SIGNAL (clicked(QDate)), this, SLOT (updateJourSelectionne(QDate)));
    connect(ui->calendrier, SIGNAL (clicked(QDate)), this, SLOT (updateVueHebdomadaire()));
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
    this->updateVueHebdomadaire();
}

void MainWindow::boutonajouterProjet()
{
    ajouterProjet a;
    a.exec();
    this->updateListeProjets();
    this->updateVueHebdomadaire();
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
    Q_UNUSED(date);
    jourSelectionne = ui->calendrier->selectedDate();
}

void MainWindow::projetClic(QListWidgetItem *projet)
{
    MainWindowProjet * a = new MainWindowProjet(this, projet->text());
    a->setAttribute(Qt::WA_DeleteOnClose);
    a->show();
}

void MainWindow::updateVueHebdomadaire() {

    //Nettoyage de l'affichage précédent
    ui->vueHebdomadaire->clearContents();
    ui->vueHebdomadaire->clearSpans();

    //Mise à jour des labels horizontaux
    QStringList listeJours(getSelectedMonday().toString("ddd d"));
    int i;
    for(i=1;i<7;i++){
        listeJours << getSelectedMonday().addDays(i).toString("ddd d");
    }
    ui->vueHebdomadaire->setHorizontalHeaderLabels(listeJours);

    //Mise à jour des labels Verticaux
    QStringList listeHeures;
    QTime h(8,0) ;
    for(i=0; i<=72; i++){
        if(i%6 == 0){
           listeHeures << h.toString("H:mm");
           h = h.addSecs(3600);
           int j=0;
//           while(j!=7){
//               ui->vueHebdomadaire->setSpan(i,j,6,1);
//               j++;
//           }
           j=0;
        }
        else
            listeHeures << QString("");

        ui->vueHebdomadaire->verticalHeader()->setStyleSheet("QHeaderView::section {border : none;}");
    }
    ui->vueHebdomadaire->setVerticalHeaderLabels(listeHeures);


    //Mise à jour des evenements de la semaine

    QFont policeTitre;
    policeTitre.setPointSize(12);

    Programmation& myProgrammation = Programmation::getInstance();
    foreach(Evenement* evenement, *myProgrammation.getWeekEvents(getSelectedMonday())){
        qDebug() << evenement->getNom();
        QTableWidgetItem * titre = new QTableWidgetItem(evenement->getNom());
        titre->setFont(policeTitre);
        titre->setTextAlignment(Qt::AlignCenter);
        titre->setBackgroundColor(evenement->getColor());

        int colonne = (evenement->getDebut().date().daysTo(getSelectedMonday())) + 1;

        int ligne = (evenement->getDebut().time().hour() - 8) * 6;
        ligne = ligne + evenement->getFin().time().minute() / 10;
        ui->vueHebdomadaire->setItem(ligne,-colonne + 1,titre);
        ui->vueHebdomadaire->setSpan(ligne,-colonne + 1,evenement->getDebut().time().secsTo(evenement->getFin().time()) / 600,1);

    }
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
