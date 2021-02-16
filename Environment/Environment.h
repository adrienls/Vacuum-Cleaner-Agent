#ifndef VACUUM_CLEANER_AGENT_ENVIRONMENT_H
#define VACUUM_CLEANER_AGENT_ENVIRONMENT_H

#include "Grid.h"

class Environment {
private:
    bool running;
    unsigned short nbJewel;
    unsigned short nbDust;
    Grid grid;

    void randomElement(Cell element);

public:
    Environment() : running(true), nbJewel(0), nbDust(0), grid(5, 5) {}
    virtual ~Environment() = default;

    void display();
    bool isRunning() const {
        return running;
    }
    unsigned short getNbJewel() const {
        return nbJewel;
    }
    unsigned short getNbDust() const {
        return nbDust;
    }
    const Grid &getGrid() const {
        return grid;
    }
    Cell getCell(unsigned int column, unsigned int row){
        return grid.getCell(column, row);
    }
    void cleanCell(unsigned int column, unsigned int row);
    void pickUpJewel(unsigned int column, unsigned int row);
    void move(unsigned int x, unsigned int y);

    bool shouldThereBeANewDirtySpace() const;
    bool shouldThereBeANewLostJewel() const;

    void generateDirt();
    void generateJewel();

};


#endif //VACUUM_CLEANER_AGENT_ENVIRONMENT_H
