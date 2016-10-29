#include "cell.h"

Cell Cell::Cell(int x_loc, int y_loc) {
	x = x_loc;
	y = y_loc;
	visited = false; 
}

int Cell::GetLocationX(void) {
	return x; 
}

int Cell::GetLocationY(void) {
	return y; 
}

bool Cell::IsVisited(void) {
	return visited; 
}

void Cell::VisitCell(bool state) {
	visited = state; 
}
