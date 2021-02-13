#include "Agent.h"
#include <iostream>

Agent::Agent(Environnement* environnement) {
	this->capteur = new Capteur(environnement);
	this->effecteur = new Effecteur(environnement);
	this->X = 0;
	this->Y = 0;
	this->electricite = 0;
	this->isAlive = true;
	while (this->amIAlive()) {
		this->updateMyState();
		for (int etape = 0; etape < this->parcours.size(); etape = etape + 2) {
			this->justDoIt(etape);
			this->chooseAnAction();
		}
	}
}

bool Agent::amIAlive() {
	return this->isAlive;
}

void Agent::updateMyState() {

	this->dirtyCells.clear();
	this->jowelCells.clear();
	this->parcours.clear();

	Grid* grid = this->capteur->ObserveEnvironmentWithAllMySensors();

	for (int row = 1; row < grid->getNbRows(); row++) {
		for (int col = 1; col < grid->getNbCols(); col++) {
			if (grid->get(row, col) == 2 || grid->get(row, col) == 4) {
				this->dirtyCells.push_back(row);
				this->dirtyCells.push_back(col);
			}
			if (grid->get(row, col) == 3 || grid->get(row, col) == 4) {
				this->jowelCells.push_back(row);
				this->jowelCells.push_back(col);
			}
		}
	}

	this->explorationNonInforme();
	//this->explorationInforme();
}
//<----------------------------------------------- TODO HERE ----------------------------------------------------------------------------------------------->
void Agent::explorationNonInforme() {
	//TODO
	Grid* fringeNodes;
	//Récupération des cases adjacentes
	fringeNodes = this->capteur->ObserveAdjacentEnvironment(this->X, this->Y);
	int size = fringeNodes->getNbRows() * fringeNodes->getNbCols();
	

	
}

void Agent::explorationInforme() {
	//TODO
}

Grid* Agent::Expand(int X, int Y) {
	this->capteur->ObserveAdjacentEnvironment(X, Y);
}
//<----------------------------------------------- TODO HERE ------------------------------------------------------------------------------------------------>

void Agent::justDoIt(int etape) {
	this->X = this->parcours[etape];
	this->Y = this->parcours[etape + 1];
	this->electricite--;
}

void Agent::chooseAnAction() {
	if (this->grid->get(this->X, this->Y) == 2) {
		this->effecteur->clean(this->X, this->Y);
	}
	if (this->grid->get(this->X, this->Y) == 3) {
		this->effecteur->pickUp(this->X, this->Y);
	}
	if (this->grid->get(this->X, this->Y) == 4) {
		this->effecteur->pickUp(this->X, this->Y);
		this->effecteur->clean(this->X, this->Y);
	}
		
}