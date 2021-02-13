#include "Problem.h"


Problem::Problem(std::vector<int> iState, std::vector<Mouve> mAvaliable, int cost, Environnement env) {
	this->initialState = iState;
	this->mouvesAvaliable = mAvaliable;
	this->actionCost = cost;
	this->environnement = &env;
}
bool Problem::goalAchieved() {
	int c = 0;
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			if (environnement->Environnement::getGrid()->get(i, j) == 0) c++;
		}
	}
	if (c == 25) return true;
	return false;
}

std::vector<std::pair<Mouve,States>> Problem::Succession() {
	std::vector<std::pair<Mouve,States>> p;
	std::vector<int> nextPos;
	States s;
	std::pair<Mouve, States> pb;
	for each (Mouve var in mouvesAvaliable)
	{
		switch (var) {
		case GAUCHE:
			nextPos.push_back(initialState[0] - 1);
			nextPos.push_back(initialState[1]);
			s = States(nextPos, environnement->getGrid()->get(nextPos[0], nextPos[1]));
			pb.first = var;
			pb.second = s;
			p.push_back(pb);
			break;
		case HAUT:
			nextPos.push_back(initialState[0]);
			nextPos.push_back(initialState[1] + 1);
			s = States(nextPos, environnement->getGrid()->get(nextPos[0], nextPos[1]));
			pb.first = var;
			pb.second = s;
			p.push_back(pb);
			break;
		case DROITE:
			nextPos.push_back(initialState[0] + 1);
			nextPos.push_back(initialState[1]);
			s = States(nextPos, environnement->getGrid()->get(nextPos[0], nextPos[1]));
			pb.first = var;
			pb.second = s;
			p.push_back(pb);
			break;
		case BAS:
			nextPos.push_back(initialState[0]);
			nextPos.push_back(initialState[1] - 1);
			s = States(nextPos, environnement->getGrid()->get(nextPos[0], nextPos[1]));
			pb.first = var;
			pb.second = s;
			p.push_back(pb);
			break;
		}
	}
	return p;
}