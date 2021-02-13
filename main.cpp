#include <iostream>
#include <thread>
#include "Agent.h"
#include "Environment.h"

using std::cout, std::endl, std::thread;

void envLoop(Environment* environment){
    while (environment->isRunning()){
        if (environment->shouldThereBeANewDirtySpace()){
            environment->generateDirt();
            cout << endl << "---------- New DUST ----------" << endl;
        }
        if (environment->shouldThereBeANewLostJewel()){
            environment->generateJewel();
            cout << endl << "---------- New JEWEL ----------" << endl;
        }
    }
}

int main() {

    Environment environment;
    Agent agent(environment);

    thread envThread(envLoop, &environment);

    while (agent.amIAlive()) {
        agent.observeEnvironmentWithAllMySensors();
        agent.updateMyState();
        agent.chooseAnAction();
        agent.justDoIt();
    }

    envThread.join();

    return 0;
}