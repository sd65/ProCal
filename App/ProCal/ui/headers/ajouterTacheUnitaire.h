#ifndef AJOUTERTACHEUNITAIRE_H
#define AJOUTERTACHEUNITAIRE_H

#include <QDialog>
#include "core/headers/projet.h"

namespace Ui {
class ajouterTacheUnitaire;
}

class ajouterTacheUnitaire : public QDialog
{
    Q_OBJECT

    Projet* projet;

public:
    explicit ajouterTacheUnitaire(QWidget *parent = 0, Projet* projet = 0);
    ~ajouterTacheUnitaire();

private:
    Ui::ajouterTacheUnitaire *ui;
    void accept();
};

#endif // AJOUTERTACHEUNITAIRE_H
