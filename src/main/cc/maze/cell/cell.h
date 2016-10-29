#ifndef CC_CELL_CELL_H_
#define CC_CELL_CELL_H_

// Abstract class to represent a cell.
class Cell {
	// Creates a Cell object at (x,y)
	Cell(int x, int y);

	// Gets the x offsest of a Cell
	int GetLocationX();

	// Gets the y offset of a Cell
	int GetLocationY();

	// Gets the status of whether a Cell has been visited
	bool IsVisited();

	// Sets a Cell to visited (true)
	void VisitCell();

	// Sets a Cell to unvisited (false) 
	void unVisitCell();

private:
	int x;
	int y; 
	bool visited; 
};

#endif  // CC_CELL_CELL_H_