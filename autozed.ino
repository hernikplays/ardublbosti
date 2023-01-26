#include <Ultrasonic.h>
#include <Servo.h>

#define motor1_a 12  // PRAVY
#define motor1_b 11
#define motor1_pwm 6
#define motor2_a 8
#define motor2_b 7
#define motor2_pwm 5

Servo myservo;
Ultrasonic ultrasonic(A4, A5);

int distance;
unsigned long startTime;
const int time = 1300;

bool hledaZed = true;
bool toceni = false;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(motor1_a, OUTPUT);
  pinMode(motor1_b, OUTPUT);
  pinMode(motor1_pwm, OUTPUT);
  pinMode(motor2_a, OUTPUT);
  pinMode(motor2_b, OUTPUT);
  pinMode(motor2_pwm, OUTPUT);
  ultrasonic.setTimeout(40000UL);
  myservo.write(90);
  delay(1000);
}

void loop() {
  if (!toceni) {
    distance = ultrasonic.read();
  }
  /*Serial.print("Distance in CM: ");*/
  Serial.println(distance);
  if (hledaZed && !toceni && distance > 16) {
    // jedeme dopředu směrem ke zdi
    motor1_dopredu();
    motor2_dopredu();
  } else if (hledaZed && distance < 16) {
    // našli jsme zeď
    if (!toceni) {
      motor1_stop();
      motor2_stop();
      myservo.write(180);
      delay(20);
      startTime = millis();
      toceni = true;
    }

    if (millis() < startTime + time) {
      Serial.println("Točíme se na místě");
      motor2_dopredu();
      motor1_stop();
    } else {
      hledaZed = false;
      toceni = false;
      Serial.println("hotovo");
    }
  } else if (!hledaZed && distance > 18) {
    // jedeme podél zdi
    motor1_dopredu();
    motor2_stop();
  } else if (!hledaZed && distance < 18) {
    // musíme se otočit

    motor2_dopredu();
    motor1_stop();
  }
}

void motor1_dopredu() {
  digitalWrite(motor1_a, HIGH);
  digitalWrite(motor1_b, LOW);
  digitalWrite(motor1_pwm, HIGH);
}

void motor1_dozadu() {
  digitalWrite(motor1_a, LOW);
  digitalWrite(motor1_b, HIGH);
  digitalWrite(motor1_pwm, HIGH);
}

void motor1_stop() {
  digitalWrite(motor1_a, LOW);
  digitalWrite(motor1_b, LOW);
  digitalWrite(motor1_pwm, HIGH);
}

void motor2_dopredu() {
  digitalWrite(motor2_a, HIGH);
  digitalWrite(motor2_b, LOW);
  digitalWrite(motor2_pwm, HIGH);
}

void motor2_dozadu() {
  digitalWrite(motor2_a, LOW);
  digitalWrite(motor2_b, HIGH);
  digitalWrite(motor2_pwm, HIGH);
}

void motor2_stop() {
  digitalWrite(motor2_a, LOW);
  digitalWrite(motor2_b, LOW);
  digitalWrite(motor2_pwm, HIGH);
}