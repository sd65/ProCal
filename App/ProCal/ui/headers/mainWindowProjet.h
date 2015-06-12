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

    Projet* projet;

public:
    explicit MainWindowProjet(QWidget *parent, QString pprojetName);
    ~MainWindowProjet();

public slots:
    void updateDetailTache(QTreeWidgetItem *item, int column);
    void boutonAddUnitaire();
    void boutonAddComposite();
    void boutonProgrammerTache();

private:
    Ui::MainWindowProjet *ui;

    void updateListeTache();
};

#endif // MAINWINDOWPROJET_H
