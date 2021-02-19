#include"States.h"

std::vector<unsigned int> States::getPosition() {
	return this->positon;
}

int States::getGridState() {
	return this->gridState;
}

States::States(std::vector<unsigned int> pos, int gState) {
	this->positon = pos;
	this->gridState = gState;
}

States::States() {
	std::vector<unsigned int> tmp;
	tmp.push_back(0);
	tmp.push_back(0);
	this->positon = tmp;
	this->gridState = 0;
}
