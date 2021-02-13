#pragma once
#include"Environnement.h"
#include"States.h"
#include<vector>

enum Mouve {
	GAUCHE = 0,
	HAUT = 1,
	DROITE = 2,
	BAS = 3
};

class Problem {
	
public:
	bool goalAchieved();
	std::vector<std::pair<Mouve,States>> Succession();
	Problem(std::vector<int> initial, std::vector<Mouve> mouvesAvaliable, int cost, Environnement env);
private:
	std::vector<int> initialState;
	std::vector<Mouve> mouvesAvaliable;
	int actionCost;
	Environnement* environnement;
};