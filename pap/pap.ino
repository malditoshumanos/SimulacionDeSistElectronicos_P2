#include <Stepper.h>

const int stepsPerRevolution = 10; 
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int velRot = 500;
  int st = 300;
    
  if (Serial.available() > 0) { // Check if there is data available in the serial buffer
    
  
    Serial.println("Introduca la velocidad de rotacion: ");
    velRot = Serial.parseInt();
    Serial.println(velRot);
    Serial.println("Introduca el numero de steps: ");
    st = Serial.parseInt();       
    
  } 
  
  myStepper.setSpeed(velRot); // Definir las RPM a las que girará el motor
  myStepper.step(st); // Hacer que el motor gire una cierta cantidad de "pasos" (steps)

  Serial.flush(); // Clear the serial buffer of any remaining characters

  delay(1000);

}
