/**
 * @file unittest_PIDControllerParam.cpp
 * @author Sakshi Kakde, Hrushikesh Badhale
 * @brief 
 * @version 0.1
 * @date 2021-09-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <pid_controller.hpp>
/**
 * @brief Unit test for defaut parameters
 * 
 */
TEST(PIDControllerTest, testPIDControllerDefaltParam) {
  std::unique_ptr<PIDController> pid(new PIDController());
  const vector<double> expected_value = {1.0, 1.0, 1.0};
  EXPECT_EQ(pid->getGains(), expected_value);
}
/**
 * @brief Unit test for user defined parameters
 * 
 */
TEST(PIDControllerTest, testPIDControllerCustomParam) {
  std::unique_ptr<PIDController> pid(new PIDController());
  const double Kp = 2.0;
  const double Ki = 2.0;
  const double Kd = 2.0;
  const vector<double> expected_value = {Kp, Ki, Kd};
  pid->setGains(Kp, Ki, Kd);
  EXPECT_EQ(pid->getGains(), expected_value);
}
/**
 * @brief Unit test for window size parameter
 * 
 */
TEST(PIDControllerTest, testPIDControllerWindowSizeParam) {
  std::unique_ptr<PIDController> pid(new PIDController());
  const int expected_value = 5;
  pid->setWindowSize(5);
  EXPECT_EQ(pid->getWindowSize(), expected_value);
}
/**
 * @brief test Proportional component
 * 
 */
TEST(PIDControllerTest, testPIDControllerP) {
  std::unique_ptr<PIDController> pid(new PIDController());
  const double kp = 0.5;
  const double ki = 0.0;
  const double kd = 0.0;
  const double ref_vel = 10.0;
  const double actual_vel = 5.0;
  const double expected_output = 7.5;
  pid->setGains(kp, ki, kd);
  double computed_output = pid->computeOutput(ref_vel, actual_vel);
  EXPECT_NEAR(computed_output, expected_output, 0.1);
}
/**
 * @brief test Proportional and Derivative component
 * 
 */
TEST(PIDControllerTest, testPIDControllerPD) {
  std::unique_ptr<PIDController> pid(new PIDController());
  const double kp = 0.5;
  const double ki = 0.0;
  const double kd = 0.02;
  const double ref_vel = 12.0;
  const double actual_vel = 5.0;
  const double expected_output = 10.2;  // Expected output after 2 iterations
  pid->setGains(kp, ki, kd);
  double computed_output = pid->computeOutput(ref_vel, actual_vel);
  computed_output = pid->computeOutput(ref_vel, computed_output);
  EXPECT_NEAR(computed_output, expected_output, 0.1);
}
/**
 * @brief test Proportional and Integral component
 * 
 */
TEST(PIDControllerTest, testPIDControllerPI) {
  std::unique_ptr<PIDController> pid(new PIDController());
  const double kp = 0.5;
  const double ki = 0.05;
  const double kd = 0.0;
  const double ref_vel = 12.0;
  const double actual_vel = 5.0;
  const double expected_output = 11.6;  // Expected output after 3 iterations
  pid->setGains(kp, ki, kd);
  double computed_output = pid->computeOutput(ref_vel, actual_vel);
  computed_output = pid->computeOutput(ref_vel, computed_output);
  computed_output = pid->computeOutput(ref_vel, computed_output);
  EXPECT_NEAR(computed_output, expected_output, 0.1);
}
/**
 * @brief test to verify convergence
 * 
 */
TEST(PIDControllerTest, testPIDControllerPID) {
  std::unique_ptr<PIDController> pid(new PIDController());
  const double kp = 1.0;
  const double ki = 0.05;
  const double kd = 0.02;
  const double ref_vel = 12.0;
  const double actual_vel = 5.0;
  const double expected_output = ref_vel;  // output after 15 iterations
  pid->setGains(kp, ki, kd);
  double computed_output = actual_vel;
  for (int i = 0; i< 15; i++)
    computed_output = pid->computeOutput(ref_vel, computed_output);
  EXPECT_NEAR(computed_output, expected_output, 0.01);
}
