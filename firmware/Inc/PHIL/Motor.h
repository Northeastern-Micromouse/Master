#ifndef MOTOR_H
#define MOTOR_H

#include "GPIO.h"
#include "TIM.h"

#define TICK_PRESCALER 80

namespace phil
{

	class Motor
	{
	private:
		pal::Gpio step_, dir_;
		pal::Tim tick_;
		int steps_;
    	
	public:
    	enum class Direction {
    	    CW, CCW
    	};
    	
		Motor(pal::Gpio& step, pal::Gpio& dir, pal::Tim& tick);
		int GetSteps() const;
    	void SetDirection(Direction d);
    	void Step();
		void ResetSteps();
    	
    	void SetAngularVelocity(float w, float radPerStep);
    	void SetMotion(bool on);
	};
	
}

#endif