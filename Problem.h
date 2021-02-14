#ifndef VACUUM_CLEANER_AGENT_PROBLEM_H
#define VACUUM_CLEANER_AGENT_PROBLEM_H

#include"Environment.h"
#include"States.h"
#include<vector>

using std::vector;

enum Mouve {
    GAUCHE = 0,
    HAUT,
    DROITE,
    BAS
};

class Problem {
private:
    vector<unsigned int> initialState;
    vector<unsigned int> movesAvailable;
    unsigned int actionCost;
    Environment environment;

public:
	bool goalAchieved(){
	    return false;
	}
	vector<int> path(){
        vector<int> p;
        p[0] = 1;
        return p;
	}

    Problem(const vector<unsigned int> &initialState, const vector<unsigned int> &movesAvailable, int actionCost,
            const Environment &environment) : initialState(initialState), movesAvailable(movesAvailable),
                                              actionCost(actionCost), environment(environment) {}
    virtual ~Problem() = default;
};

struct Nodes {
    States state;
    Nodes parents;
};

#endif //VACUUM_CLEANER_AGENT_PROBLEM_H