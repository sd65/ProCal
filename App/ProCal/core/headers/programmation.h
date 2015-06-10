#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H

#include "evenement.h"
#include <QDebug>

class Programmation
{
private:
    QList<Evenement*> programmation;

    // Singleton
    Programmation() {}
    Programmation(Programmation const&) = delete;
    void operator=(Programmation const&) = delete;
    // End Singleton

public:

    // Singleton
    static Programmation& getInstance()
    {
        static Programmation instance;
        return instance;
    }
    // End Singleton

    bool programmer(Evenement *e, const QDateTime &d, const QDateTime &f);

    int getDureeRestante(Evenement&);

    QList<Evenement*>* getProgrammation() { return &programmation; }

    QList<Evenement*>* getWeekEvents(const QDate& monday);
};

#endif // PROGRAMMATION_H
