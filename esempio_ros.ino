#include "ros_controller.hpp"

#define BRAKEVCC 0
#define CW   1
#define CCW  2
#define BRAKEGND 3
#define CS_THRESHOLD 100

int inApin[2] = {7, 4};  // INA: Clockwise input
int inBpin[2] = {8, 9}; // INB: Counter-clockwise input
int pwmpin[2] = {5, 6}; // PWM input
int cspin[2] = {2, 3}; // CS: Current sense ANALOG input
int enpin[2] = {0, 1}; // EN: Status of switches output (Analog pin)

void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)
{
  if (motor <= 1)
  {
    if (direct <=4)
    {
      // Set inA[motor]
      if (direct <=1)
        digitalWrite(inApin[motor], HIGH);
      else
        digitalWrite(inApin[motor], LOW);

      // Set inB[motor]
      if ((direct==0)||(direct==2))
        digitalWrite(inBpin[motor], HIGH);
      else
        digitalWrite(inBpin[motor], LOW);

      analogWrite(pwmpin[motor], pwm);
    }
  }
}

int cnt = 0;

void setup() {
  ros_setup();
}

void loop() {

  robot_status.battery = cnt++;
  robot_status.current_sx = analogRead(cspin[0]);
  robot_status.current_dx = analogRead(cspin[0]);

  if (motor_ctrl.dx < 0) {
      motorGo(0, CCW, -motor_ctrl.dx);
  } else  {
      motorGo(0, CW, motor_ctrl.dx);
    }

    if (motor_ctrl.sx < 0) {
        motorGo(1, CCW, -motor_ctrl.sx);
    } else  {
        motorGo(1, CW, motor_ctrl.sx);
      }

  ros_spin();
  delay(10);
}
