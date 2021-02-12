#pragma once

#include "Environnement.h"
#include "Capteur.h"
#include "Effecteur.h"
#include <vector>

class Agent {
public:
	Agent(Environnement* environnement);

private:
	Capteur* capteur;
	Effecteur* effecteur;

	//belief
	bool isAlive;
	int X;
	int Y;
	float score;
	int electricite;
	Grid* grid;

	//desires
	std::vector<int> jowelCells;
	std::vector<int> dirtyCells;

	//intention
	std::vector<int> parcours;

	bool amIAlive();
	void updateMyState();
	void chooseAnAction();
	void justDoIt(int etape);
	void explorationInforme();
	void explorationNonInforme();
};