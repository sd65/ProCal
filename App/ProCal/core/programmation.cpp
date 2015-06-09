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
