#ifndef PROJET_H
#define PROJET_H

#include <vector>

#include <QDate>
#include <QString>
#include  <QDebug>

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

    Projet(QString n, QDate d, QDate e) {
        nom = n;
        disponibilite = d;
        echeance = e;
    }

    QMap<QString, Tache*> getTaches() const { return taches; }

    void creerTacheUnitaire(const QString& pnom, const int& pduree = 10, const bool& pisPreemptive = false, const QList<Tache*>& ppred = QList<Tache*>(), const QList<Tache*>& psucc = QList<Tache*>(), const QDate& pdisponibilite = QDate::currentDate(), const QDate& pecheance = QDate::currentDate().addMonths(1)) {
            TacheUnitaire* newTache = new TacheUnitaire(pnom, pduree, pisPreemptive, psucc, ppred, pdisponibilite, pecheance);
            taches.insert(pnom, newTache);
    }

    const QString getNom() const { return nom; }
    const QDate getDisponibilite() const { return disponibilite; }
    const QDate getEcheance() const { return echeance; }

    /*
    void setNom(const QString &value) { nom = value; }
    void setDisponibilite(const QDate &value) { disponibilite = value; }
    void setEcheance(const QDate &value) { echeance = value; }
    */
};

//////////////////////
// CLASS ProjetManager

class ProjetManager
{
private:

    QMap<QString, Projet*> projets;

    // Singleton
    ProjetManager() {};
    ProjetManager(ProjetManager const&) = delete;
    void operator=(ProjetManager const&) = delete;;
    // End Singleton

public:

    static ProjetManager& getInstance()
    {
        static ProjetManager instance;
        return instance;
    }

    QMap<QString, Projet*> getProjets() const { return projets; }

     void creerProjet(const QString& n, const QDate& d = QDate::currentDate(), const QDate &e = QDate::currentDate().addMonths(1))
    {
        Projet* newProject = new Projet(n, d, e);
        projets.insert(n, newProject);
    }

};


#endif // PROJET_H
