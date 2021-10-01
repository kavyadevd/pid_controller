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
    void setGains(double kp, double ki, double kd);
    vector<double> getGains();
    void setWindowSize(int window_size);
    int getWindowSize();
 private:
    int window_size;  // window size for integral
    double kp;  // Proportional gain
    double ki;  // Integral gain
    double kd;  // Derivative gain
    vector<double> error_array;  // Array to store past errors for integral
    // and derivative terms
};

#endif  // INCLUDE_PID_CONTROLLER_HPP_
