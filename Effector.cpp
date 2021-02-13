#include "Effector.h"

unsigned int Effector::clean(unsigned int x, unsigned int y) {
	int score = 0;
	if (environment.getCell(x, y) == 2)
		score = 1;
	if (environment.getCell(x, y) == 3)
		score = -5;
	if (environment.getCell(x, y) == 3)
		score = -4;
	//this->environment->clean(x, y);
	return score;
}

void Effector::pickUp(unsigned int x, unsigned int y) {
	//this->environment->pickUp(x, y);
}
