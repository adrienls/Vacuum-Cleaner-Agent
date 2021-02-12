#pragma once

#include <vector>

class Grid {
private:
	std::vector<int> vector;
	int nb_rows;
	int nb_cols;

public:
	Grid(int nb_rows, int nb_cols);
	Grid(int nb_rows, int nb_cols, int value);
	int get(int row, int col);
	void set(int row, int col, int value);
	void print();
	int getNbRows();
	int getNbCols();
	Grid* copy();
};