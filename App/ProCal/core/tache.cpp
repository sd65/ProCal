#include "headers/tache.h"

Tache *Tache::getParent()
{
    return projet->getParent(this);
}

const QColor& Tache::getColor() const
{
    return projet->getCouleur();
}

const QString &Tache::getDesc() const
{
    QString& desc = *new QString(this->getNom());
    desc += "\n";
    desc += getDebut().toString("hh:mm") += " - " ;
    desc += getFin().toString("hh:mm") += "\nProjet : ";
    return desc += projet->getNom();
}

QString Tache::toHtml() const {
    QString d;
    d.append("<h1>" + this->getNom() + "</h1>");
    d.append("<p><b>Date de disponibilité : </b>" + this->getDisponibilite().toString("dddd dd MMMM yyyy") + "</p>");
    d.append("<p><b>Date d'échéance : </b>" + this->getEcheance().toString("dddd dd MMMM yyyy") + "</p>");
    d.append("<p><b>Unitaire : </b>" + this->isUnitaireToString() + "</p>");
    if (pred != nullptr)
        d.append("<p><b>Prédécesseur : </b>" + pred->getNom() + "</p>");
    if (!this->getDebut().isNull())
        d.append("<p><b>Programmé de </b>" + this->getDebut().toString("dddd dd MMMM yyyy HH:mm") + " à " + this->getFin().toString("dddd dd MMMM yyyy HH:mm") + "</p>");
    return d;
}

QString TacheUnitaire::toHtml() const {
    QString d = Tache::toHtml();
    d.append("<p><b>Durée : </b>" + this->getDuree().toString()+ "</p>");
    d.append("<p><b>Preemptive : </b>" + this->isPreemptiveToString()+ "</p>");
    return d;
}

QString TacheComposite::toHtml() const {
    QString d = Tache::toHtml();
    d.append("<p><b>Contient :</b></p><ul>");
    foreach(Tache* tache, this->composition)
    {
        d.append("<li>" + tache->getNom()+ "</li>");
    }
    d.append("</ul>");
    return d;
}
