#ifndef VACUUM_CLEANER_AGENT_SENSOR_H
#define VACUUM_CLEANER_AGENT_SENSOR_H

#include "../Environment/Environment.h"

class Sensor {
private:
    Environment* environment;

public:
	explicit Sensor(Environment* environment): environment(environment) {}
    virtual ~Sensor() = default;

    const Grid& ObserveEnvironmentWithAllMySensors();
	const Grid& ObserveAdjacentEnvironment(unsigned int x, unsigned int y);

};

#endif //VACUUM_CLEANER_AGENT_SENSOR_H