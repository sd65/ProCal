#ifndef PROJET_H
#define PROJET_H

#include <QDate>
#include <QString>
#include <QColor>
#include <QDebug>

#include "tache.h"


class Tache; // Forward declare

class Projet
{

private:

    QString nom;
    QDate disponibilite;
    QDate echeance;
    QMap<QString, Tache*> taches;
    QColor couleur;

public:

    Projet(QString n, QDate d, QDate e) : nom(n), disponibilite(d), echeance(e) {
        QColor colors[] {"#d1e277", "#f9dd81", "#ffc265", "#ff9696", "#d7afe6"};
        couleur = colors[rand() % (sizeof(colors)/sizeof(*colors))];
    }

    void creerTacheUnitaire(const QString& pnom, const QTime& pduree = QTime(0,10), const bool& pisPreemptive = false, Tache* ppred = nullptr, const QDate& pdisponibilite = QDate::currentDate(), const QDate& pecheance = QDate::currentDate().addMonths(1));

    void creerTacheComposite(const QString& pnom, const QList<Tache*>& pcomposition, Tache* ppred = nullptr, const QDate& pdisponibilite = QDate::currentDate(), const QDate& pecheance = QDate::currentDate().addMonths(1));

    QMap<QString, Tache*>* getTaches() { return &taches; }
    const QColor& getCouleur() const { return couleur; }
    const QString getNom() const { return nom; }
    const QDate getDisponibilite() const { return disponibilite; }
    const QDate getEcheance() const { return echeance; }
    Tache *getParent(Tache *tacheChild);
};

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

    QMap<QString, Projet*>* getProjets() { return &projets; }

};


#endif // PROJET_H
