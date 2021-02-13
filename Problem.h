#pragma once
#include"Environnement.h"
#include<vector>
class Problem {
	
public:
	bool goalAchived();
	std::vector<int> parkour();
	Problem(std::vector<int> initial, std::vector<int> mouvesAvaliable, int cost, Environnement env);
private:
	std::vector<int> initialState;
	std::vector<int> mouvesAvaliable;
	int actionCost;
	Environnement* environnement;
};