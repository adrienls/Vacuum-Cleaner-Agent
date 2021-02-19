#ifndef VACUUM_CLEANER_AGENT_PROBLEM_H
#define VACUUM_CLEANER_AGENT_PROBLEM_H

#include"../Environment/Environment.h"
#include"States.h"
#include<vector>

using std::vector;

enum Mouve { GAUCHE, HAUT, DROITE, BAS };

class Problem {
private:
    vector<unsigned int> initialState;
    vector<Mouve> movesAvailable;
    unsigned int actionCost;
    Environment environment;

public:
    bool goalAchieved();
    vector<int> path();
    vector<std::pair<Mouve, States>> Problem::Succession();
    Problem(const vector<unsigned int> &initialState, const vector<Mouve> &movesAvailable, int actionCost,
            const Environment &environment) : initialState(initialState), movesAvailable(movesAvailable),
                                              actionCost(actionCost), environment(environment) {}
    virtual ~Problem() = default;
};

struct Nodes {
    States state;
    Nodes* parents;
};

#endif //VACUUM_CLEANER_AGENT_PROBLEM_H