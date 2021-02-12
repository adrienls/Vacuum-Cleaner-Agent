#include "Effecteur.h"

Effecteur::Effecteur(Environnement* environnement) {
	this->environnement = environnement;
}

int Effecteur::clean(int x, int y) {
	int score = 0;
	if (this->environnement->getGrid()->get(x, y) == 2) 
		score = 1;
	if (this->environnement->getGrid()->get(x, y) == 3)
		score = -5;
	if (this->environnement->getGrid()->get(x, y) == 3)
		score = -4;
	//this->environnement->clean(x, y);
	return score;
}

void Effecteur::pickUp(int x, int y) {
	//this->environnement->pickUp(x, y);
}