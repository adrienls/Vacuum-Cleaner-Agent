#pragma once

#include "Environnement.h"

class Capteur {
public:
	Capteur(Environnement* environnement);
	Grid* ObserveEnvironmentWithAllMySensors();
	Grid* ObserveAdjacentEnvironment(int, int);
private:
	Environnement* environnement;
};