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
PIDController::PIDController() {
    /**
     * @todo Implement the default constructor: initialize default kp, ki, kd, window_size
     * 
     */
}

/**
 * @brief Explicit Constructor to initialize the controller gains
 * 
 * @param  kp Proportional gain
 * @param  ki Integral gain
 * @param  kd Derivative gain
 */
PIDController::PIDController(double kp, double ki, double kd) {
    /**
     * @todo initialize default kp, ki, kd using the arguments
     * 
     */
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
    /**
     * @todo Using ref vel and actual vel, compute current error.
     * Check the length of error array. If length == 0, the there wont be any derivative or integral terms. 
     * Set them to zero. If length >= 1, compute derivative and integral using dt as 1.
     * error = ref_vel - actual_vel
     * der_err = current error - past error / dt
     * int_err = sum(error_array) / size of array * dt
     * control_output  = kp *  error + ki * int_err + kd * der_err
     * output = actual_vel + control_output
     */
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
void PIDController::setGains(double kp, double ki, double kd) {
    /**
     * @todo Set kp, ki, kd using the arguments
     * 
     */
}

vector<double> PIDController::getGains() {
    /**
     * @todo Return values of kp, ki, kd in form of vector
     * 
     */
    return {0, 0, 0};
}
/**
 * @brief A function to set window size for integral term
 * 
 * @param window_size Size of window for integral term
 */
void PIDController::setWindowSize(int window_size) {
    /**
     * @todo Set window size param using the argument
     * 
     */
}
/**
 * @brief A function to return size of the window used to calculate the integral term
 * 
 * @return int 
 */
int PIDController::getWindowSize() {
    /**
     * @todo return the window size param
     * 
     */
    return 0;
}
