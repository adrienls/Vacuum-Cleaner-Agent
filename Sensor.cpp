#include "Sensor.h"
#include <iostream>

const Grid& Sensor::ObserveEnvironmentWithAllMySensors() {
	return environment->getGrid();
}

//const Grid& Sensor::ObserveAdjacentEnvironment(unsigned int x, unsigned int y) {
//	Grid* adj = new Grid(2, 2);
//	//La case de gauche
//	if (X - 1 < 0) {
//		adj->set(0, 0, NULL);
//	}
//	else {
//		adj->set(0, 0, this->environment->getGrid()->get(X - 1, Y));
//	}
//	//La case du dessus
//	if (Y + 1 > 5) {
//		adj->set(1, 0, NULL);
//	}
//	else {
//		adj->set(1, 0, this->environment->getGrid()->get(X, Y + 1));
//	}
//	//La case de droite
//	if (X + 1 > 5) {
//		adj->set(0, 1, NULL);
//	}
//	else {
//		adj->set(0, 1, this->environment->getGrid()->get(X + 1, Y));
//	}
//	//La case du bas
//	if (Y - 1 < 0) {
//		adj->set(1, 1, NULL);
//	}
//	else {
//		adj->set(1, 1, this->environment->getGrid()->get(X, Y - 1));
//	}
//
//	return adj;
//}
