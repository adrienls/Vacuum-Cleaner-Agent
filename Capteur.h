#pragma once

#include "Environnement.h"

class Capteur {
public:
	Capteur(Environnement* environnement);

private:
	Environnement* environnement;
};