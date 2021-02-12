#pragma once

#include "Environnement.h"

class Effecteur {
public:
	Effecteur(Environnement* environnement);
	int clean(int x, int y);
	void pickUp(int x, int y);
		
private:
	Environnement* environnement;
};
