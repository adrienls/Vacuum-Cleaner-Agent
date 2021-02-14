#include <iostream>
#include "Grid.h"
#include "termcolor/termcolor.hpp"

using std::cout, std::endl;

Grid::Grid(unsigned int nbCol, unsigned int nbRow, Cell initialValue) : nbCol(nbCol), nbRow(nbRow) {
    grid.resize(nbCol);
    for(auto& column : grid){
        column.resize(nbRow);
        for(auto& row: column){
            row = initialValue;
        }
    }
}

void Grid::setAgentPosition(unsigned int x, unsigned int y) {
    this->agentPosition = std::make_pair(x, y);
}

void Grid::display() {
    for (int x = 0; x < 5; x++) {
        for(int y = 0; y < 5; y++){
            if (this->agentPosition.first == x && this->agentPosition.second == y) {
                cout << termcolor::red;
                cout << "A  ";
            }
            else {
                Cell cell = grid[x][y];
                if (cell == empty) {
                    cout << termcolor::reset;
                }
                else if (cell == dust) {
                    cout << termcolor::yellow;
                }
                else if (cell == jewel) {
                    cout << termcolor::blue;
                }
                else if (cell == both) {
                    cout << termcolor::green;
                }
                cout << cell << "  ";
            }
        }
        cout << endl;
    }
}