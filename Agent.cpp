#include "Agent.h"

bool Agent::amIAlive() const {
	return this->isAlive;
}

void Agent::updateMyState() {

	this->dirtyCells.clear();
	this->jewelCells.clear();
	this->path.clear();

	Grid grid = sensor.ObserveEnvironmentWithAllMySensors();
	unsigned int nbColumn = grid.getNbCol();
	unsigned int nbRow = grid.getNbRow();

	for (unsigned int column = 0; column < nbColumn; column++) {
		for (int row = 1; row < nbRow; row++) {
			if (grid.getCell(column, row) == dust || grid.getCell(column, row) == both) {
				dirtyCells.push_back(column);
				dirtyCells.push_back(row);
			}
			if (grid.getCell(column, row) == jewel || grid.getCell(column, row) == both) {
				jewelCells.push_back(column);
				jewelCells.push_back(row);
			}
		}
	}

    uninformedExploration();
	//informedExploration();
}
//<----------------------------------------------- TODO HERE ----------------------------------------------------------------------------------------------->
void Agent::uninformedExploration() {
	//TODO
	//Grid* fringeNodes;
	////R�cup�ration des cases adjacentes
	//fringeNodes = this->sensor->ObserveAdjacentEnvironment(this->X, this->Y);
	//int size = fringeNodes->getNbRows() * fringeNodes->getNbCols();
	

	
}

void Agent::informedExploration() {
	//TODO
}

Grid* Agent::Expand(unsigned int x, unsigned int y) {
	/*this->sensor->ObserveAdjacentEnvironment(X, Y);*/
}
//<----------------------------------------------- TODO HERE ------------------------------------------------------------------------------------------------>

void Agent::justDoIt(unsigned int step) {
	x = path[step];
	y = path[step + 1];
	electricity--;
}

void Agent::chooseAnAction() {
    Cell cell = environment.getCell(x, y);
	if (cell == dust) {
		effector.clean(x, y);
	}
	if (cell == jewel) {
		effector.pickUp(x, y);
	}
	if (cell == both) {
		effector.pickUp(x, y);
		effector.clean(x, y);
	}
		
}

void Agent::observeEnvironmentWithAllMySensors() {

}
