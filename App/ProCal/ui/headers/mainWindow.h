#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QDate"
#include "QDebug"
#include <QMainWindow>
#include <QStandardItem>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void boutonajouterActivite();
    void boutonajouterProjet();
    void updateJourSelectionne(const QDate & date);
    void updateVueHebdomadaire();
    void projetClic(QListWidgetItem* projet);


private:
    Ui::MainWindow *ui;
    QDate jourSelectionne;

    const QDate getSelectedMonday()
    {
        return jourSelectionne.addDays(- jourSelectionne.dayOfWeek() + 1);
    }
    void updateListeActivites();
    void updateListeProjets();

};

#endif // MAINWINDOW_H
