#include <iostream>
#include <thread>
#include "Agent/Agent.h"
#include "Environment/Environment.h"

using std::cout, std::endl, std::thread;

void envLoop(Environment* environment){
    while (environment->isRunning()){
        if (environment->shouldThereBeANewDirtySpace()){
            environment->generateDirt();
            //cout << endl << "---------- New DUST ----------" << endl;
        }
        if (environment->shouldThereBeANewLostJewel()){
            environment->generateJewel();
            //cout << endl << "---------- New JEWEL ----------" << endl;
        }
        environment->display();
        for (auto runUntil = std::chrono::system_clock::now() + std::chrono::seconds(1);
            std::chrono::system_clock::now() < runUntil;) {
        }
    }
}

int main() {

    Environment environment;

    thread envThread(envLoop, &environment);
    
    Agent agent(&environment);
    
    while (agent.amIAlive()) {
        agent.updateMyState();
        for (int step = 0; step < agent.getPath().size(); step++) {
            agent.justDoIt(step);
            for (auto runUntil = std::chrono::system_clock::now() + std::chrono::seconds(1);
                std::chrono::system_clock::now() < runUntil;) {
            }
        }
        agent.chooseAnAction();
        //printf("score %f\n", agent.getScore());
        for (auto runUntil = std::chrono::system_clock::now() + std::chrono::milliseconds(500);
            std::chrono::system_clock::now() < runUntil;) {
        }
    }

    envThread.join();

    return 0;
}