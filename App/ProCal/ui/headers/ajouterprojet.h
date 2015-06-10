#ifndef AJOUTERPROJET_H
#define AJOUTERPROJET_H

#include <QDialog>

namespace Ui {
class ajouterProjet;
}

class ajouterProjet : public QDialog
{
    Q_OBJECT

public:
    explicit ajouterProjet(QWidget *parent = 0);
    ~ajouterProjet();

private:
    Ui::ajouterProjet *ui;
};

#endif // AJOUTERPROJET_H
