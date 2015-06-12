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
    Ui::ajouterTacheUnitaire *ui;

    void accept();

public:
    explicit ajouterTacheUnitaire(QWidget *parent = 0, Projet* projet = 0);
    ~ajouterTacheUnitaire();

};

#endif // AJOUTERTACHEUNITAIRE_H
