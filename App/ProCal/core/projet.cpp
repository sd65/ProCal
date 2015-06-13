#include "headers/projet.h"

/*!
  Create an tache unitaire
   \param pnom const QString& Name
   \param pduree const QTime& Duration
   \param pisPreemptive const bool& If preemtive
   \param ppred Tache* The pred tache, nullptr if none
   \param pdisponibilite const QDate&
   \param pecheance const QDate&
 */
void Projet::creerTacheUnitaire(const QString &pnom, const QTime &pduree, const bool &pisPreemptive, Tache* ppred, const QDate &pdisponibilite, const QDate &pecheance) {
    TacheUnitaire* newTache = new TacheUnitaire(pnom, pduree, pisPreemptive, ppred, pdisponibilite, pecheance, this);
    taches.insert(pnom, newTache);

}

/*!
   \param pnom const QString& Name
   \param ppred Tache* The pred tache, nullptr if none
   \param pdisponibilite const QDate&
   \param pecheance const QDate&
   \param pcomposition const QList<Tache *> & A list of all tache inside this new composite tache

 */
void Projet::creerTacheComposite(const QString &pnom, const QList<Tache *> &pcomposition, Tache* ppred, const QDate &pdisponibilite, const QDate &pecheance) {
    TacheComposite* newTache = new TacheComposite(pnom, pcomposition, ppred, pdisponibilite, pecheance, this);
    taches.insert(pnom, newTache);
}

/*!
   Return the parent of a tache should not be called. Use tache->getTache()
   \param Tache* tacheChild The tache
   \return Tache* The parent tache or nullptr
 */
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
