#include <iostream>
#include "cell.h"

Cell::Cell(int x, int y) {
	x_loc_ = x;
	y_loc_ = y;
	visited = false;
}

Cell::Cell() {
	Cell(0,0);
}

int Cell::x() {
	return x_loc_;
}

int Cell::y() {
	return y_loc_; 
}

bool Cell::isVisited() {
	return visited; 
}

void Cell::VisitCell() {
  std::cout << "Visit cell -_- X: " << x_loc_ << " Y: " << y_loc_ << std::endl;
	visited = true;
  // For now just return all the directions.
  // TODO(matt): Query the seneors here.
  neighbors.push_back(RelativeDirection::FORWARD);
  neighbors.push_back(RelativeDirection::BACKWARD);
  neighbors.push_back(RelativeDirection::LEFT);
  neighbors.push_back(RelativeDirection::RIGHT);
}

void Cell::UnVisitCell() {
	visited = false;
  neighbors.clear();
}

std::vector<Cell::RelativeDirection> Cell::GetNeighbors() {
  return neighbors;
}

std::string Cell::print() {
  // TODO(matt): Implement
}
