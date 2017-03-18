#include <iostream>
#include <src/main/cc/util/Location.h>
#include "cell.h"

namespace maze {
namespace cell {

using util::location::Location;

Cell::Cell(int x, int y) {
  x_loc_ = x;
  y_loc_ = y;
  visited_ = false;
}

Cell::Cell() : Cell(0,0) {
  // No op.
}

void Cell::setParent(int x, int y) {
  parent_.update(x,y);
}

int Cell::x() {
  return x_loc_;
}

int Cell::y() {
  return y_loc_;
}

bool Cell::isVisited() {
  return visited_;
}

void Cell::VisitCell() {
  visited_ = true;
  // For now just return all the directions.
  // TODO(matt): Query the seneors here.
  neighbors_.push_back(RelativeDirection::NORTH);
  neighbors_.push_back(RelativeDirection::SOUTH);
  neighbors_.push_back(RelativeDirection::EAST);
  neighbors_.push_back(RelativeDirection::WEST);
}

void Cell::UnVisitCell() {
  visited_ = false;
  neighbors_.clear();
}

std::vector<Cell::RelativeDirection> Cell::GetNeighbors() {
  return neighbors_;
}

void Cell::print() {
  std::cout << "--------------------" << std::endl;
  std::cout << "| Cell: " << x_loc_ << ", " << y_loc_ << "       |" << std::endl;
  std::cout << "| Visited: " << (visited_ ? "True " : "False") << "   |" << std::endl;
  for (RelativeDirection neighbor : neighbors_) {
    switch (neighbor) {
      case NORTH:
        std::cout << "| Neighbor: North  |" << std::endl;
        break;
      case EAST:
        std::cout << "| Neighbor: South  |" << std::endl;
        break;
      case WEST:
        std::cout << "| Neighbor: East   |" << std::endl;
        break;
      case SOUTH:
        std::cout << "| Neighbor: West   |" << std::endl;
        break;
      case NONE:
        std::cout << "| Neighbor: None    |" << std::endl;
        break;
      default:
        std::cout << "| Neighbor: Unknown    |" << std::endl;
        break;
    }
  }
  std::cout << "--------------------" << std::endl;
}

}  // cell
}  // maze
