#include "headers/evenement.h"


const QString &Activite::getDesc() const
{
    QString& desc = *new QString("Activité\n" + this->getNom());
    desc += "\n";
    desc += getDebut().toString("hh:mm") += " - " ;
    desc += getFin().toString("hh:mm") += "\nDescription : ";
    return desc += type;
}
