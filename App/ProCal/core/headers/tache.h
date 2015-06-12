#ifndef TACHE_H
#define TACHE_H

#include <QDate>
#include <QString>

#include "evenement.h"
#include "projet.h"

class Projet; // Forward declare

class Tache : public Evenement
{
    friend class TacheUnitaire;

private:

    QString nom;
    Tache* pred;
    QDate disponibilite;
    QDate echeance;
    bool is_Unitaire;
    Projet* projet;

protected:

    Tache(const QString& pnom, Tache* ppred, const bool& pisUnitaire, const QDate& pdisponibilite, const QDate& pecheance, Projet* pprojet) : nom(pnom), pred(ppred), disponibilite(pdisponibilite), echeance(pecheance), is_Unitaire(pisUnitaire), projet(pprojet)  {}

public:

    virtual QString toHtml() const = 0;

    Tache* getParent();
    const QColor& getColor() const;
    const QString& getDesc() const;
    const Projet* getProjet() const { return projet; }
    const QString& getNom() const { return nom; }
    const Tache* getPred() const { return pred; }
    const QDate getDisponibilite() const { return disponibilite; }
    const QDate getEcheance() const { return echeance; }
    bool isUnitaire() const { return is_Unitaire; }
    QString isUnitaireToString() const { return is_Unitaire ? "Oui" : "Non"; }
    virtual QList<Tache*>* getComposition() { return nullptr; }

};


class TacheUnitaire : public Tache
{
private:

    QTime duree;
    bool is_Preemptive;

public:

    TacheUnitaire(const QString& pnom, const QTime& pduree, const bool& pisPreemptive, Tache* ppred, const QDate& pdisponibilite, const QDate& pecheance, Projet* pprojet) : Tache(pnom, ppred, true, pdisponibilite, pecheance, pprojet), duree(pduree), is_Preemptive(pisPreemptive)  {}

    QString toHtml() const;
    QTime getDuree() const { return duree; }
    bool isPreemptive() const { return is_Preemptive; }
    QString isPreemptiveToString() const { return is_Preemptive ? "true" : "false"; }
};

class TacheComposite : public Tache
{

private:

    QList<Tache*> composition;

public:

    TacheComposite(const QString& pnom, const QList<Tache*>& pcomposition, Tache* ppred, const QDate& pdisponibilite, const QDate& pecheance, Projet* pprojet) : Tache(pnom, ppred, false, pdisponibilite, pecheance, pprojet), composition(pcomposition)  {}

    QString toHtml() const;

    QList<Tache*>* getComposition() { return &composition; }
};


#endif // TACHE_H
