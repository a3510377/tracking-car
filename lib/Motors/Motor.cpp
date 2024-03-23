#include "Motor.h"

void Motor::setup() {
  pinMode(_in1, OUTPUT);
  pinMode(_in2, OUTPUT);
  pinMode(_stby, OUTPUT);
  pinMode(_pwm, OUTPUT);
}

void Motor::standby() {
  digitalWrite(_stby, LOW);
}

void Motor::forward() {
  if (!_speed_direction) setSpeed(255);
  else if (_speed_direction < 0) _speed_direction = -_speed_direction;

  move(_speed_direction);
}

void Motor::forward(uint8_t speed) {
  move(abs(speed));
}

void Motor::back() {
  if (!_speed_direction) {
    setSpeed(255);
    _speed_direction *= -1;
  } else if (_speed_direction > 0) _speed_direction = -_speed_direction;

  move(_speed_direction);
}

void Motor::back(uint8_t speed) {
  move(-abs(speed));
}

void Motor::stop() {
  move(0);
}

void Motor::setDirection(Direction direction) {
  if (direction == FORWARD) forward();
  else if (direction == BACK) back();
  else stop();
}

Direction Motor::getDirection() {
  if (_speed_direction == 0) {
    return STOP;
  }

  return _speed_direction > 0 ? FORWARD : BACK;
}

void Motor::move(int32_t speed_direction) {
  _speed_direction = speed_direction;

  setSpeed(abs(speed_direction));
  if (_speed_direction > 0) {
    // forward
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, LOW);
  } else if (_speed_direction < 0) {
    // back
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, HIGH);
  } else {
    // stop
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, LOW);
    analogWrite(_pwm, 0);
  }
  digitalWrite(_stby, HIGH);
}

void Motor::setSpeed(uint8_t speed) {
  _speed_direction = _speed_direction >= 0 ? speed : -speed;

  analogWrite(_pwm, speed);
}

uint8_t Motor::getSpeed() {
  return abs(_speed_direction);
}
int32_t Motor::getSpeedDirection() {
  return _speed_direction;
}

uint8_t Motor::getIn1Pin() {
  return _in1;
}
uint8_t Motor::getIn2Pin() {
  return _in2;
}
uint8_t Motor::getStbyPin() {
  return _stby;
}
uint8_t Motor::getPwmPin() {
  return _pwm;
}

void Motor::setPwm(uint8_t pwm) {
  _pwm = pwm;
}
void Motor::setIn1(uint8_t in1) {
  _in1 = in1;
}
void Motor::setIn2(uint8_t in2) {
  _in2 = in2;
}
void Motor::setStby(uint8_t stby) {
  _stby = stby;
}
