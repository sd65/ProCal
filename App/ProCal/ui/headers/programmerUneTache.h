#ifndef PROGRAMMERUNETACHE_H
#define PROGRAMMERUNETACHE_H

#include <QDialog>

#include "core/headers/tache.h"

namespace Ui {
class programmerUneTache;
}

class programmerUneTache : public QDialog
{
    Q_OBJECT

    Tache* tache;

    Ui::programmerUneTache *ui;
    void accept();

public:
    explicit programmerUneTache(QWidget *parent = 0, Tache* ptache = 0);
    ~programmerUneTache();

};

#endif // PROGRAMMERUNETACHE_H
