#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QDate>
#include <QMap>

class Evenement
{

private:

    QDateTime debut;
    QDateTime fin;

public:

    Evenement() : debut(QDateTime()), fin(QDateTime()) {}

    virtual QString toString() const =0;

    virtual QDateTime getDebut() const { return debut; }
    QDateTime getFin() const { return fin; }

    void setDebut(const QDateTime &value) { debut = value; }
    void setFin(const QDateTime &value) { fin = value; }
};

class Activite : public Evenement
{

private:

	QString nom;
	QString type;

public:

    Activite(const QString& n, const QString& t) : nom(n), type(t) {}

    QString toString() const;

    const QString& getNom() const { return nom; }
    const QString& getType() const { return type; }

    /*
    void setNom(const QString &value) { nom = value; } 
    void setType(const QString &value) { type = value; } 
    */

};

//////////////////////
// CLASS ActiviteManager

class ActiviteManager
{

private:

    QMap<QString, Activite*> activites;

    // Singleton
    ActiviteManager() {}
    ActiviteManager(ActiviteManager const&) = delete;
    void operator=(ActiviteManager const&) = delete;
    // End Singleton

public:

    // Singleton
    static ActiviteManager& getInstance()
    {
        static ActiviteManager instance;
        return instance;
    }
    // End Singleton

     void creerActivite(const QString& n, const QString& t)
    {
        Activite* newActivite= new Activite(n, t);
        activites.insert(n, newActivite);
    }

    QMap<QString, Activite*>* getActivites() { return &activites; }

};


// END CLASS ActiviteManager
///////////////////////////


#endif // EVENEMENT_H
