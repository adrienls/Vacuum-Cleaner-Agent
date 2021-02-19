#pragma once
#include<vector>

class States {
public:
	int getGridState();
	std::vector<unsigned int> getPosition();
	States(std::vector<unsigned int> pos, int gState);
	States();
	void setState(std::vector<unsigned int> pos, int s);
private:
	std::vector<unsigned int> positon;
	int gridState;
};