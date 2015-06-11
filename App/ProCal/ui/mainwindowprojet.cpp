#include "ui/headers/mainwindowprojet.h"
#include "ui_mainwindowprojet.h"

MainWindowProjet::MainWindowProjet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowProjet)
{
    ui->setupUi(this);
}

MainWindowProjet::~MainWindowProjet()
{
    delete ui;
}
