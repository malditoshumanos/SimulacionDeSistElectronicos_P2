#include <Stepper.h>

const int stepsPerRevolution = 10; // El motor solo funciona cuando este valor es cercano a 10  
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600); // Iniciar monitor serial
  while (!Serial) {
    ; // Esperar a que el monitor serial se inicie correctamente 
  }
  Serial.println("Programa iniciado.");
  Serial.setTimeout(10000); // Definir el tiempo de espera para recibir input
  Serial.flush(); // Limpiar el buffer del monitor serial

}

void loop() {
  int velRot = 0;
  int st = 0;
    
  Serial.println("***********************************************");
  Serial.println("Introduca la velocidad de rotacion: ");
  velRot = Serial.parseInt();
  Serial.println(velRot);
  Serial.println("Introduca el numero de steps: ");
  st = Serial.parseInt();
  Serial.println(st);       
 
  
  myStepper.setSpeed(velRot); // Definir las RPM a las que girará el motor
  myStepper.step(st); // Hacer que el motor gire una cierta cantidad de "pasos" (steps)
  
  Serial.flush(); 
  delay(1000);

}
