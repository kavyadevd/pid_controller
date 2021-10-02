/**
 * @file pid_controller.cpp
 * @author Sakshi Kakde, Hrushikesh Budhale
 * @brief Source file for PIDController class
 * @version 0.1
 * 
 * 
 * @date 2021-09-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<math.h>
#include<iostream>
#include <numeric>
#include<pid_controller.hpp>

/**
 * @brief Default constructor
 * 
 */
PIDController::PIDController() {
    kp = 1.0;
    ki = 1.0;
    kd = 1.0;
    window_size = 5;
}

/**
 * @brief Explicit Constructor to initialize the controller gains
 * 
 * @param  kp Proportional gain
 * @param  ki Integral gain
 * @param  kd Derivative gain
 */
PIDController::PIDController(double kp, double ki, double kd) {
    PIDController::kp = kp;
    PIDController::ki = ki;
    PIDController::kd = kd;
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
    double error;
    double  der_err = 0.0;
    double int_err = 0.0;
    if ( error_array.empty() ) {    // Edge case
        error = ref_vel - actual_vel;
        der_err = 0.0;
        int_err = 0.0;
    } else {
        error = ref_vel - actual_vel;
        der_err = (error - error_array[error_array.size()-1])/ 1;
<<<<<<< HEAD
        // calculate sum for integral error
=======
>>>>>>> fea07df2a05a4f8de6fa3f2ecc4a961023662316
        double sum = std::accumulate(error_array.begin(), error_array.end(), 0.0);
        int_err = (sum)/ error_array.size();
    }
    double  control_output  = kp *  error + ki * int_err + kd * der_err;
    double  output = actual_vel + control_output;
<<<<<<< HEAD
    if ( error_array.size() >= window_size )  // Restrict error array to defined window size
=======
    if ( error_array.size() >= window_size )
>>>>>>> fea07df2a05a4f8de6fa3f2ecc4a961023662316
        error_array.erase(error_array.begin());
    error_array.push_back(error);
    return (round(output*100.0)/100.0);   // Return last error
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
    PIDController::kp = kp;
    PIDController::ki = ki;
    PIDController::kd = kd;
}
/**
 * @brief A function to retrun the kp, ki, kd values
 * 
 * @return vector<double> 
 */
vector<double> PIDController::getGains() {
    return {kp, ki, kd};
}
/**
 * @brief A function to set window size for integral term
 * 
 * @param window_size Size of window for integral term
 */
void PIDController::setWindowSize(int window_size) {
    PIDController::window_size = window_size;
}
/**
 * @brief A function to return size of the window used to calculate the integral term
 * 
 * @return int 
 */
int PIDController::getWindowSize() {
    return window_size;
}
