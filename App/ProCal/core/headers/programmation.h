#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H

#include "evenement.h"

class Programmation
{
private:
	Evenement** programmation;
public:
    Programmation();
    int getDureeRestante(Evenement&);
};

#endif // PROGRAMMATION_H
