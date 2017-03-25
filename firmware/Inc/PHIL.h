/**
 * PHIL.h
 * Declares the PHysical Interface Layer of the Micromouse firmware
 */

#ifndef PHIL_H
#ifdef __cplusplus
#define PHIL_H

#include "PAL.h"

namespace MMPHIL
{
	class Motor
	{
	private:
		MMPAL::GPIO a, b;
		MMPAL::TIM tick;
	public:
		Motor(MMPAL::GPIO& a, MMPAL::GPIO& b, MMPAL::TIM& tick);
	};
	
	class Reflectance
	{
		
	};
	
	class Distance
	{
		
	};
	
	class IMU
	{
		
	};
	
}

#endif

#endif
