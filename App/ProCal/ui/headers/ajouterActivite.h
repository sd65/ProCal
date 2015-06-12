#ifndef AJOUTERACTIVITE_H
#define AJOUTERACTIVITE_H

#include <QDialog>

namespace Ui {
class ajouterActivite;
}

class ajouterActivite : public QDialog
{
    Q_OBJECT

    Ui::ajouterActivite *ui;

    void accept();

public:
    explicit ajouterActivite(QWidget *parent = 0);
    ~ajouterActivite();

};

#endif // AJOUTERACTIVITE_H
