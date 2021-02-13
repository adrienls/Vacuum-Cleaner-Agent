#include "Environment.h"

Environment::Environment() {
	this->grid = new Grid(5, 5, 1);
}

Grid* Environment::getGrid() {
	return this->grid;
}