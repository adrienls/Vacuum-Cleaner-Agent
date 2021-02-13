#ifndef VACUUM_CLEANER_AGENT_ENVIRONMENT_H
#define VACUUM_CLEANER_AGENT_ENVIRONMENT_H

#include "Grid.h"

class Environment {
private:
    bool running;
    unsigned short nbJewel;
    unsigned short nbDust;
    Grid grid;
public:
    Environment() : running(true), nbJewel(0), nbDust(0), grid(5, 5) {}
    virtual ~Environment() = default;

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
        grid.getCell(column, row);
    }
    void cleanCell(unsigned int column, unsigned int row){
        grid.setCell(column, row, empty);
    }
    void pickUpJewel(unsigned int column, unsigned int row){
        Cell pickUp = grid.getCell(column, row);
        if (pickUp == both){
            grid.setCell(column, row, dust);
        }
        else if (pickUp == jewel){
            grid.setCell(column, row, empty);
        }
    }
    void display(){
        grid.display();
    }

};


#endif //VACUUM_CLEANER_AGENT_ENVIRONMENT_H
