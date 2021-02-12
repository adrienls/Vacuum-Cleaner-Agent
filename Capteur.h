#pragma once

#include "Environnement.h"

class Capteur {
public:
	Capteur(Environnement* environnement);
	Grid* ObserveEnvironmentWithAllMySensors();
private:
	Environnement* environnement;
};