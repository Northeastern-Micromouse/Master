/**
 * AL.cpp
 * Defines the Algorithm Layer of the Micromouse firmware.
 */
#include "AL.h"

MMAL::Robot::Robot(MMPHIL::Motor& left, MMPHIL::Motor& right)
// Default robot constructor, initializes hardware handles
{
	// TODO
}

void MMAL::Robot::drive(int nCells, float velocity, 
							MMAL::Robot::DriveMethod method)
{
	switch (method)
	{
		case MMAL::Robot::DriveMethod::SIMPLE:
			simpleDrive(velocity);
			break;
		case MMAL::Robot::DriveMethod::DIRECTED:
			directedDrive(velocity);
			break;
		case MMAL::Robot::DriveMethod::DISCRETESPLINE:
			discreteSplineDrive(velocity);
			break;
		case MMAL::Robot::DriveMethod::CONTINUOUSSPLINE:
			continuousSplineDrive(velocity);
			break;
	}
}

void MMAL::Robot::simpleDrive(float velocity)
{
	
}

void MMAL::Robot::directedDrive(float velocity)
{
	
}

void MMAL::Robot::discreteSplineDrive(float velocity)
{
	
}

void MMAL::Robot::continuousSplineDrive(float velocity)
{
	
}
