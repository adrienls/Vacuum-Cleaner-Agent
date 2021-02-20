#include "Problem.h"
#include "States.h"

bool Problem::goalAchieved() {
	int c = 0;
	Grid grid = environment.getGrid();
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			if (grid.getCell(i, j) == 0) c++;
		}
	}
	if (c == 25) return true;
	return false;
}

vector<std::pair<Mouve,States>> Problem::Succession() {
	vector<std::pair<Mouve,States>> p;
	vector<unsigned int> nextPos;
	Grid grid = environment.getGrid();
	States s = States(initialPos, 0);
	std::pair<Mouve, States> pb;
	for (auto Mouve : movesAvailable)
	{
		switch (Mouve) {
		case GAUCHE:
			nextPos.push_back(this->initialPos[0] - 1);
			nextPos.push_back(this->initialPos[1]);
			s = States(nextPos, (int) grid.getCell(nextPos[0], nextPos[1]));
			pb.first = GAUCHE;
			pb.second = s;
			p.push_back(pb);
			break;
		case HAUT:
			nextPos.push_back(this->initialPos[0]);
			nextPos.push_back(this->initialPos[1] + 1);
			s = States(nextPos, (int) grid.getCell(nextPos[0], nextPos[1]));
			pb.first = HAUT;
			pb.second = s;
			p.push_back(pb);
			break;
		case DROITE:
			nextPos.push_back(this->initialPos[0] + 1);
			nextPos.push_back(this->initialPos[1]);
			s = States(nextPos, (int) grid.getCell(nextPos[0], nextPos[1]));
			pb.first = DROITE;
			pb.second = s;
			p.push_back(pb);
			break;
		case BAS:
			nextPos.push_back(this->initialPos[0]);
			nextPos.push_back(this->initialPos[1] - 1);
			s = States(nextPos, (int) grid.getCell(nextPos[0], nextPos[1]));
			pb.first = BAS;
			pb.second = s;
			p.push_back(pb);
			break;
		}
	}
	return p;
}

vector<int> Problem::path() {
	vector<int> p;
	p.push_back(0);
	return p;
}

//Nodes Problem::makeTree(Grid env) {
//	Nodes initialNode;
//	vector<unsigned int> pos;
//	int s;
//	pos = initialPos;
//	s = env.getCell(pos[0], pos[1]);
//	initialNode.state.setState(pos, s);
//	initialNode.parents = NULL;
//	return initialNode;
//}