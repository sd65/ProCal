#include "headers/evenement.h"


QString Activite::toString() const {
    QString d = this->getNom();
    d.append(" | Type : " + this->getType());
    d.append(" PROGRAMMATION | debut : " + this->getDebut().toString());
    d.append(" | fin : " + this->getFin().toString());
    return d;
}
