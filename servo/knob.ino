#include <Servo.h>

Servo myservo;  // crear un objeto servo para controlar el servomotor
int potpin = A0;  // pin analógico usado para conectar el potenciometro
int val;    // variable para leer el valor del pin analógico

void setup() {
  myservo.attach(9);  // define el pin de conexión del servo
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potpin);            // lee el valor del potenciometro (valor entre 0 y 1023)
  val = map(val, 0, 1023, 0, 180);     // ajustar el rango del potenciometro al rango del motor
  Serial.println(val);
  myservo.write(val);                  // modifica la posición del motor
  delay(15);                           // esperar a que el motor realice el movimiento
}
