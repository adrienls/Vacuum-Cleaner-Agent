#include "Capteur.h"

Capteur::Capteur(Environnement* environnement) {
	this->environnement = environnement;
}

Grid* Capteur::ObserveEnvironmentWithAllMySensors() {
	return this->environnement->getGrid()->copy();
}