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
   /**
    * @brief Default constructor
    * 
    */
    PIDController();
    /**
    * @brief Explicit Constructor to initialize the controller gains
    * 
    * @param  kp Proportional gain
    * @param  ki Integral gain
    * @param  kd Derivative gain
    */
    PIDController(double kp, double ki, double kd);
    /**
    * @brief Default Destructor
    * 
    */
    ~PIDController();
    /**
    * @brief Computes the controller output using reference velocity and actual velocity. 
    * 
    * @param ref_vel Reference velocity
    * @param actual_vel Actual velocity
    * @return double 
    */
    double computeOutput(double ref_vel, double actual_vel);
    /**
    * @brief Set the gains for the controller
    * 
    * @param kp Proportional gain 
    * @param ki Integral gain 
    * @param kd Derivative gain 
    * @return double 
    */
    void setGains(double kp, double ki, double kd);
    /**
    * @brief A function to retrun the kp, ki, kd values
    * 
    * @return vector<double> 
    */
    vector<double> getGains();
    /**
    * @brief A function to set window size for integral term
    * 
    * @param window_size Size of window for integral term
    */
    void setWindowSize(int window_size);
    /**
    * @brief A function to return size of the window used to calculate the integral term
    * 
    * @return int 
    */
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
