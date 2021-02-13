#ifndef VACUUM_CLEANER_AGENT_EFFECTOR_H
#define VACUUM_CLEANER_AGENT_EFFECTOR_H

#include "Environment.h"

class Effector {
private:
    Environment environment;

public:
	explicit Effector(Environment& environment): environment(environment) {}
    virtual ~Effector() = default;

    unsigned int clean(unsigned int x, unsigned int y);
	void pickUp(unsigned int x, unsigned int y);
};

#endif //VACUUM_CLEANER_AGENT_EFFECTOR_H