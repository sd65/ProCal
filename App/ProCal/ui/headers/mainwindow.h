#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void boutonajouterActivite();
    void boutonajouterProjet();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
