
int ledRed = 10;
int ledGreen = 9;
int ledBlue = 11;


void setup()  { 
  // nothing happens in setup 
}

void music1(){
  int off = 255;
  int on = 0;
  int entre = 150;

  analogWrite(ledGreen, off);
  analogWrite(ledBlue, off);
  analogWrite(ledRed, on);    
  
  delay(entre);
  
  analogWrite(ledGreen, off);
  analogWrite(ledBlue, on);
  analogWrite(ledRed, off);

  delay(entre);
  
  analogWrite(ledGreen, on);
  analogWrite(ledBlue, off);
  analogWrite(ledRed, off);      
  
  delay(entre);
  
  for(int i= 0 ; i<3 ; i++){
  analogWrite(ledGreen, on);
  analogWrite(ledBlue, on);
  analogWrite(ledRed, on);            
      delay(entre);
  analogWrite(ledGreen, off);
  analogWrite(ledBlue, off);
  analogWrite(ledRed, off);            
  delay(entre);
  }
}


void music2(){
  int off = 255;
  int on = 0;
  int entre = 100;
  int rep = 2;

  for(int i= 0 ; i<rep ; i++){
    analogWrite(ledGreen, off);
    analogWrite(ledBlue, off);
    analogWrite(ledRed, on);
    delay(entre);
    analogWrite(ledGreen, off);
    analogWrite(ledBlue, off);
    analogWrite(ledRed, off);
    delay(entre);
  }
  

  for(int i= 0 ; i<rep ; i++){
    analogWrite(ledGreen, off);
    analogWrite(ledBlue, on);
    analogWrite(ledRed, off);
    delay(entre);
    analogWrite(ledGreen, off);
    analogWrite(ledBlue, off);
    analogWrite(ledRed, off);
    delay(entre);
  }

  for(int i= 0 ; i<rep ; i++){
    analogWrite(ledGreen, on);
    analogWrite(ledBlue, off);
    analogWrite(ledRed, off);
    delay(entre);
    analogWrite(ledGreen, off);
    analogWrite(ledBlue, off);
    analogWrite(ledRed, off);
    delay(entre);
  }

  for(int i= 0 ; i<rep ; i++){
    analogWrite(ledGreen, on);
    analogWrite(ledBlue, on);
    analogWrite(ledRed, on);
    delay(entre);
    analogWrite(ledGreen, off);
    analogWrite(ledBlue, off);
    analogWrite(ledRed, off);
    delay(entre);
  }


}



void loop()  {
  music2();
}


