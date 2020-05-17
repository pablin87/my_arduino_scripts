#include <IRremote.h>

const long unsigned int CH_MINUS = 0xFFA25D;
const long unsigned int CH_PLUS = 0xFFE21D;
const long unsigned int CH = 0xFF629D;

const long unsigned int PREV = 0xFF22DD;
const long unsigned int NEXT = 0xFF02FD;
const long unsigned int PLAY_PAUSE = 0xFFC23D;
const long unsigned int VOL_MINUS = 0xFFE01F;
const long unsigned int VOL_PLUS = 0xFFA857;
const long unsigned int EQ = 0xFF906F;

const long unsigned int ONE = 0xFF30CF;                 
const long unsigned int TWO = 0xFF18E7;                 
const long unsigned int THREE = 0xFF7A85;                  
const long unsigned int FOUR = 0xFF10EF;                   
const long unsigned int FIVE = 0xFF38C7;                    
const long unsigned int SIX = 0xFF5AA5;                  
const long unsigned int SEVEN = 0xFF42BD;                  
const long unsigned int EIGHT = 0xFF4AB5;             
const long unsigned int NINE = 0xFF52AD; 
const long unsigned int ZERO = 0xFF6897;

const long unsigned int PLUS_100 = 0xFF9867;
const long unsigned int PLUS_200 = 0xFFB04F;

const long unsigned int LAST_VALUE = 0xFFFFFFFF;
const long unsigned int NO_VALUE = 0;

long unsigned int ir_last_value = NO_VALUE;

// Motor A 
int enA = 9;
int in1 = 8;
int in2 = 7;
 
// Motor B
int enB = 4;
int in3 = 6;
int in4 = 5;

int IR_PIN = 11;

IRrecv irrecv(IR_PIN);
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

long unsigned int last_value = NO_VALUE;
bool moving=false;
int DELAY=100;
void loop()
{  
  unsigned long int ir_value;
  
  if (irrecv.decode(&results)){
    ir_value = results.value;
    switch (ir_value){
      case TWO:
        avanzar();
        moving = true;
        Serial.print("Avanzando\n");
        delay(DELAY);
        break;
      case EIGHT:
        retroceder();
        moving = true;
        Serial.print("Retrocediendo\n");
        delay(DELAY);
        break;
      case LAST_VALUE:
        delay(DELAY);
        Serial.print("LAST VALUE\n");
        break;
    }
    irrecv.resume();
  } else {
    ir_value = NO_VALUE;
    if (moving){
      frenar();
      Serial.print("Frenando\n");
      delay(DELAY);
      moving = false;
    } else {
      Serial.print("Frenado\n");
      delay(DELAY);
    }
  }
}


void avanzar(){ 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(enA, HIGH);  
  digitalWrite(enB, HIGH);  
}

void retroceder(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(enA, HIGH);  
  digitalWrite(enB, HIGH);  
}

void frenar(){
  digitalWrite(enA, LOW);  
  digitalWrite(enB, LOW);  
}

