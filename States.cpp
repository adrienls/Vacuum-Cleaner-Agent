#include"States.h"

std::vector<int> States::getPosition() {
	return this->positon;
}

int States::getGridState() {
	return this->gridState;
}

States::States(std::vector<int> pos, int gState) {
	this->positon = pos;
	this->gridState = gState;
}
States::States() {
	std::vector<int> p;
	this->positon = p;
	this->gridState = NULL;
}