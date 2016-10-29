#ifndef CC_CELL_CELL_H_
#define CC_CELL_CELL_H_

// Abstract class to represent a cell.
public class Cell {
public:
	// Creates a Cell object at (x,y)
	Cell(int x, int y);

	// Destructor 
	~Cell(int x, int y);

	// Gets the x offsest of a Cell
	int getLocationX();

	// Gets the y offset of a Cell
	int getLocationY();

	// Gets the status of whether a Cell has been visited
	bool isVisited();


private:
	int x;
	int y; 
	bool visited; 

	 	
};

#endif  // CC_CELL_CELL_H_