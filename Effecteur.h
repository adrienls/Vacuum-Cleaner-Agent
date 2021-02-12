#pragma once

#include "Environnement.h"

class Effecteur {
public:
	Effecteur(Environnement* environnement);

private:
	Environnement* environnement;
};
