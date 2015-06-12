#ifndef AJOUTERPROJET_H
#define AJOUTERPROJET_H

#include <QDialog>

namespace Ui {
class ajouterProjet;
}

class ajouterProjet : public QDialog
{
    Q_OBJECT

    Ui::ajouterProjet *ui;

    void accept();

public:
    explicit ajouterProjet(QWidget *parent = 0);
    ~ajouterProjet();

};

#endif // AJOUTERPROJET_H
