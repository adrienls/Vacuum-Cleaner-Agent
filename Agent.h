#ifndef VACUUM_CLEANER_AGENT_AGENT_H
#define VACUUM_CLEANER_AGENT_AGENT_H

#include "Environment.h"
#include "Sensor.h"
#include "Effector.h"
#include <vector>

using std::vector;

class Agent {
private:
    Environment environment;
    Sensor sensor;
    Effector effector;

    // Belief
    bool isAlive;
    unsigned int x;
    unsigned int y;
    float score;
    unsigned int electricity;

    // Desires
    vector<int> jewelCells;
    vector<int> dirtyCells;

    // Intention
    vector<int> path;

    bool amIAlive() const;
    void updateMyState();
    void chooseAnAction();
    void justDoIt(int step);

    void informedExploration();
    void uninformedExploration();
    Grid* Expand(int X, int Y);

public:
    explicit Agent(Environment &environment) : environment(environment), sensor(environment), effector(environment), isAlive(true), x(0), y(0), score(0), electricity(0) {}
    virtual ~Agent() = default;
};

#endif //VACUUM_CLEANER_AGENT_AGENT_H

