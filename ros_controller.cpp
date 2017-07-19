#include <ros.h>
#include <hb_core_msgs/MotorCtrl.h>
#include "ros_controller.hpp"

ros::NodeHandle _nh;
hb_core_msgs::RobotStatus robot_status;
hb_core_msgs::MotorCtrl motor_ctrl;
hb_core_msgs::ServoMotorCtrl servo_ctrl;

void _motors_cb( const hb_core_msgs::MotorCtrl& motor_msg) {
  motor_ctrl = motor_msg;
}

void _servo_cb( const hb_core_msgs::ServoMotorCtrl& motor_msg) {
  servo_ctrl = motor_msg;
}

ros::Subscriber<hb_core_msgs::MotorCtrl> _motor_sub("/motors", &_motors_cb);
ros::Subscriber<hb_core_msgs::ServoMotorCtrl> _servo_sub("/servo", &_servo_cb);

ros::Publisher _status_pub("/status", &robot_status);

void ros_setup()
{
  _nh.initNode();
  _nh.subscribe(_motor_sub);
  _nh.subscribe(_servo_sub);
  _nh.advertise(_status_pub);
}

void ros_spin() {
  _status_pub.publish(&robot_status);
  _nh.spinOnce();
}
