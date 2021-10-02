/**
 * @file main.cpp
 * @author Sakshi Kakde, Hrushikesh Budhale
 * @brief Main file
 * @version 0.1
 * @date 2021-09-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
#include<vector>
#include <memory>
#include <pid_controller.hpp>

int main() {
    std::unique_ptr<PIDController> pid(new PIDController());
    const double kp = 0.4;
    const double ki = 0.01;
    const double kd = 0.2;
    const double ref_vel = 20.0;
    const double actual_vel = 15.0;
    pid->setGains(kp, ki, kd);
    pid->setWindowSize(5);
    double computed_output;
    for (int i = 0; i< 15; i++)
      computed_output = pid->computeOutput(ref_vel, computed_output);
    std::cout << "Coumputed output is : " << computed_output << std::endl;
    return 0;
}
