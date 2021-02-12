#pragma once

#include "Grid.h"

class Environnement {
private:
	Grid* grid;

public:
	Environnement();
	Grid* getGrid();
};