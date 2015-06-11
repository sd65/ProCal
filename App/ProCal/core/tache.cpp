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

QString Tache::toHtml() const {
    QString d;
    d.append("<h1>" + this->getNom() + "</h1>");
    d.append("<p>Date de disponibilité : " + this->getDisponibilite().toString() + "</p>");
    d.append("<p>Date d'échéance : " + this->getEcheance().toString() + "</p>");
    d.append("<p>Unitaire : " + this->isUnitaireToString() + "</p>");
    if (pred != nullptr)
        d.append("<p>Prédécesseur : " + pred->getNom() + "</p>");
    if (!this->getDebut().isNull())
        d.append("<p>Programmé de " + this->getDebut().toString() + " à " + this->getFin().toString() + "</p>");
    return d;
}

Tache *Tache::getParent() { return projet->getParent(this); }

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

QString TacheUnitaire::toHtml() const {
    QString d = Tache::toHtml();
    d.append("<p>Durée : " + this->getDuree().toString()+ "</p>");
    d.append("<p>Preemptive : " + this->isPreemptiveToString()+ "</p>");
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

QString TacheComposite::toHtml() const {
    QString d = Tache::toHtml();
    d.append("<p>Contient :</p><ul>");
    foreach(Tache* tache, this->composition)
    {
        d.append("<li>" + tache->getNom()+ "</li>");
    }
    d.append("</ul>");
    return d;
}
