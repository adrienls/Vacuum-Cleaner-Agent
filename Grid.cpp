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

void Grid::display() {
    for (const auto& column : grid){
        for(const auto& row : column){
            if (row == empty){
                cout << termcolor::reset;
            }
            else if (row == dust){
                cout << termcolor::yellow;
            }
            else if (row == jewel){
                cout << termcolor::blue;
            }
            else if (row == both){
                cout << termcolor::green;
            }
            cout << row << "  ";
        }
        cout << endl;
    }
}