#ifndef MAINWINDOWPROJET_H
#define MAINWINDOWPROJET_H

#include <QMainWindow>

namespace Ui {
class MainWindowProjet;
}

class MainWindowProjet : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowProjet(QWidget *parent = 0);
    ~MainWindowProjet();

private:
    Ui::MainWindowProjet *ui;
};

#endif // MAINWINDOWPROJET_H
