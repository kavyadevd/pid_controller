/**
 * @file pid_controller.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * 
 * 
 * @date 2021-09-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<pid_controller.hpp>

/**
 * @brief Default constructor
 * 
 */
PIDController::PIDController() {}

/**
 * @brief Explicit Constructor to initialize the controller gains
 * 
 * @param  kp Proportional gain
 * @param  ki Integral gain
 * @param  kd Derivative gain
 */
PIDController::PIDController(double kp, double ki, double kd) {
}

/**
 * @brief Default Destructor
 * 
 */
PIDController::~PIDController() {
}

/**
 * @brief Computes the controller output using reference velocity and actual velocity. 
 * 
 * @param ref_vel Reference velocity
 * @param actual_vel Actual velocity
 * @return double 
 */
double PIDController::computeOutput(double ref_vel, double actual_vel) {
    return 0;
}
/**
 * @brief Set the gains for the controller
 * 
 * @param kp Proportional gain 
 * @param ki Integral gain 
 * @param kd Derivative gain 
 * @return double 
 */
double PIDController::setGains(double kp, double ki, double kd) {
    return 0;
}

vector<double> PIDController::getGains() {
    double kp = 0;
    double ki = 0;
    double kd = 0;
    return {kp, ki, kd};
}
