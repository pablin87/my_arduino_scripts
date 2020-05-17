#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h> 

int potenciometer_pin = A0;  // analog pin used to connect the potentiometer
int servo_signal_pin = 9;

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //

Servo myservo;  // create servo object to control a servo 

char degree = 'd';
int pval = -1;
int sangle = 0;

 
void setup() 
{ 
  myservo.attach(servo_signal_pin); 

  //Encender la luz de fondo.
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Initializing...");

  int sangle = myservo.read();
  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Servo angle:");
  lcd.setCursor(0,1);
  lcd.print(sangle);
  lcd.print(degree); //degree symbol
  
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Setting to  90");
  lcd.print(degree); //degree symbol
  myservo.write(90);
  delay(2000);
} 
 
void loop() 
{ 
  int new_pval = analogRead(potenciometer_pin);    
  if ( new_pval == pval){
    delay(20);
    return;
  }
  pval = new_pval;
  sangle = map(pval, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(sangle);                  // sets the servo position according to the scaled value 
  refresh_display();
  delay(20);
}

void refresh_display(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pot: ");
  lcd.print(pval);
  lcd.setCursor(0,1);
  lcd.print("Servo angle: ");
  lcd.print(sangle);
  lcd.print(degree); //degree symbol  
}
