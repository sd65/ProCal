#ifndef TACHE_H
#define TACHE_H

#include <QDate>
#include <QString>

#include "evenement.h"
#include "projet.h"
class Projet; // Forward declare

////////////////
// CLASS Tache

class Tache : public Evenement
{

private:

	QString nom;
    QList<Tache*> pred;
	QDate disponibilite;
    QDate echeance;
    bool is_Unitaire;
    Projet* projet;

protected:

    Tache(const QString& pnom, const QList<Tache*>& ppred, const bool& pisUnitaire, const QDate& pdisponibilite, const QDate& pecheance, Projet* pprojet) : nom(pnom), pred(ppred), disponibilite(pdisponibilite), echeance(pecheance), is_Unitaire(pisUnitaire), projet(pprojet)  {}

public:

    virtual QString toString() const=0;

    const Projet* getProjet() const { return projet; }
    const QString& getNom() const { return nom; }
    const QList<Tache*> getPred() const { return pred; }
    const QDate getDisponibilite() const { return disponibilite; }
    const QDate getEcheance() const { return echeance; }
    bool isUnitaire() const { return is_Unitaire; }
    QString isUnitaireToString() const { return is_Unitaire ? "true" : "false"; }

    /*
    void setNom(const QString &value) { nom = value; }
    void setDisponibilite(const QDate &value) { disponibilite = value; }
    void setEcheance(const QDate &value) { echeance = value; }
    void setUnitaire(const bool &value) { is_Unitaire = value; }
    */
};

// END CLASS Tache
//////////////////


///////////////////////
// CLASS Tache Unitaire

class TacheUnitaire : public Tache
{

private:

	int duree;
    bool is_Preemptive;

public:

    TacheUnitaire(const QString& pnom, const int& pduree, const bool& pisPreemptive, const QList<Tache*>& ppred, const QDate& pdisponibilite, const QDate& pecheance, Projet* pprojet) : Tache(pnom, ppred, true, pdisponibilite, pecheance, pprojet), duree(pduree), is_Preemptive(pisPreemptive)  {}

    QString toString() const;

    int getDuree() const { return duree; }
    bool isPreemptive() const { return is_Preemptive; }
    QString isPreemptiveToString() const { return is_Preemptive ? "true" : "false"; }

    /*
    void setDuree(const int &value) { duree = value; }
    void setPreemtive(const bool &value) { is_Preemtive = value; }
    */
};

// END CLASS Tache Unitaire
///////////////////////////


/////////////////////////
// CLASS Tache Composite

class TacheComposite : public Tache
{

private:

    QList<Tache*> composition;

public:

    TacheComposite(const QString& pnom, const QList<Tache*>& pcomposition, const QList<Tache*>& ppred, const QDate& pdisponibilite, const QDate& pecheance, Projet* pprojet) : Tache(pnom, ppred, false, pdisponibilite, pecheance, pprojet), composition(pcomposition)  {}

    QString toString() const;
};

// END CLASS Tache Composite
/////////////////////////////

#endif // TACHE_H
