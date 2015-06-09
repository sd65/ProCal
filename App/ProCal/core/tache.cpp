#include "headers/tache.h"

QString Tache::toString() const {
    QString d = this->getNom();
    d.append(" | DISPO : " + this->getDisponibilite().toString());
    d.append(" | ECHEANCE : " + this->getEcheance().toString());
    d.append(" | UNITAIRE : " + this->isUnitaireToString());
    foreach(Tache* tache, this->pred)
    {
        d.append(" | PRED : " + tache->getNom());
    }
    foreach(Tache* tache, this->succ)
    {
        d.append(" | SUCC : " + tache->getNom());
    }
    return d;
}

QString TacheUnitaire::toString() const {
    QString d = Tache::toString();
    d.append(" | Duree : " + QString::number(this->getDuree()));
    d.append(" | Preemptive : " + this->isPreemptiveToString());
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
