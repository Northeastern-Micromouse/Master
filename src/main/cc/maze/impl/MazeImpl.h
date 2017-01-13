#ifndef CC_MAZE_IMPL_MAZEIMPL_H_
#define CC_MAZE_IMPL_MAZEIMPL_H_

#include "maze/cell/cell.h"
#include "maze/maze.h"
#include <vector>
#include <exception>
#include <iostream>

// Class to represent a maze. A maze is a collections of Cells. 
class MazeImpl : public Maze {
 public:
 	MazeImpl();

 	Cell *operator()(int row, int col) {
    std::cout << "Get the cell in the maze. Row: " << row << " Column: " << col << std::endl;
 		if (row < 0 || col < 0) {
 			throw new std::range_error("Index out of bounds");
 		}
 		return maze_[col + (col * row)];
 	}

	std::vector<Cell *> GetNeighbors(int row, int col);

 private:
 	std::vector<Cell *> maze_;
};

#endif  // CC_MAZE_IMPL_MAZEIMPL_H_
