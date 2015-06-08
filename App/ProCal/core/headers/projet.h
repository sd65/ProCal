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
    Tache** taches;

public:

    Projet(QString n, QDate d, QDate e) {
        nom = n;
        disponibilite = d;
        echeance = e;
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

    void creerProjet(QString n, QDate d = QDate::currentDate(), QDate e = QDate()) {
        if(e.isNull()) // Default argument for echeance
             e = d.addMonths(2);
        Projet* newProject = new Projet(n, d, e);
        projets.insert(n, newProject);
    }

};


#endif // PROJET_H
