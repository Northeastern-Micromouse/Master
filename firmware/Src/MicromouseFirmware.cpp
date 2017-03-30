#include <stm32l4xx_hal.h>

#ifdef __cplusplus
extern "C" {
    #include "main.h"
}
#endif

#include <functional>
    
#include "stm32l4xx_hal.h"
#include "GPIO.h"
#include "TIM.h"
#include "Motor.h"
#include "Robot.h"

int main(void) {
    
    CMain();
    
    pal::Gpio leftMotorStep = 
        pal::Gpio(S_MOTOR_A_STEP_GPIO_Port, S_MOTOR_A_STEP_Pin);
    
    pal::Gpio leftMotorDir = 
        pal::Gpio(S_MOTOR_A_DIR_GPIO_Port, S_MOTOR_A_DIR_Pin);
    
    pal::Tim leftMotorTick = pal::Tim(getTIM1Handle());
    
    phil::Motor leftMotor = 
        phil::Motor(leftMotorStep, leftMotorDir, leftMotorTick);
    
    pal::Gpio rightMotorStep = 
        pal::Gpio(S_MOTOR_B_STEP_GPIO_Port, S_MOTOR_B_STEP_Pin);
    
    pal::Gpio rightMotorDir = 
        pal::Gpio(S_MOTOR_B_DIR_GPIO_Port, S_MOTOR_B_DIR_Pin);
    
    pal::Tim rightMotorTick = pal::Tim(getTIM2Handle());
    
    phil::Motor rightMotor = 
        phil::Motor(rightMotorStep, rightMotorDir, rightMotorTick);
    
    //pal::Gpio led = pal::Gpio(DC_M1_IN1_GPIO_Port, DC_M1_IN1_Pin);
    //pal::Tim timer = pal::Tim(TIM2);
    //leftMotorTick.SetTiming(40000, 500);
    //leftMotorTick.SetISR(std::bind<void>(&phil::Motor::Step, leftMotor));
    //leftMotorTick.Enable();
    
    //al::Robot micromouse = al::Robot(leftMotor, rightMotor);
    
    //leftMotor.SetAngularVelocity(M_PI/4, 2.0 * M_PI / 200.0);
    //leftMotor.SetMotion(true);
    
    rightMotor.SetDirection(phil::Motor::Direction::CW);
    
    while (1) {
        //HAL_Delay(3000);
        //micromouse.Drive(1, 2*M_PI, al::Robot::DriveMethod::SIMPLE);
        HAL_Delay(1000);
        leftMotor.Step();
        //rightMotor.Step();
    }
        
}
