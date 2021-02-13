#include "Problem.h"

Problem::Problem(std::vector<int> iState, std::vector<int> mAvaliable, int cost, Environnement env) {
	this->initialState = iState;
	this->mouvesAvaliable = mAvaliable;
	this->actionCost = cost;
	this->environnement = &env;
}
bool goalAchieved() {
	return false;
}

std::vector<int> parkour() {
	std::vector<int> p;
	p[0] = 1;
	return p;
}