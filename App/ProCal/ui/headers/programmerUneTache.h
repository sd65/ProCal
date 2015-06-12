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

public:
    explicit programmerUneTache(QWidget *parent = 0, Tache* ptache = 0);
    ~programmerUneTache();

private:
    Ui::programmerUneTache *ui;
};

#endif // PROGRAMMERUNETACHE_H
