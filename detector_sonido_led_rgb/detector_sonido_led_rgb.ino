
#include <SoftwareSerial.h>

int soundSensor=8;

int led_r=9;
int led_g=10;
int led_b=11;

boolean LEDStatus=false;

int cred = 0;
int cgreen = 0;
int cblue = 0;

const int color_step = 3;

long lastDebounceTime = 0;  // the last time the sensor heard something
long debounceDelay = 200;  

void setColor(int red,int green,int blue)
{
  analogWrite(led_r,red);
  analogWrite(led_g,green);
  analogWrite(led_b,blue); 
}

void init_colores(){
   setColor(0,255,255);
  delay(500);
  setColor(255,0,255);
  delay(500);
  setColor(255,255,0);
  delay(500);
  //Comprobacion todos los colores
  setColor(255,255,255);
  delay(500);
  setColor(0,0,0);
  delay(1000);
  setColor(255,255,255);
  delay(500);
  //Dejamos el color rojo para empezar el loop
  setColor(255,0,0);
  cred = 255;
  cblue = 0;
  cgreen = 0;
  delay(100);
}

void setup() {
 Serial.begin(9600);
 pinMode(soundSensor,INPUT);
 pinMode(led_r,OUTPUT);
 pinMode(led_g,OUTPUT);
 pinMode(led_b,OUTPUT);
 //init_colores();
}

void led_on(){
  Serial.println("led on");
  analogWrite(led_r, 255);
  analogWrite(led_g, 255);
  analogWrite(led_b, 255);
}

void led_off(){
    Serial.println("led off");
  cred = 0;
  cgreen = 0;
  cblue = 0;
  analogWrite(led_r, 0);
  analogWrite(led_g, 0);
  analogWrite(led_b, 0);
}


void loop() {
  
  int SensorData=digitalRead(soundSensor);
  if ( SensorData == 1 && (millis() - lastDebounceTime) > debounceDelay) {
    lastDebounceTime = millis();
    if(SensorData==1){
      Serial.println("sensor data");
      if(LEDStatus==false){
          LEDStatus=true;
      } else{
          LEDStatus=false;
      }
    }
  }
  
  if (LEDStatus == true){
    led_step();
    delay(5);
  } else{
    led_off();
  }
} 

 
void led_step() { 
  if (cblue == 0 && cred == 255 && cgreen >= 0 and cgreen < 255){
      //Se mantiene el rojo al maximo mientras sube el verde
      cgreen = cgreen + color_step;    
  } else if ( cgreen == 255 && cblue == 0 && cred > 0){
      //Se mantiene el verde al maximo mientras baja el rojo
      cred = cred - color_step;
  } else if ( cgreen == 255 && cred == 0 && cblue >=0 && cblue < 255){
     //Se mantiene el verde al maximo mientras sube el azul
     cblue = cblue + color_step;
  } else if ( cblue == 255 && cred == 0 && cgreen > 0){
    //Se mantiene el azul al maximo mientras baja el verde
    cgreen = cgreen - color_step;
  } else if (cblue == 255 && cgreen == 0 && cred >= 0 && cred < 255){
    //Se mantiene el azul al maximo mientras sube el rojo
    cred = cred + color_step;
  } else if (cred == 255 && cgreen == 0 && cblue > 0){
    //Se mantiene el rojo al maximo mientras baja el azul
    cblue = cblue - color_step;
  } else if (cblue == 0 && cgreen == 0 && cred >= 0) {
    cred = cred + color_step;
  }else {
    Serial.println("Shouldn't reach here");
    Serial.print(cred);
    Serial.print(","); 
    Serial.print(cgreen); 
    Serial.print(","); 
    Serial.print(cblue); 
  }
  if (cred > 255){
    cred = 255;
  }
  if (cblue > 255){
    cblue = 255;
  }
  if (cgreen > 255){
    cgreen = 255;
  }
  if (cred < 0){
    cred = 0;
  }
  if (cblue < 0){
    cblue = 0;
  }
  if (cgreen < 0){
    cgreen = 0;
  }
  setColor(cred, cgreen, cblue);
}
