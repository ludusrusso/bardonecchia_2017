#include <ros.h>
#include <hb_core_msgs/MotorCtrl.h>
#include <hb_core_msgs/RobotStatus.h>
#include <hb_core_msgs/ServoMotorCtrl.h>

extern hb_core_msgs::MotorCtrl motor_ctrl;
extern hb_core_msgs::ServoMotorCtrl servo_ctrl;
extern hb_core_msgs::RobotStatus robot_status;

void ros_setup();
void ros_spin();
