#include <queue>
#include <iostream>
#include <src/main/c/com/micromouse/maze/cell.h>
#include "src/main/cc/maze/impl/MazeImpl.h"
#include "RobotImpl.h"
#include "src/main/cc/util/logger.h"

namespace robot {
namespace impl {
namespace {
  util::logger log = util::logger(false, std::cout);
}

using maze::cell::Cell;
using util::location::Location;

RobotImpl::RobotImpl() : enable_debugging_(false) {
  // No op.
}

RobotImpl::RobotImpl(bool enable_debugging) : enable_debugging_(enable_debugging) {
  log.should_log(true);
}

void RobotImpl::StartExploration() {
  log.log("--------------- Start Exploration ---------------");
  // Make sure the robot starts out at the beginning.
  if (curr_loc_.x() != 0 && curr_loc_.y() != 0) {
    ReturnToStart();
  }
  maze_.clear_maze();
  Cell* curr_cell;
  std::vector<Cell*> neighbors;
  Cell::RelativeDirection prev_move = Cell::RelativeDirection::NONE;

  // Visit the first cell.
  VisitCurrentCell();

  while (!stack_.empty()) {
    curr_cell = stack_.top();
    stack_.pop();
    if (!curr_cell->isVisited()) {
      prev_move = GetDirection(curr_cell);
      // Move the robot to the cell.
      Move(prev_move);
      // Visit the cell.
      if (!VisitCurrentCell()) {
        GoBack(prev_move);
      }
    }
  }
}

void RobotImpl::GoToGoal() {
  // TODO(matt): Implement
}

void RobotImpl::ComputeFastestPath() {
  Cell* itr;
  std::queue<maze::cell::Cell *> queue;
  std::vector<maze::cell::Cell*> neighbors = maze_.GetNeighbors(0,0);
  curr_loc_.update(0,0);
  maze_.clear_maze();
  maze_.operator()(0,0)->VisitCell();

  for (Cell* cell : neighbors) {
    cell->setParent(0, 0);
    cell->VisitCell();
    queue.push(cell);
  }

  while (!queue.empty()) {
    itr = queue.front();
    queue.pop();
    if (itr->x() == 8 && itr->y() == 8) {
      break;
    }
    neighbors = maze_.GetNeighbors(itr->x(), itr->y());
    for (maze::cell::Cell* cell : neighbors) {
      if (!cell->isVisited()) {
        cell->setParent(itr->x(), itr->y());
        cell->VisitCell();
        queue.push(cell);
      }
    }
    curr_loc_.update(itr->x(),itr->y());
  }

  curr_loc_.update(8,8);
  util::location::Location temp(0,0);
  while (curr_loc_.x() != 0 || curr_loc_.y() != 0) {
    log.log("At location X: " + std::to_string(curr_loc_.x()) + " Y: " + std::to_string(curr_loc_.y()));
    temp = maze_.operator()(curr_loc_.x(), curr_loc_.y())->getParent();
    log.log("Moving to X: " + std::to_string(temp.x()) + " Y: " + std::to_string(temp.y()));
    curr_loc_.update(temp.x(), temp.y());
  }
}

void RobotImpl::ReturnToStart() {
  // TODO(matt): Implement
  log.log("--------------- Return To Start ---------------");
}

void RobotImpl::GoBack(Cell::RelativeDirection dir) {
  switch (dir) {
    case Cell::RelativeDirection::NORTH:
      Move(Cell::RelativeDirection::SOUTH);
      break;
    case Cell::RelativeDirection::SOUTH:
      Move(Cell::RelativeDirection::NORTH);
      break;
    case Cell::RelativeDirection::EAST:
      Move(Cell::RelativeDirection::WEST);
      break;
    case Cell::RelativeDirection::WEST:
      Move(Cell::RelativeDirection::EAST);
      break;
    default:
      break;
  }
}

std::vector<Cell*> RobotImpl::GetNeighbors() {
  return maze_.GetNeighbors(curr_loc_.x(), curr_loc_.y());
}

bool RobotImpl::VisitCurrentCell() {
  Cell* curr_cell = maze_(curr_loc_.x(), curr_loc_.y());
  bool should_move_forward = false;
  if (!curr_cell->isVisited()) {
    log.log("--------------- Visit A Cell ---------------");
    log.log("X: " + std::to_string(curr_cell->x()));
    log.log("Y: " + std::to_string(curr_cell->y()));
    log.log("--------------------------------------------");
    curr_cell->VisitCell();
    for (Cell* neighbor : GetNeighbors()) {
      if (!neighbor->isVisited()) {
        should_move_forward = true;
        stack_.push(neighbor);
      }
    }
  }
  return should_move_forward;
}

void RobotImpl::Move(Cell::RelativeDirection dir) {
  switch (dir) {
    case Cell::RelativeDirection::NORTH:
      // TODO(matt): Actually move forward
      log.log("--------------- Move from Cell ---------------");
      log.log("X: " + std::to_string(curr_loc_.x()));
      log.log("Y: " + std::to_string(curr_loc_.y()));
      log.log("----------------------------------------------");
      curr_loc_.update(curr_loc_.x(), curr_loc_.y() + 1);
      log.log("--------------- to Cell ---------------");
      log.log("X: " + std::to_string(curr_loc_.x()));
      log.log("Y: " + std::to_string(curr_loc_.y()));
      log.log("----------------------------------------------");
      break;
    case Cell::RelativeDirection::SOUTH:
      // TODO(matt): Actually move backward
      log.log("--------------- Move from Cell ---------------");
      log.log("X: " + std::to_string(curr_loc_.x()));
      log.log("Y: " + std::to_string(curr_loc_.y()));
      log.log("----------------------------------------------");
      curr_loc_.update(curr_loc_.x(), curr_loc_.y() - 1);
      log.log("--------------- to Cell ---------------");
      log.log("X: " + std::to_string(curr_loc_.x()));
      log.log("Y: " + std::to_string(curr_loc_.y()));
      log.log("----------------------------------------------");
      break;
    case Cell::RelativeDirection::EAST:
      // TODO(matt): Actually move left
      log.log("--------------- Move from Cell ---------------");
      log.log("X: " + std::to_string(curr_loc_.x()));
      log.log("Y: " + std::to_string(curr_loc_.y()));
      log.log("----------------------------------------------");
      curr_loc_.update(curr_loc_.x() + 1, curr_loc_.y());
      log.log("--------------- to Cell ---------------");
      log.log("X: " + std::to_string(curr_loc_.x()));
      log.log("Y: " + std::to_string(curr_loc_.y()));
      log.log("----------------------------------------------");
      break;
    case Cell::RelativeDirection::WEST:
      // TODO(matt): Actually move right
      log.log("--------------- Move from Cell ---------------");
      log.log("X: " + std::to_string(curr_loc_.x()));
      log.log("Y: " + std::to_string(curr_loc_.y()));
      log.log("----------------------------------------------");
      curr_loc_.update(curr_loc_.x() - 1, curr_loc_.y());
      log.log("--------------- to Cell ---------------");
      log.log("X: " + std::to_string(curr_loc_.x()));
      log.log("Y: " + std::to_string(curr_loc_.y()));
      log.log("----------------------------------------------");
      break;
    default:
      break;
  }
}

Cell::RelativeDirection RobotImpl::GetDirection(Cell* cell) {
  int x = cell->x();
  int y = cell->y();
  if (x == curr_loc_.x() && y == curr_loc_.y() + 1) {
    return Cell::RelativeDirection::NORTH;
  }
  if (x == curr_loc_.x() && y == curr_loc_.y() - 1) {
    return Cell::RelativeDirection::SOUTH;
  }
  if (x == curr_loc_.x() + 1 && y == curr_loc_.y()) {
    return Cell::RelativeDirection::EAST;
  }
  if (x == curr_loc_.x() - 1 && y == curr_loc_.y()) {
    return Cell::RelativeDirection::WEST;
  }
  // TODO(matt): Implement error checking
  return Cell::RelativeDirection::NONE;
}

std::string RobotImpl::print() {
  // TODO(matt): Implement
  return "";
}

}  // impl
}  // robot
