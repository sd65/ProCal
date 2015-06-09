#ifndef TACHE_H
#define TACHE_H

#include <QDate>
#include <QString>

#include "evenement.h"

class Tache
{
private:
	QString nom;
    QList<Tache*> succ;
    QList<Tache*> pred;
	QDate disponibilite;
    QDate echeance;
    bool is_Unitaire;

protected:
    Tache(const QString& pnom, const QList<Tache*>& psucc, const QList<Tache*>& ppred, const bool& pisUnitaire, const QDate& pdisponibilite, const QDate& pecheance) : nom(pnom), succ(psucc), pred(ppred), is_Unitaire(pisUnitaire), disponibilite(pdisponibilite), echeance(pecheance) {}

public:
    const QString& getNom() const { return nom; }
    const QList<Tache*>getSucc() const { return succ; }
    const QList<Tache*> getPred() const { return pred; }
    const QDate getDisponibilite() const { return disponibilite; }
    const QDate getEcheance() const { return echeance; }
    bool isUnitaire() const { return is_Unitaire; }
    QString isUnitaireToString() const { return is_Unitaire ? "true" : "false"; }

    virtual QString toString() const {
       QString d = this->getNom();
       d.append(" | DISPO : " + this->getDisponibilite().toString());
       d.append(" | ECHEANCE : " + this->getDisponibilite().toString());
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

    /*
    void setNom(const QString &value) { nom = value; }
    void setSucc(const Tache** value) { succ = value; }
    void setPred(const Tache** value) { pred = value; }
    void setDisponibilite(const QDate &value) { disponibilite = value; }
    void setEcheance(const QDate &value) { echeance = value; }
    void setUnitaire(const bool &value) { is_Unitaire = value; }
    */
};

//

class TacheUnitaire : public Tache, public Evenement
{
private:
	int duree;
    bool is_Preemptive;
public:
    TacheUnitaire(const QString& pnom, const int& pduree, const bool& pisPreemptive, const QList<Tache*>& psucc, const QList<Tache*>& ppred, const QDate& pdisponibilite, const QDate& pecheance) : Tache(pnom, psucc, ppred, true, pdisponibilite, pecheance), duree(pduree), is_Preemptive(pisPreemptive)  {}

    QString toString() const {
       QString d = Tache::toString();
       d.append(" | Duree : " + QString::number(this->getDuree()));
       d.append(" | Preemptive : " + this->isPreemptiveToString());
       return d;
    }

    int getDuree() const { return duree; }
    bool isPreemptive() const { return is_Preemptive; }
    QString isPreemptiveToString() const { return is_Preemptive ? "true" : "false"; }

    /*
    void setDuree(const int &value) { duree = value; }
    void setPreemtive(const bool &value) { is_Preemtive = value; }
    */
};

//

class TacheComposite : public Tache
{
private:
	Tache** composition;
public:
    TacheComposite();
    QDate fin(TacheComposite&);
};

#endif // TACHE_H
