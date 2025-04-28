#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

const int servoMin = 100; // minimale Pulsweite
const int servoMax = 500; // maximale Pulsweite

const int segments[7] = {0, 1, 2, 3, 4, 5, 6};

const bool digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

void setup() {
  pwm.begin();
  pwm.setPWMFreq(50);
  delay(500);
}

void loop() {
  for (int d = 0; d <= 9; d++) {
    showDigit(d);
    delay(1000);
  }
}

void showDigit(int num) {
  for (int i = 0; i < 7; i++) {
    if (digits[num][i]) {
      pwm.setPWM(segments[i], 0, servoMax);
    } else {
      pwm.setPWM(segments[i], 0, servoMin);
    }
  }
}
