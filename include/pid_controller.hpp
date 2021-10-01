/**
 * @file pid_controller.hpp
 * @author Sakshi Kakde, Hrushikesh Budhale
 * @brief Header file for PIDController class
 * @version 0.1
 * @date 2021-09-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef INCLUDE_PID_CONTROLLER_HPP_
#define INCLUDE_PID_CONTROLLER_HPP_

#include <vector>

using std::vector;
/**
 * @brief A class to implement PID controller for velocity.
 * 
 */
class PIDController {
 public:
    PIDController();
    PIDController(double kp, double ki, double kd);
    ~PIDController();
    double computeOutput(double ref_vel, double actual_vel);
    double setGains(double kp, double ki, double kd);
    vector<double> getGains();
 private:
    int window_size = 10;  // window size for integral
    double kp;  // Proportional gain
    double ki;  // Integral gain
    double kd;  // Derivative gain
    vector<double> error_array;
};

#endif  // INCLUDE_PID_CONTROLLER_HPP_
