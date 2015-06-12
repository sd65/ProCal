#include "headers/programmation.h"

bool Programmation::programmer(Evenement * e, const QDateTime& d, const QDateTime& f)
{
    bool status = false;
    if (d > f)
        qWarning("Votre programmation a un début plus tardif que sa fin !");
    programmation.append(e);
    e->setDebut(d);
    e->setFin(f);
    return status;
}

bool Programmation::progExistanteEntre(const QDateTime &d, const QDateTime &f)
{
    bool ok = false;
    foreach (Evenement* prog, programmation) {
        if (prog->getDebut().date() == d.date())
            if (d.time() > prog->getDebut().time() && d.time() < prog->getFin().time() || f.time() > prog->getDebut().time() && f.time() < prog->getFin().time() || d.time() < prog->getDebut().time() && f.time() > prog->getFin().time() )
                ok=true;
    }
    return ok;
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
