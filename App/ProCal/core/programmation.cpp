#include "headers/programmation.h"

/*!
  Schedule an event
   \param e Evenement * The event
   \param d const QDateTime&The start time
   \param f const QDateTime&The end time
 */
void Programmation::programmer(Evenement * e, const QDateTime& d, const QDateTime& f)
{
    e->setDebut(d);
    e->setFin(f);
    programmation.append(e);
}

/*!
  If an event is scheduled between those two dates return the pointer to this event otherwise return nullptr
   \param d const QDateTime& The start date time
   \param f const QDateTime& The end date time
   \return Evenement*
 */
Evenement* Programmation::progExistanteEntre(const QDateTime &d, const QDateTime &f)
{
    foreach (Evenement* prog, programmation) {
        if (prog->getDebut()->date() == d.date())
            if ((d.time() > prog->getDebut()->time() && d.time() < prog->getFin()->time()) || (f.time() > prog->getDebut()->time() && f.time() < prog->getFin()->time()) || (d.time() < prog->getDebut()->time() && f.time() > prog->getFin()->time()) )
                return prog;
    }
    return nullptr;
}

/*!
  Return a list of all events scheduled this week
   \param monday const QDate The first day of this week
   \return QList<Evenement *> * The list
 */
QList<Evenement *>* Programmation::getWeekEvents(const QDate &monday)
{
    QList<Evenement*>* weekEvents = new QList<Evenement*>;
    const QDate sunday = monday.addDays(6);
    foreach(Evenement* evenement, *this->getProgrammation())
        if(evenement->getDebut()->date() >= monday && evenement->getDebut()->date() <= sunday)
            weekEvents->append(evenement);
    return weekEvents;
}
