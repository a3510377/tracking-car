#include "Motors.h"

void Motors::setup() {
  _motor1->setup();
  _motor2->setup();
}
void Motors::stop() {
  _motor1->stop();
  _motor2->stop();
}
void Motors::standby() {
  _motor1->standby();
  _motor2->standby();
}

void Motors::back(void) {
  _motor1->back();
  _motor2->back();
}
void Motors::back(uint8_t speed) {
  _motor1->back(speed);
  _motor2->back(speed);
}
void Motors::forward(void) {
  _motor1->forward();
  _motor2->forward();
}
void Motors::forward(uint8_t speed) {
  _motor1->forward(speed);
  _motor2->forward(speed);
}
void Motors::right(void) {
  _motor1->forward();
  _motor2->back();
}
void Motors::right(uint8_t speed) {
  _motor1->forward(speed);
  _motor2->back(speed);
}
void Motors::left(void) {
  _motor1->back();
  _motor2->forward();
}
void Motors::left(uint8_t speed) {
  _motor1->back(speed);
  _motor2->forward(speed);
}

void Motors::setDirection(Direction direction) {
  _motor1->setDirection(direction);
  _motor2->setDirection(direction);
}
void Motors::setDirection(Direction directionA, Direction directionB) {
  _motor1->setDirection(directionA);
  _motor2->setDirection(directionB);
}
void Motors::setDirectionA(Direction direction) {
  _motor1->setDirection(direction);
}
void Motors::setDirectionB(Direction direction) {
  _motor2->setDirection(direction);
}

Direction Motors::getDirectionA() {
  return _motor1->getDirection();
}
Direction Motors::getDirectionB() {
  return _motor2->getDirection();
}

void Motors::move(int8_t speed_direction) {
  _motor1->move(speed_direction);
  _motor2->move(speed_direction);
}
void Motors::moveA(int8_t speed_direction) {
  _motor1->move(speed_direction);
}
void Motors::moveB(int8_t speed_direction) {
  _motor2->move(speed_direction);
}

void Motors::setSpeed(uint8_t speed) {
  _motor1->setSpeed(speed);
  _motor2->setSpeed(speed);
}
void Motors::setSpeed(uint8_t speedA, uint8_t speedB) {
  _motor1->setSpeed(speedA);
  _motor2->setSpeed(speedB);
}
void Motors::setSpeedA(uint8_t speed) {
  _motor1->setSpeed(speed);
}
void Motors::setSpeedB(uint8_t speed) {
  _motor2->setSpeed(speed);
}
uint8_t Motors::getSpeedA() {
  return _motor1->getSpeed();
}
uint8_t Motors::getSpeedB() {
  return _motor2->getSpeed();
}

Motor *Motors::getMotorA() {
  return _motor1;
}
Motor *Motors::getMotorB() {
  return _motor2;
}
