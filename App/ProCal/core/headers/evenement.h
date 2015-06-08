#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QDate>

class Evenement
{
private:
	QDate debut;
	QDate fin;
public:
    Evenement();

    /*
    QDate getDebut() const { return debut; }
    void setDebut(const QDate &value) { debut = value; } 

    QDate getFin() const { return fin; }
    void setFin(const QDate &value) { fin = value; } 
    */
};

class Activite : public Evenement
{
private:
	QString nom;
	QString type;
public:
    Activite();

    /*
    QString getNom() const { return nom; }
    void setNom(const QString &value) { nom = value; } 

    QString getType() const { return type; }
    void setType(const QString &value) { type = value; } 
    */
};


#endif // EVENEMENT_H
