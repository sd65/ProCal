#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QDate>
#include <QMap>
#include <QColor>


class Evenement
{

private:

    QDateTime debut;
    QDateTime fin;

public:

    virtual const QString& getNom() const = 0;
    virtual const QColor& getColor() const = 0;
    virtual const QString& getDesc() const = 0;

    virtual QDateTime getDebut() const { return debut; }
    QDateTime getFin() const { return fin; }

    void setDebut(const QDateTime &value) { debut = value; }
    void setFin(const QDateTime &value) { fin = value; }

protected:

    Evenement(const QDateTime& pdebut = QDateTime(), const QDateTime& pfin = QDateTime()) : debut(pdebut), fin(pfin) {}

};

class Activite : public Evenement
{

private:

    QString nom;
    QString type;
    QColor color;

public:

    Activite(const QString& n, const QString& t, const QDateTime& pdebut, const QDateTime& pfin) : Evenement(pdebut, pfin), nom(n), type(t), color(QColor(255, 0, 0, 127)) {}

    const QString& getNom() const { return nom; }
    const QString& getDesc() const;
    const QColor& getColor() const { return color; }

};

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

    Activite* creerActivite(const QString& n, const QString& t, const QDateTime& pdebut = QDateTime::currentDateTime().addDays(1), const QDateTime& pfin = QDateTime::currentDateTime().addDays(1).addSecs(3600))
    {
        Activite* newActivite= new Activite(n, t, pdebut, pfin);
        activites.insert(n, newActivite);
        return newActivite;
    }

    QMap<QString, Activite*>* getActivites() { return &activites; }

};

#endif // EVENEMENT_H
