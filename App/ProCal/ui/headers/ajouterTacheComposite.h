#ifndef AJOUTERTACHECOMPOSITE_H
#define AJOUTERTACHECOMPOSITE_H

#include <QDialog>

#include "core/headers/projet.h"

namespace Ui {
class ajouterTacheComposite;
}

class ajouterTacheComposite : public QDialog
{
    Q_OBJECT

    Projet* projet;
    Ui::ajouterTacheComposite *ui;

    void accept();

public:
    explicit ajouterTacheComposite(QWidget *parent = 0, Projet* projet = 0);
    ~ajouterTacheComposite();

};

#endif // AJOUTERTACHECOMPOSITE_H
