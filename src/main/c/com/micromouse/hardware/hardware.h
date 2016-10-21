#ifndef MICROMOUSE_HARDWARE_HARDWARE_H_
#define MICROMOUSE_HARDWARE_HARDWARE_H_

#include "src/main/c/com/micromouse/utility/moves/move.h"
#include <stdio.h>

typedef enum SensorResult {
	VALID,
	INVALID
} SR;

SR * PollSensors();

// Moves the robot in the given direction. Makes the calls down to the 
// hardware.
void Move(move_t * move);

// Moves the robot right. Right is relative to where the robot was first placed
// in the maze.
void MoveRight();

// Moves the robot left. Left is relative to where the robot was first placed
// in the maze.
void MoveLeft();

// Moves the robot forward. Forward is relative to where the robot was first
// placed in the maze.
void MoveForward();

// Moves the robot backwards. Backwards is relative to where the robot was 
// first placed in the maze.
void MoveBackward();

#endif  // MICROMOUSE_HARDWARE_HARDWARE_H_