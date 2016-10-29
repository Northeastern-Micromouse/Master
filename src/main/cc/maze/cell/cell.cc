#include "cell.h"

Cell::Cell(int x_loc, int y_loc) {
	x = x_loc;
	y = y_loc;
	visited = false; 
}

int Cell::GetLocationX() {
	return x; 
}

int Cell::GetLocationY() {
	return y; 
}

bool Cell::IsVisited() {
	return visited; 
}

void Cell::VisitCell() {
	visited = true; 
}

void Cell::UnvisitCell() {
	visited = false; 
}