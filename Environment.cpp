#include "Environment.h"
#include <random>
#include <iostream>

using std::random_device;

void Environment::cleanCell(unsigned int column, unsigned int row) {
    grid.setCell(column, row, empty);
    nbDust--;
}
void Environment::pickUpJewel(unsigned int column, unsigned int row){
    Cell pickUp = grid.getCell(column, row);
    if (pickUp == both){
        grid.setCell(column, row, dust);
        nbJewel--;
    }
    else if (pickUp == jewel){
        grid.setCell(column, row, empty);
        nbJewel--;
    }
}

bool Environment::shouldThereBeANewDirtySpace() const {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 10.0);

    return dist(mt) > 8;
}
bool Environment::shouldThereBeANewLostJewel() const {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 10.0);

    return dist(mt) > 9;
}

void Environment::randomElement(Cell element) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 4.0);
    unsigned int x = dist(mt);
    unsigned int y = dist(mt);

    grid.setCell(x, y, element);
}
void Environment::generateDirt() {
    randomElement(dust);
    nbDust++;
}
void Environment::generateJewel() {
    randomElement(jewel);
    nbJewel++;
}

void Environment::move(unsigned int x, unsigned int y) {
    grid.setAgentPosition(x, y);
}

