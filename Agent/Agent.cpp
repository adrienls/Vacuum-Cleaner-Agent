#include "Agent.h"
#include <set>
#include <iostream>
#include <cmath>
#include "../Environment/Graph.h"

bool Agent::amIAlive() const {
	return this->isAlive;
}

void Agent::updateMyState() {

    this->dirtyCells.clear();
	this->jewelCells.clear();
	this->path.clear();

    bool informedMode = false;

    if (informedMode) {
        Pair dest = unInformedExploration();
        informedExploration(dest);
    }
    else {
        Pair dest = unInformedExploration();
        if (dest.first != -1 && dest.second != -1) {
            unsigned int xAxes = this->x;
            unsigned int yAxes = this->y;
            while (xAxes != dest.first) {
                if (xAxes > dest.first) xAxes--;
                else xAxes++;
                this->path.emplace_back(xAxes, yAxes);
            }
            while (yAxes != dest.second) {
                if (yAxes > dest.second) yAxes--;
                else yAxes++;
                this->path.emplace_back(xAxes, yAxes);
            }
        }
        
    }
}

void Agent::informedExploration(Pair dest) {
    vector<Pair> pathCoordinates;

    set<pair<double, Pair>> openList;

    bool closedList[5][5];
    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 5; y++) {
            closedList[x][y] = false;
        }

    cell grid[5][5];

    unsigned int xAxes = this->x;
    unsigned int yAxes = this->y;

    grid[xAxes][yAxes].f = 0.0;
    grid[xAxes][yAxes].g = 0.0;
    grid[xAxes][yAxes].h = 0.0;
    grid[xAxes][yAxes].parent_x = xAxes;
    grid[xAxes][yAxes].parent_y = yAxes;

    openList.insert(make_pair(0.0, make_pair(xAxes, yAxes)));

    bool first = true;
    while (!openList.empty())
    {
        pair<double, pair<int, int>> p = *openList.begin();

        openList.erase(openList.begin());

        xAxes = p.second.first;
        yAxes = p.second.second;

        closedList[xAxes][yAxes] = true;

        double newG, newH, newF;

        vector<Pair> neighbours;

        if (xAxes - 1 >= 0 && xAxes - 1 < 5 && yAxes >= 0 && yAxes < 5) neighbours.emplace_back(xAxes - 1, yAxes);
        if (xAxes + 1 >= 0 && xAxes + 1 < 5 && yAxes >= 0 && yAxes < 5) neighbours.emplace_back(xAxes + 1, yAxes);
        if (xAxes >= 0 && xAxes < 5 && yAxes + 1 >= 0 && yAxes + 1 < 5) neighbours.emplace_back(xAxes, yAxes + 1);
        if (xAxes >= 0 && xAxes < 5 && yAxes - 1 >= 0 && yAxes - 1 < 5) neighbours.emplace_back(xAxes, yAxes - 1);

        for (int i = 0; i < neighbours.size(); i++) {

            int nextX = neighbours[i].first;
            int nextY = neighbours[i].second;

            if (nextX == dest.first && nextY == dest.second) {
                grid[nextX][nextY].parent_x = xAxes;
                grid[nextX][nextY].parent_y = yAxes;

                int pathLength = grid[xAxes][yAxes].f;
                if (first) {
                    pathLength = 1;
                }
                int X = nextX;
                int Y = nextY;

                vector<Pair> path;
                for (int i = 0; i <= pathLength; i++) path.emplace_back(this->x, this->y);

                for (int i = pathLength; i > 0; i--) {
                    path[i] = make_pair(X, Y);
                    X = grid[path[i].first][path[i].second].parent_x;
                    Y = grid[path[i].first][path[i].second].parent_y;
                }
                this->path = path;
                return;
            }
            else if (!closedList[nextX][nextY]) {
                newG = grid[xAxes][yAxes].g + 1.0;
                newH = sqrt((nextX - dest.first) * (nextX - dest.first) + (nextY - dest.second) * (nextY - dest.second));
                newF = newG + newH;

                if (grid[nextX][nextY].f == FLT_MAX || grid[nextX][nextY].f > newF) {
                    openList.insert(make_pair(newF, make_pair(nextX, nextY)));
                    grid[nextX][nextY].f = newF;
                    grid[nextX][nextY].g = newG;
                    grid[nextX][nextY].h = newH;
                    grid[nextX][nextY].parent_x = xAxes;
                    grid[nextX][nextY].parent_y = yAxes;
                }
            }
        }
        first = false;
    }
    return;
}

Pair Agent::unInformedExploration() {
    Grid grid = sensor.ObserveEnvironmentWithAllMySensors();
    Graph graph = Graph(grid);

    Pair dest = graph.BFS(this->x, this->y);
    return dest;
}
void Agent::justDoIt(unsigned int step) {
	x = path[step].first;
	y = path[step].second;
	electricity--;
    this->effector.move(x, y);
}

void Agent::chooseAnAction() {
    Cell cell = environment->getCell(x, y);
	if (cell == dust) {
        cout << "aspirer" << endl;
        this->score = this->score + effector.clean(x, y);
	}
	if (cell == jewel) {
        cout << "ramasser" << endl;
		effector.pickUp(x, y);
	}
	if (cell == both) {
        cout << "ramasser" << endl;
		effector.pickUp(x, y);
        cout << "aspirer" << endl;
		this->score = this->score + effector.clean(x, y);
	}
		
}

void Agent::observeEnvironmentWithAllMySensors() {
    this->sensor.ObserveEnvironmentWithAllMySensors();
}

vector<Pair> Agent::getPath() {
    return this->path;
}

float Agent::getScore() const {
    return this->score;
}
