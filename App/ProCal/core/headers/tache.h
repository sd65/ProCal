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
public:
    Tache() {}

    Tache(QString pnom, QList<Tache*> psucc, QList<Tache*> ppred, bool pisUnitaire, QDate pdisponibilite, QDate pecheance) : nom(pnom), succ(psucc), pred(ppred), is_Unitaire(pisUnitaire), disponibilite(pdisponibilite), echeance(pecheance) {}

    const QString& getNom() const { return nom; }
    const QList<Tache*>getSucc() const { return succ; }
    const QList<Tache*> getPred() const { return pred; }
    const QDate getDisponibilite() const { return disponibilite; }
    const QDate getEcheance() const { return echeance; }
    bool isUnitaire() const { return is_Unitaire; }

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
    bool is_Preemtive;
public:
    TacheUnitaire();

    /*
    int getDuree() const { return duree; }
    void setDuree(const int &value) { duree = value; }

    bool isPreemtive() const { return is_Preemtive; }
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
