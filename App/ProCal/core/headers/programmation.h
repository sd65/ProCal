#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H

#include "evenement.h"

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

    void programmer(Evenement *e, const QDateTime &d, const QDateTime &f);


    Evenement* progExistanteEntre(const QDateTime &d, const QDateTime &f);

    QList<Evenement*>* getProgrammation() { return &programmation; }
    QList<Evenement*>* getWeekEvents(const QDate& monday);
};

#endif // PROGRAMMATION_H
