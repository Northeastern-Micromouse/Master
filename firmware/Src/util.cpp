#include "util.h"

util::PID::PID(float kp, float ki, float kd):kp_(kp), ki_(ki), kd_(kd) {}

float util::PID::Set(float setpoint) {
    setpoint_ = setpoint;
}

float util::PID::Update(float process, float dt) {
    float error = process - setpoint_;
    integral_ += (error + previous_error_) * dt / 2.0;
    float retval = kp_ * error
                 + ki_ * integral_
                 + kd_ * (error - previous_error_) / dt;
    previous_error_ = error;
    return retval;
}

void util::PID::ResetIntegral() {
    integral_ = 0;
}

float util::HermiteSplinePointDistance(
    float starting_x, 
    float offset,
    float t0,
    float t1) {
        
    // Calculate the distance between two points on the Hermite spline
        /*
    return sqrt((pow(-0.5 * (3 * pow(t0, 2) - 2 * pow(t0, 3)) - 
            starting_x * (1 - 3 * pow(t0, 2) + 2 * pow(t0, 3)) - 
            offset / sqrt(1 + pow(0.5 * (6 * t0 - 6 * pow(t0, 2)) + 
            starting_x * (-6 * t0 + 6 * pow(t0, 2)),
            2)) + 0.5 * (3 * pow(t1, 2) - 2 * pow(t1, 3)) + 
            starting_x * (1 - 3 * pow(t1, 2) + 2 * pow(t1, 3)) + offset /
            sqrt(1 + pow((0.5 * (6 * t1 - 6 * pow(t1, 2)) + 
            starting_x * (-6 * t1 + 6 * pow(t1, 2))),
            2)),
        2) + 
            pow(-t0 - (offset * (-0.5 * (6 * t0 - 6 * pow(t0, 2)) - 
            starting_x * (-6 * t0 + 6 * pow(t0, 2)))) / 
            sqrt(1 + pow((0.5 * (6 * t0 - 6 * pow(t0, 2)) + 
            starting_x * (-6 * t0 + 6 * pow(t0, 2))),
            2)) + t1 + (offset * (-0.5 * (6 * t1 - 6 * pow(t1, 2)) - 
            starting_x * (-6 * t1 + 6 * pow(t1, 2)))) / 
            sqrt(1 + pow(0.5 * (6 * t1 - 6 * pow(t1, 2)) + 
            starting_x * (-6 * t1 + 6 * pow(t1, 2)),
            2)),
        2)));
        */
        return sqrt(pow(-t0 + 3*pow(t0, 2) - 2*pow(t0, 3) + pow(t0, 2)*(-5.4 + 3.6*t0) + 
      (6.*offset*(0.84 + starting_x*(-1. + t0) - 0.84*t0)*t0)/
       sqrt(36.*pow(0.84 + starting_x*(-1. + t0) - 0.84*t0, 2)*pow(t0, 2) + 
         23.040000000000006*pow(0.20833333333333331 + 1.*t0 - 1.*pow(t0, 2), 2))\
       + t1 - 3*pow(t1, 2) + (5.4 - 3.6*t1)*pow(t1, 2) + 2*pow(t1, 3) - 
      (6.*offset*(0.84 + starting_x*(-1. + t1) - 0.84*t1)*t1)/
       sqrt(36.*pow(0.84 + starting_x*(-1. + t1) - 0.84*t1, 2)*pow(t1, 2) + 
         23.040000000000006*pow(0.20833333333333331 + 1.*t1 - 1.*pow(t1, 2), 2)),
            2) + pow(pow(t0, 2)*(-2.52 + 1.68*t0) - 
             starting_x*pow(-1 + t0, 2)*(1 + 2*t0) + 
             (4.800000000000001*offset*(-0.20833333333333331 - 1.*t0 + 1.*pow(t0, 2)))/
              sqrt(36.*pow(0.84 + starting_x*(-1. + t0) - 0.84*t0, 2)*pow(t0, 2) + 
                23.040000000000006*pow(0.20833333333333331 + 1.*t0 - 1.*pow(t0, 2), 2))\
         + (2.52 - 1.68*t1)*pow(t1, 2) + starting_x*pow(-1 + t1, 2)*(1 + 2*t1) - 
   (4.800000000000001*offset*(-0.20833333333333331 - 1.*t1 + 1.*pow(t1, 2)))/
    sqrt(36.*pow(0.84 + starting_x*(-1. + t1) - 0.84*t1, 2)*pow(t1, 2) + 
      23.040000000000006*pow(0.20833333333333331 + 1.*t1 - 1.*pow(t1, 2), 2)),
            2));
}

float util::HermiteSplineArcLength(
    float starting_x,
    float offset,
    float t0,
    float t1,
    int segments) {
        
    // Normally, the equation for the Hermite Spline can be quite long, but 
    // here we will simplify the equation by utilizing the fact that the
    // tangent at both points will be (0,1), the final point will always be
    // (0.5, 1), and the y-coordinate of the starting point is always 0.
    // We will take the offset of this curve (using 0 to represent the regular
    // curve) and calculate the arc length between t0 and t1.
        
    // Begin by first dividing the spline segment into a number of its own
    // discrete segments
    float arc_step = (t1 - t0) / segments;                           

                // Now sum the length of each arc segment
    float length = 0;
    for (int i = 0; i < segments; i++) {
        length += 
            HermiteSplinePointDistance(starting_x, offset, t0 + i*arc_step, t0 + (i + 1)*arc_step);
    }
        
    return length;
}
    
float util::DeltaAngle(float current, float target) {
    if (fabs(target - current) > 180) {
        return (360 - fabs(target - current))*
                    (target - current > 0 ? 1 : -1);
    }
    return target - current;
}

