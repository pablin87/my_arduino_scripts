/* 
 Ejemplo de control de motor DC usando modulo L298
 http://electronilab.co/tienda/driver-dual-para-motores-full-bridge-l298n/
 
 El programa activa el motor en un sentido por 4 segundos, 
 para el motor por 500 ms, activa el motor en sentido inverso por 4 segundos 
 y se detiene por 5 segundos. Luego repite la acción indefinidamente.
 
 Creado 16/05/14
 por Andres Cruz
 ELECTRONILAB.CO
 */

int IN1 = 2; 
int IN2 = 3;
int IN3 = 4; 
int IN4 = 5;
int motorA = 6;
int motorB = 1;



void setup()
{
  pinMode (IN1, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (IN2, OUTPUT);    // Input3 conectada al pin 5
  pinMode (IN3, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (IN4, OUTPUT);    // Input3 conectada al pin 5
  pinMode (motorA, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (motorB, OUTPUT);    // Input3 conectada al pin 5
}
void loop()
{
  // Motor gira en un sentido
  digitalWrite (motorA, HIGH);
  digitalWrite (motorB, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN1, HIGH);
  
  delay(2000);
  digitalWrite (motorA, LOW);
  digitalWrite (motorB, LOW);
  delay(2000);
}
