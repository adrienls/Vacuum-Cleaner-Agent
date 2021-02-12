#include "Environnement.h"

Environnement::Environnement() {
	this->grid = new Grid(5, 5, 1);
}

Grid* Environnement::getGrid() {
	return this->grid;
}