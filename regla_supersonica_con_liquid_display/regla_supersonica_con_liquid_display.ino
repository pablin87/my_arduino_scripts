#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //

const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor


void setup() {
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Initializing...");
  delay(1000);
  
}

void loop() {
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
  
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  lcd.clear();
  lcd.setCursor(0,0);
    
  lcd.print("Distancia: ");
  
  if (d < 60){
    lcd.print(d);
    lcd.print("cm");
  } else {
    float mts = (float) d / 60;
    lcd.print(mts);
    lcd.print("m");
  }
  
  delay(500);
}
