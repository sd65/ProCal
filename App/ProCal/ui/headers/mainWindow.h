#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QStandardItem>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

    Ui::MainWindow *ui;
    QDate jourSelectionne;

    const QDate getSelectedMonday();
    void updateListeActivites();
    void updateListeProjets();


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void boutonajouterActivite();
    void boutonExportProjet();
    void boutonajouterProjet();
    void updateJourSelectionne(const QDate & date);
    void updateVueHebdomadaire();
    void projetClic(QListWidgetItem* projet);
    void updateExportProjet();

};

#endif // MAINWINDOW_H
