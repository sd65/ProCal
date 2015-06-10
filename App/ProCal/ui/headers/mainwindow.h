#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QDate"
#include "QDebug"
#include <QMainWindow>

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
    void updateLundiCourant(const QDate & date);

private:
    Ui::MainWindow *ui;
    QDate jourSelectionne;

    const QDate getSelectedMonday()
    {
        return jourSelectionne.addDays(- jourSelectionne.dayOfWeek() + 1);
    }
};

#endif // MAINWINDOW_H
