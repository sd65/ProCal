#ifndef MAINWINDOWPROJET_H
#define MAINWINDOWPROJET_H

#include <QMainWindow>

namespace Ui {
class MainWindowProjet;
}

class MainWindowProjet : public QMainWindow
{
    Q_OBJECT

    QString nomProjet;

public:
    explicit MainWindowProjet(QWidget *parent, QString pprojetName);
    ~MainWindowProjet();


private:
    Ui::MainWindowProjet *ui;
};

#endif // MAINWINDOWPROJET_H
