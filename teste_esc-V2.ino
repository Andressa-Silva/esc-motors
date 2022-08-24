// Teste do funcionamento dos ESC's a partir de um potenciometro

#include <Servo.h>

Servo ESC;                                     // create servo object to control the ESC

int potValue;                                  // value from the analog pin - valor do potenciometro
int pin_pot   =   A0;                          // pino do potenciometro
int pin_esc   =    9;                          // pino esc
int min_pulse = 1000;                          // largura minima do pulso em microsegundos
int max_pulse = 2000;                          // largura máxima do pulso em microsegundos

void setup() {
  Serial.begin(9600);                          // abre a porta serial, configura a taxa de transferência para 9600
  ESC.attach(pin_esc, min_pulse, max_pulse);   // (pino, min pulse width, max pulse width in microseconds)
  Serial.println("Aguardando 5 segundos....");
  delay(5000);
}

void loop() {
  potValue = analogRead(pin_pot);              // reads the value of the potentiometer (value between 0 and 1023)
  potValue = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)

  Serial.print("Potenciometro: ");             // monitor serial
  Serial.println(potValue);

  ESC.write(potValue);                         // send the signal to the ESC
}

// Circuito de base:
// https://howtomechatronics.com/wp-content/uploads/2019/02/Arduino-BLDC-Motor-Control-Circuit-Diagram-Schematic.png
// Descricao do funcionamento:
// https://howtomechatronics.com/tutorials/arduino/arduino-brushless-motor-control-tutorial-esc-bldc/
