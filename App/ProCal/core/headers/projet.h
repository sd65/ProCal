#ifndef PROJET_H
#define PROJET_H

#include <vector>

#include <QDate>
#include <QString>
#include <QDebug>

#include "tache.h"

using namespace std;

////////////////
// CLASS Projet

class Projet
{

private:

    QString nom;
    QDate disponibilite;
    QDate echeance;
    QMap<QString, Tache*> taches;

public:

    Projet(QString n, QDate d, QDate e) : nom(n), disponibilite(d), echeance(e) {}

    bool creerTacheUnitaire(const QString& pnom, const int& pduree = 10, const bool& pisPreemptive = false, const QList<Tache*>& ppred = QList<Tache*>(), const QList<Tache*>& psucc = QList<Tache*>(), const QDate& pdisponibilite = QDate::currentDate(), const QDate& pecheance = QDate::currentDate().addMonths(1)); // See CPP

    bool creerTacheComposite(const QString& pnom, const QList<Tache*>& pcomposition, const QList<Tache*>& psucc = QList<Tache*>(), const QList<Tache*>& ppred = QList<Tache*>(), const QDate& pdisponibilite = QDate::currentDate(), const QDate& pecheance = QDate::currentDate().addMonths(1)); // See CPP

    bool precheck(const QDate &pdisponibilite, const QDate &pecheance) const; // See CPP

    QString toString() const; // See CPP

    QMap<QString, Tache*> getTaches() const { return taches; }
    const QString getNom() const { return nom; }
    const QDate getDisponibilite() const { return disponibilite; }
    const QDate getEcheance() const { return echeance; }

    /* Unused setters
    void setNom(const QString &value) { nom = value; }
    void setDisponibilite(const QDate &value) { disponibilite = value; }
    void setEcheance(const QDate &value) { echeance = value; }
    */
};

// END CLASS Projet
//////////////////////////


//////////////////////
// CLASS ProjetManager

class ProjetManager
{

private:

    QMap<QString, Projet*> projets;

    // Singleton
    ProjetManager() {}
    ProjetManager(ProjetManager const&) = delete;
    void operator=(ProjetManager const&) = delete;
    // End Singleton

public:

    // Singleton
    static ProjetManager& getInstance()
    {
        static ProjetManager instance;
        return instance;
    }
    // End Singleton

     void creerProjet(const QString& n, const QDate& d = QDate::currentDate(), const QDate &e = QDate::currentDate().addYears(1))
    {
        Projet* newProject = new Projet(n, d, e);
        projets.insert(n, newProject);
    }

    QMap<QString, Projet*> getProjets() const { return projets; }

};


// END CLASS ProjetManager
///////////////////////////


#endif // PROJET_H
