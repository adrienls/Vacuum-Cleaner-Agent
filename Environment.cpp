#include "Environment.h"
#include <random>

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
    return nbDust < 8;
}
bool Environment::shouldThereBeANewLostJewel() const {
    return nbJewel < 5;
}

void Environment::randomElement(Cell element) {
    random_device rd;
    unsigned int x = rd() % grid.getNbCol();
    unsigned int y = rd() % grid.getNbRow();
    while (getCell(x, y) == element || getCell(x, y) == both){
        x = rd() % grid.getNbCol();
        y = rd() % grid.getNbRow();
    }
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


