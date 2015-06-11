#include "headers/projet.h"

bool Projet::creerTacheUnitaire(const QString &pnom, const int &pduree, const bool &pisPreemptive, Tache* ppred, const QDate &pdisponibilite, const QDate &pecheance) {
    bool status = this->precheck(pdisponibilite, pecheance);
    if(!pisPreemptive && pduree > 12)
        qWarning("Votre tache ne peut pas excéder 12h sans être preemptive !");
    else if (status)
    {
        status = true;
        TacheUnitaire* newTache = new TacheUnitaire(pnom, pduree, pisPreemptive, ppred, pdisponibilite, pecheance, this);
        taches.insert(pnom, newTache);
    }
    return status;
}

bool Projet::creerTacheComposite(const QString &pnom, const QList<Tache *> &pcomposition, Tache* ppred, const QDate &pdisponibilite, const QDate &pecheance) {
    bool status = this->precheck(pdisponibilite, pecheance);
    foreach(Tache* tache, pcomposition)
    {
        if(pecheance < tache->getEcheance())
        {
                qWarning("Une des taches a une date d'échéance suppérieure à la tache composite !");
                status = false;
        }
    }
    if(pecheance > this->getEcheance())
        qWarning("Votre tache a une date d'échéance suppérieure à son projet' !");
    else if (status)
    {
        status = true;
        TacheComposite* newTache = new TacheComposite(pnom, pcomposition, ppred, pdisponibilite, pecheance, this);
        taches.insert(pnom, newTache);
    }
    return status;
}

bool Projet::precheck (const QDate &pdisponibilite, const QDate &pecheance) const
{
    bool status = false;
    if(pecheance > this->echeance)
            qWarning("Votre tache a une date d'échéance suppérieure à son projet !");
    else if(pdisponibilite > pecheance)
            qWarning("Votre tache a une date d'échéance inférieure à sa date de disponibilité !");
    else
        status = true;
    return status;

}

QString Projet::toString() const {
    QString d = this->getNom();
    d.append(" | Dispo : " + this->disponibilite.toString());
    d.append(" | Dispo : " + this->echeance.toString());
    return d;
}
