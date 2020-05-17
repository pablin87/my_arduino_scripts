#include <dht.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int DHTPIN = 7;

dht DHT;
LiquidCrystal_I2C lcd(0x3F,16,2);

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Initializing...");
  delay(1000);
  
}

void loop()
{
  int chk = DHT.read11(DHTPIN);
  if (chk == DHTLIB_OK){
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Temp: ");
    lcd.print(DHT.temperature);
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Humidity: ");
    lcd.print(DHT.humidity);
    lcd.print("%");
  }  
  delay(1000);
}

