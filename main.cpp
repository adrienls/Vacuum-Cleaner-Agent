#include <iostream>
#include <thread>
#include "Agent.h"
#include "Environment.h"

using std::cout, std::endl, std::thread;

void envLoop(Environment* environment){
    environment->generateDirt();
    environment->generateDirt();
    while (environment->isRunning()){
        if (environment->shouldThereBeANewDirtySpace()){
            environment->generateDirt();
            //cout << endl << "---------- New DUST ----------" << endl;
        }
        if (environment->shouldThereBeANewLostJewel()){
            environment->generateJewel();
            //cout << endl << "---------- New JEWEL ----------" << endl;
        }
        //environment->display();
    }
}

int main() {

    Environment environment;

    thread envThread(envLoop, &environment);
    
    Agent agent(&environment);
    
    while (agent.amIAlive()) {
        //agent.observeEnvironmentWithAllMySensors();
        agent.updateMyState();
        for (int step = 0; step < agent.getPath().size(); step++) {
            agent.justDoIt(step);
        }
        agent.chooseAnAction();
    }

    envThread.join();

    return 0;
}