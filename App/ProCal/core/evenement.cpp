#include "headers/evenement.h"



const QString &Activite::getDesc() const
{
    QString& desc = *new QString(getDebut().toString("hh:mm"));
    desc += " - " ;
    desc += getFin().toString("hh:mm") += "\n";
    return desc += type;
}
