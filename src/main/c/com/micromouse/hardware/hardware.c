#include "hardware.h"

SR * PollSensors() {
	// TODO: Implement
	return 0;
}

void Move(move_t * move) {
	switch (*move) {
		case FORWARD:
			MoveForward();
			break;
		case BACKWARD:
			MoveBackward();
			break;
		case RIGHT:
			MoveRight();
			break;
		case LEFT:
			MoveLeft();
			break;
		default:
			printf("Invalid move. Unable to move the robot\n");
			break;
	}
}

void MoveRight() {
	// TODO: Implement
}

void MoveLeft() {
	// TODO: Implement
}

void MoveForward() {
	// TODO: Implement
}

void MoveBackward() {
	// TODO: Implemenet
}