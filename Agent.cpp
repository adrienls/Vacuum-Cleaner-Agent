#include "Agent.h"
#include <set>
#include <iostream>

bool Agent::amIAlive() const {
	return this->isAlive;
}

void Agent::updateMyState() {

    this->dirtyCells.clear();
	this->jewelCells.clear();
	this->path.clear();

	Grid grid = sensor.ObserveEnvironmentWithAllMySensors();
	unsigned int nbColumn = grid.getNbCol();
	unsigned int nbRow = grid.getNbRow();

	for (unsigned int column = 0; column < nbColumn; column++) {
		for (int row = 1; row < nbRow; row++) {
			if (grid.getCell(column, row) == dust || grid.getCell(column, row) == both) {
				this->dirtyCells.push_back(make_pair(column, row));
			}
			if (grid.getCell(column, row) == jewel || grid.getCell(column, row) == both) {
                this->jewelCells.push_back(make_pair(column, row));
			}
		}
	}
    if (this->dirtyCells.size() != 0) {
        uninformedExploration(this->dirtyCells[0]);
        this->dirtyCells.pop_back();
    }
	//informedExploration();
}
//<----------------------------------------------- TODO HERE ----------------------------------------------------------------------------------------------->
void Agent::uninformedExploration(Pair dest) {
    vector<Pair> path;

    set<pair<double, Pair>> openList;

    bool closedList[5][5];
    memset(closedList, false, sizeof(closedList));

    cell grid[5][5];

    int x = this->x;
    int y = this->y;

    grid[x][y].f = 0.0;
    grid[x][y].g = 0.0;
    grid[x][y].h = 0.0;
    grid[x][y].parent_x = x;
    grid[x][y].parent_y = y;

    openList.insert(make_pair(0.0, make_pair(x, y)));

    while (!openList.empty())
    {
        pair<double, pair<int, int>> p = *openList.begin();

        openList.erase(openList.begin());

        x = p.second.first;
        y = p.second.second;

        if (x >= 0 && x < 5 && y >= 0 && y < 5)
            closedList[x][y] = true;

        double newG, newH, newF;

        vector<Pair> neighbours;

        if (x - 1 >= 0 && x - 1 < 5 && y >= 0 && y < 5) neighbours.push_back(make_pair(x - 1, y));
        if (x + 1 >= 0 && x + 1 < 5 && y >= 0 && y < 5) neighbours.push_back(make_pair(x + 1, y));
        if (x >= 0 && x < 5 && y + 1 >= 0 && y + 1 < 5) neighbours.push_back(make_pair(x, y + 1));
        if (x >= 0 && x < 5 && y - 1 >= 0 && y - 1 < 5) neighbours.push_back(make_pair(x, y - 1));

        for (int i = 0; i < neighbours.size(); i++) {

            int nextX = neighbours[i].first;
            int nextY = neighbours[i].second;

            if (nextX == dest.first && nextY == dest.second) {
                grid[nextX][nextY].parent_x = x;
                grid[nextX][nextY].parent_y = y;

                if (x >= 0 && x < 5 && y >= 0 && y < 5) {
                    int pathLength = grid[x][y].f;

                    int X = nextX;
                    int Y = nextY;

                    vector<Pair> path;
                    for (int i = 0; i < pathLength; i++) path.push_back(make_pair(0, 0));

                    for (int i = pathLength - 1; i >= 0; i--) {
                        path[i] = make_pair(X, Y);
                        X = grid[path[i].first][path[i].second].parent_x;
                        Y = grid[path[i].first][path[i].second].parent_y;
                    }
                    this->path = path;
                    return;
                }
            }
            else if (closedList[nextX][nextY] == false) {
                if (x >= 0 && x < 5 && y >= 0 && y < 5) {
                    newG = grid[x][y].g + 1.0;
                    int x = (nextX - dest.first) * (nextX - dest.first) + (nextY - dest.second) * (nextY - dest.second);
                    newH = sqrt(x);
                    newF = newG + newH;

                    if (grid[nextX][nextY].f == FLT_MAX || grid[nextX][nextY].f > newF) {
                        openList.insert(make_pair(newF, make_pair(nextX, nextY)));
                        grid[nextX][nextY].f = newF;
                        grid[nextX][nextY].g = newG;
                        grid[nextX][nextY].h = newH;
                        grid[nextX][nextY].parent_x = x;
                        grid[nextX][nextY].parent_y = y;
                    }
                }
            }
        }
    }

    return;
}

void Agent::informedExploration() {
	//TODO
}

//Grid* Agent::Expand(unsigned int x, unsigned int y) {
//	this->sensor->ObserveAdjacentEnvironment(X, Y);
//}
//<----------------------------------------------- TODO HERE ------------------------------------------------------------------------------------------------>

void Agent::justDoIt(unsigned int step) {
	x = path[step].first;
	y = path[step].second;
	electricity--;
    cout << "moved to (" << x << "," << y << ")" << endl;
}

void Agent::chooseAnAction() {
    Cell cell = environment.getCell(x, y);
	if (cell == dust) {
		effector.clean(x, y);
	}
	if (cell == jewel) {
		effector.pickUp(x, y);
	}
	if (cell == both) {
		effector.pickUp(x, y);
		effector.clean(x, y);
	}
		
}

void Agent::observeEnvironmentWithAllMySensors() {
    this->sensor.ObserveEnvironmentWithAllMySensors();
}

vector<Pair> Agent::getPath() {
    return this->path;
}
