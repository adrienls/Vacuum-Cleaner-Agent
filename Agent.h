#pragma once

#include "Environnement.h"
#include "Capteur.h"
#include "Effecteur.h"

class Agent {
public:
	Agent(Environnement* environnement);

private:
	Capteur* capteur;
	Effecteur* effecteur;
};