#include <Servo.h> // Incluír librería para utilizar el servomotor

Servo myServo; // Crear una instancia de la clase servo 

void setup() {  
  myServo.attach(9); // Especificar el pin de conexión del servomotor
  myServo.write(0);
}

void loop() {
  // Mover el motor de 0 a 180 grados en pasos de 1 grado
  for(int pos = 0; pos <= 180; pos++){
    myServo.write(pos); // Modificar la orientación del eje del servomotor
    delay(15); // Esperar 15ms    
  }

  // Mover el motor de 180 a 0 grados en pasos de 1 grado
  for(int pos = 180; pos >= 0; pos--){
    myServo.write(pos); // Modificar la orientación del eje del servomotor
    delay(15); // Esperar 15ms    
  }

  delay(2200);

  for(int pos = 0; pos <= 180; pos += 60){
    myServo.write(pos + 60); // Modificar la orientación del eje del servomotor
    delay(500);
    myServo.write(pos);
    
    delay(1000); // Esperar 1s
  }  

  delay(2200);
  

  for(int pos = 180; pos >= 0; pos -= 30){
    myServo.write(pos - 30); // Modificar la orientación del eje del servomotor
    delay(500);
    myServo.write(pos);
    
    delay(1000); 
  }  

  delay(2200);
    
}
