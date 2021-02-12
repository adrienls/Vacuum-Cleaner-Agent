#include "Grid.h"
#include <iostream>

Grid::Grid(int nb_rows, int nb_cols) {
	this->nb_rows = nb_rows;
	this->nb_cols = nb_cols;
	for (int k = 0; k <= nb_rows * nb_cols; k++)
		this->vector.push_back(NULL);
}

Grid::Grid(int nb_rows, int nb_cols, int value) {
	this->nb_rows = nb_rows;
	this->nb_cols = nb_cols;
	for (int k = 0; k <= nb_rows * nb_cols; k++)
		this->vector.push_back(value);
}

int Grid::get(int row, int col) {
	long int index = row * this->nb_cols + col;
	return this->vector[index];
}

void Grid::set(int row, int col, int value) {
	long int index = row * this->nb_cols + col;
	this->vector[index] = value;
}

void Grid::print() {
	for (int i = 0; i < this->nb_rows; i++) {
		for (int j = 0; j < this->nb_cols; j++) {
			std::cout << this->get(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

int Grid::getNbCols() {
	return this->nb_cols;
}

int Grid::getNbRows() {
	return this->nb_rows;
}

Grid* Grid::copy() {
	Grid* grid = new Grid(this->getNbRows(), this->getNbCols());
	for (int row = 0; row < this->getNbRows(); row++) {
		for (int col = 0; col < this->getNbCols(); col++) {
			grid->set(row, col, this->get(row, col));
		}
	}
	return grid;
}