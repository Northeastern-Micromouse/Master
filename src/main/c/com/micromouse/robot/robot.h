#ifndef MICROMOUSE_ROBOT_ROBOT_H_
#define MICROMOUSE_ROBOT_ROBOT_H_

#include "src/main/c/com/micromouse/hardware/hardware.h"
#include "src/main/c/com/micromouse/location/location.h"
#include "src/main/c/com/micromouse/utility/direction/direction.h"
#include "src/main/c/com/micromouse/utility/list/list.h"
#include "src/main/c/com/micromouse/maze/cell.h"

typedef struct Robot {
	Location *location_;
	Cell *maze_[16][16];
} Robot;

// Returns a robot location at the given location.
Robot* InitializeRobot(Location* location);

void CanMove(Robot* winslow, Move move);

<<<<<<< HEAD
void NaiveStrategy(Robot* winslow, Move* possibleMoves, int size, List** queue);
=======
void NaiveStrategy(Robot* winslow, Move* possibleMoves, int size, List **queue);
>>>>>>> c1582542f7e1666506c238adcca68c76f1f2acc1

void AddMove(Robot* winslow, Move move, List** queue);

// Frees all of the memory associated with the given robot.
void RobotDestructor(Robot* winslow);
<<<<<<< HEAD
=======

void MoveRobot(Robot*, direction_t);

direction_t DetermineDirection(Robot*, Cell*);
>>>>>>> c1582542f7e1666506c238adcca68c76f1f2acc1

// Explores the maze.
void ExploreMaze(Robot* winslow);

<<<<<<< HEAD
// Updates the maze in the robot with the sensor information.
void UpdateMaze(Robot* winslow, Move* values, int size);

// Solves the maze once the robot has explored it, returns the goal Cell
Cell* SolveMaze(Robot* winslow, Location *goal);

// Checks neighbors of the cell and does stuff
List* VisitNeighbor(Cell* current_cell, int x, int y, Robot* winslow, List* queue);
=======
// Updates the maze in the robot with the sensor information/
void UpdateMaze(Robot* winslow, Move* values, int size);
>>>>>>> c1582542f7e1666506c238adcca68c76f1f2acc1

#endif  // MICROMOUSE_ROBOT_ROBOT_H_
