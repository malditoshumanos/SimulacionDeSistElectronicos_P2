#include <Servo.h> // Incluír librería para utilizar el servomotor

Servo myServo; // Crear una instancia de la clase servo 

void setup() {
  myServo.attach(9); // Especificar el pin de conexión del servomotor
  myServo.write(0); 
  
  Serial.begin(9600); // Iniciar monitor serial
  while (!Serial) {
    ; // Esperar a que el monitor serial se inicie correctamente 
  }
  Serial.println("Programa iniciado. Ingrese posición del servomotor: ");
  Serial.setTimeout(10000); // Definir el tiempo de espera para recibir input
  Serial.flush(); // Limpiar el buffer del monitor serial
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    int pos = Serial.parseInt();
    myServo.write(pos);
  }
  
}
