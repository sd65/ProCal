#ifndef MAINWINDOWPROJET_H
#define MAINWINDOWPROJET_H

#include <QMainWindow>
#include <QDebug>
#include <QTreeWidgetItem>

#include "core/headers/projet.h"

namespace Ui {
class MainWindowProjet;
}

class MainWindowProjet : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindowProjet *ui;
    Projet* projet;

    void updateListeTache();

public:
    explicit MainWindowProjet(QWidget *parent, QString pprojetName);
    ~MainWindowProjet();

public slots:
    void updateDetailTache();
    void boutonAddUnitaire();
    void boutonAddComposite();
    void boutonProgrammerTache();

};

#endif // MAINWINDOWPROJET_H
