#pragma once
#include<vector>

class States {
public:
	int getGridState();
	std::vector<int> getPosition();
	States(std::vector<int> pos, int gState);
	States();
private:
	std::vector<int> positon;
	int gridState;
};