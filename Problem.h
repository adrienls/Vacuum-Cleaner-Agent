#ifndef VACUUM_CLEANER_AGENT_PROBLEM_H
#define VACUUM_CLEANER_AGENT_PROBLEM_H

#include"Environment.h"
#include<vector>

using std::vector;

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

    Problem(const vector<int> &initialState, const vector<int> &movesAvailable, int actionCost,
            const Environment &environment) : initialState(initialState), movesAvailable(movesAvailable),
                                              actionCost(actionCost), environment(environment) {}
    virtual ~Problem() = default;
};

#endif //VACUUM_CLEANER_AGENT_PROBLEM_H