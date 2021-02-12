#include "Agent.h"
#include <iostream>

Agent::Agent(Environnement* environnement) {
	this->capteur = new Capteur(environnement);
	this->effecteur = new Effecteur(environnement);
}