#include "Effector.h"

unsigned int Effector::clean(unsigned int x, unsigned int y) {
	int score = 0;
	if (environment->getCell(x, y) == dust)
		score = 1;
	if (environment->getCell(x, y) == jewel)
		score = -5;
	if (environment->getCell(x, y) == both)
		score = -4;
	environment->cleanCell(x, y);
	return score;
}

void Effector::pickUp(unsigned int x, unsigned int y) {
	//this->environment->pickUp(x, y);
}
