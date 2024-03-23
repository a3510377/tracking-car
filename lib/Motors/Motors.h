#pragma once

#include <Arduino.h>

#include "Motor.h"

class Motors {
 public:
  Motors(Motor *motor1, Motor *motor2) : _motor1(motor1), _motor2(motor2) {};

  void setup(void);
  void stop(void);
  void standby(void);

  void back(void);
  void back(uint8_t speed);
  void forward(void);
  void forward(uint8_t speed);
  void right(void);
  void right(uint8_t speed);
  void left(void);
  void left(uint8_t speed);

  void setDirection(Direction direction);
  void setDirection(Direction directionA, Direction directionB);
  void setDirectionA(Direction direction);
  void setDirectionB(Direction direction);

  Direction getDirectionA();
  Direction getDirectionB();

  void move(int8_t speed_direction);
  void moveA(int8_t speed_direction);
  void moveB(int8_t speed_direction);

  void setSpeed(uint8_t speed);
  void setSpeed(uint8_t speedA, uint8_t speedB);
  void setSpeedA(uint8_t speed);
  void setSpeedB(uint8_t speed);
  uint8_t getSpeedA();
  uint8_t getSpeedB();

  Motor *getMotorA();
  Motor *getMotorB();

 private:
  Motor *_motor1, *_motor2;
};
