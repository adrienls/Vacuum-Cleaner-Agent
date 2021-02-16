#ifndef VACUUM_CLEANER_AGENT_AGENT_H
#define VACUUM_CLEANER_AGENT_AGENT_H

#include "../Environment/Environment.h"
#include "Sensor.h"
#include "Effector.h"
#include <vector>
typedef std::pair<int, int> Pair;
using namespace std;
struct cell
{
    int parent_x = -1;
    int parent_y = -1;
    double f = FLT_MAX;
    double g = FLT_MAX;
    double h = FLT_MAX;
};

class Agent {
private:
    Environment* environment;
    Sensor sensor;
    Effector effector;

    // Belief
    bool isAlive;
    unsigned int x;
    unsigned int y;
    float score;
    unsigned int electricity;

    // Desires
    vector<Pair> jewelCells;
    vector<Pair> dirtyCells;
    Pair target;
    bool asTarget = false;

    // Intention
    vector<Pair> path;

    void informedExploration(Pair dest);
    void unInformedExploration(Pair dest);
    Grid* Expand(unsigned int x, unsigned int y);

public:
    explicit Agent(Environment *environment) : environment(environment), sensor(environment), effector(environment), isAlive(true), x(0), y(0), score(0), electricity(0) {}
    virtual ~Agent() = default;

    bool amIAlive() const;
    void observeEnvironmentWithAllMySensors();
    void updateMyState();
    void chooseAnAction();
    void justDoIt(unsigned int step);
    vector<Pair> getPath();
    float getScore() const;
};

#endif //VACUUM_CLEANER_AGENT_AGENT_H

