#include <thread>
#include <iostream>
#include "Agent.h"
#include "Environnement.h"

void createAgentInNewThread(Environnement* environnement) {
    new Agent(environnement);
}

int main() {

    Environnement* environnement = new Environnement();

    std::thread agentThread(createAgentInNewThread, environnement);

    while (true) {
        environnement->getGrid()->print();
        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    }
    return 0;
}