#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QDate"
#include "QDebug"
#include <QMainWindow>
#include <QStandardItem>

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

private:
    Ui::MainWindow *ui;
    QDate jourSelectionne;

    const QDate getSelectedMonday()
    {
        return jourSelectionne.addDays(- jourSelectionne.dayOfWeek() + 1);
    }

    void updateVueHebdomadaire();
    void updateListeActivites();
    void updateListeProjets();
    //projetClic(QListWidgetItem*)
};

#endif // MAINWINDOW_H
