#include "headers/tache.h"

QString Tache::toString() const {
    QString d = this->getNom();
    d.append(" | DISPO : " + this->getDisponibilite().toString());
    d.append(" | ECHEANCE : " + this->getEcheance().toString());
    d.append(" | UNITAIRE : " + this->isUnitaireToString());
    d.append(" | color : " + this->getColor().name());
    if (pred != nullptr)
        d.append(" | PRED : " + pred->getNom());

    return d;
}

const QColor& Tache::getColor() const
{
    return projet->getCouleur();
}

QString TacheUnitaire::toString() const {
    QString d = Tache::toString();
    d.append(" | Duree : " + this->getDuree().toString());
    d.append(" | Preemptive : " + this->isPreemptiveToString());
    d.append(" PROGRAMMATION | debut : " + this->getDebut().toString());
    d.append(" | fin : " + this->getFin().toString());
    return d;
}

QString TacheComposite::toString() const {
    QString d = Tache::toString();
    foreach(Tache* tache, this->composition)
    {
        d.append(" | CONTIENT : " + tache->getNom());
    }
    return d;
}
