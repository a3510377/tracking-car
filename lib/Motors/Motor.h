#pragma once

#include <Arduino.h>

#ifdef ESP32
  #include <analogWrite.h>
#endif

enum Direction { FORWARD, BACK, STOP };

class Motor {
 public:
  Motor(uint8_t in1, uint8_t in2, uint8_t stby, uint8_t pwm)
      : _in1(in1), _in2(in2), _stby(stby), _pwm(pwm) {};

  void setup(void);
  void stop(void);
  void standby(void);

  void back(void);
  void back(uint8_t speed);
  void forward(void);
  void forward(uint8_t speed);

  void setDirection(Direction direction);
  Direction getDirection(void);

  void move(int32_t speed_direction);

  void setSpeed(uint8_t speed);
  void setDefaultSpeed(uint8_t speed);
  uint8_t getSpeed(void);
  uint8_t getDefaultSpeed(void);
  int32_t getSpeedDirection(void);

  uint8_t getIn1Pin(void);
  uint8_t getIn2Pin(void);
  uint8_t getStbyPin(void);
  uint8_t getPwmPin(void);

  void setPwm(uint8_t pwm);
  void setIn1(uint8_t in1);
  void setIn2(uint8_t in2);
  void setStby(uint8_t stby);

 private:
  uint8_t _in1, _in2, _stby, _pwm, _default_speed = 255;
  int32_t _speed_direction;
};
