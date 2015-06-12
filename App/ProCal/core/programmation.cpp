#include "headers/programmation.h"

void Programmation::programmer(Evenement * e, const QDateTime& d, const QDateTime& f)
{
    e->setDebut(d);
    e->setFin(f);
    programmation.append(e);
}

Evenement* Programmation::progExistanteEntre(const QDateTime &d, const QDateTime &f)
{
    foreach (Evenement* prog, programmation) {
        if (prog->getDebut().date() == d.date())
            if ((d.time() > prog->getDebut().time() && d.time() < prog->getFin().time()) || (f.time() > prog->getDebut().time() && f.time() < prog->getFin().time()) || (d.time() < prog->getDebut().time() && f.time() > prog->getFin().time()) )
                return prog;
    }
    return nullptr;
}

QList<Evenement *> *Programmation::getWeekEvents(const QDate &monday)
{
    QList<Evenement*>* weekEvents = new QList<Evenement*>;
    const QDate sunday = monday.addDays(6);
    foreach(Evenement* evenement, *this->getProgrammation())
        if(evenement->getDebut().date() >= monday && evenement->getDebut().date() <= sunday)
            weekEvents->append(evenement);
    return weekEvents;
}
