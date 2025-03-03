#include <Wire.h>

int motorA1 = 9;
int motorA2 = 11;

int motorB1 = 6;
int motorB2 = 3;

int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;

#define NUM_SENSOR 5
int valorSensores[NUM_SENSOR];

int velocidade = 140;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);

  Serial.begin(9600);
}

void leituraSensores() {
  valorSensores[0] = digitalRead(sensor1);
  valorSensores[1] = digitalRead(sensor2);
  valorSensores[2] = digitalRead(sensor3);
  valorSensores[3] = digitalRead(sensor4);
  valorSensores[4] = digitalRead(sensor5);
}
void frente() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, velocidade);

  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, velocidade);
}
void esquerda() {
  digitalWrite (motorB1, velocidade);
  digitalWrite(motorB2, LOW);

  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
}
void direita() {
  digitalWrite(motorA1, velocidade);
  digitalWrite(motorA2, LOW);

  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}


void loop() {
  leituraSensores();
  if (valorSensores[2] == 1) {
    frente();
  }

  if (valorSensores[1] == 1 && valorSensores[2] == 0) {
    esquerda();
  }
  if (valorSensores[3] == 1 && valorSensores[2] == 0) {
    direita();
  }


  /*

    for (int i = 0; i < NUM_SENSOR; i++) {
    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(valorSensores[i]);
    }
    delay(5000);
  */


}
