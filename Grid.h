#ifndef VACUUM_CLEANER_AGENT_GRID_H
#define VACUUM_CLEANER_AGENT_GRID_H

#include <vector>
using std::vector;
enum Cell {empty, dust, jewel, both};

class Grid {
private:
    unsigned int nbCol;
    unsigned int nbRow;
    vector<vector<Cell>> grid;
public:
    Grid(unsigned int nbCol, unsigned int nbRow, Cell initialValue = Cell::empty);
    virtual ~Grid() = default;

    unsigned int getNbCol() const {
        return nbCol;
    }
    unsigned int getNbRow() const {
        return nbRow;
    }

    Cell getCell(unsigned int column, unsigned int row){
        return grid[column][row];
    }
    void setCell(unsigned int column, unsigned int row, Cell value){
        grid[column][row] = value;
    }
    void display();
};


#endif //VACUUM_CLEANER_AGENT_GRID_H
