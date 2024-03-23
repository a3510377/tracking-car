#include <Arduino.h>
#include <Motor.h>
#include <Motors.h>

#define PWMA 21
#define AIN2 19
#define AIN1 18
#define STBY 5
#define BIN1 17
#define BIN2 16
#define PWMB 4

#define PWMA_ID 0
#define PWMB_ID 1

Motor motor1(AIN1, AIN2, STBY, PWMA);
Motor motor2(BIN1, BIN2, STBY, PWMB);

Motors motors(&motor1, &motor2);

void setup() {
  Serial.begin(9600);

  motors.setup();
  motors.setSpeed(100);
}

void loop() {
  if (Serial.available()) {
    uint8_t id = Serial.read() - 48;
    Serial.println("id: " + String(id));
    switch (id) {
      case 0:
        Serial.println("stop");
        motors.stop();
        break;
      case 1:
        Serial.println("forward");
        motors.forward();
        break;
      case 2:
        Serial.println("back");
        motors.back();
        break;
      case 3:
        Serial.println("right");
        motors.right();
        break;
      case 4:
        Serial.println("left");
        motors.left();
        break;
      case 5:
        Serial.println("standby");
        motors.standby();
        break;
      default:
        break;
    }
    Serial.println(motor1.getSpeedDirection());
    Serial.println(motor2.getSpeedDirection());
  }
}
