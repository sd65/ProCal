#include "headers/projet.h"

void Projet::creerTacheUnitaire(const QString &pnom, const QTime &pduree, const bool &pisPreemptive, Tache* ppred, const QDate &pdisponibilite, const QDate &pecheance) {
    TacheUnitaire* newTache = new TacheUnitaire(pnom, pduree, pisPreemptive, ppred, pdisponibilite, pecheance, this);
    taches.insert(pnom, newTache);

}

void Projet::creerTacheComposite(const QString &pnom, const QList<Tache *> &pcomposition, Tache* ppred, const QDate &pdisponibilite, const QDate &pecheance) {
    TacheComposite* newTache = new TacheComposite(pnom, pcomposition, ppred, pdisponibilite, pecheance, this);
    taches.insert(pnom, newTache);
}


Tache *Projet::getParent(Tache *tacheChild)
{
    Tache* tacheParent = nullptr;
    foreach(Tache* tache, *this->getTaches())
    {
        if(!tache->isUnitaire())
            foreach(Tache* tacheInside, *tache->getComposition())
            {
                if (tacheInside == tacheChild)
                {
                    tacheParent = tache;
                    goto endloops;
                }
            }
    }
endloops:
    return tacheParent;
}
