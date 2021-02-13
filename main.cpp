#include <thread>
#include "Agent.h"
#include "Environment.h"

void createAgentInNewThread(Environment& environment) {
    new Agent(environment);
}

int main() {

    Environment environment();

    std::thread agentThread(createAgentInNewThread, environment);

    while (true) {
        // main thread
    }
    return 0;
}