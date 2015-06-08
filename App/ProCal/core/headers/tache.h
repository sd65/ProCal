#ifndef TACHE_H
#define TACHE_H

#include <QDate>
#include <QString>

#include "evenement.h"

class Tache
{
private:
	QString nom;
    const Tache** succ;
    const Tache** pred;
	QDate disponibilite;
    QDate echeance;
    bool is_Unitaire;
public:
    Tache();

    /*
    const QString& getNom() const { return nom; }
    void setNom(const QString &value) { nom = value; }

    const Tache** getSucc() const { return succ; }
    void setSucc(const Tache** value) { succ = value; }

    const Tache** getPred() const { return pred; }
    void setPred(const Tache** value) { pred = value; }

    const QDate getDisponibilite() const { return disponibilite; }
    void setDisponibilite(const QDate &value) { disponibilite = value; }

    const QDate getEcheance() const { return echeance; }
    void setEcheance(const QDate &value) { echeance = value; }

    bool isUnitaire() const { return is_Unitaire; }
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
