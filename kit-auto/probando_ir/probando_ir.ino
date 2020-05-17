#include <IRremote.h>


long unsigned int CH_MINUS = "FFA25D";
long unsigned int CH_PLUS = "FFE21D";
long unsigned int CH = "FF629D";

long unsigned int PREV = "FF22DD";
long unsigned int NEXT = "FF02FD";
long unsigned int PLAY_PAUSE = "FFC23D";
long unsigned int VOL_MINUS = "FFE01F";
long unsigned int VOL_PLUS = "FFA857";
long unsigned int EQ = "FF906F";

long unsigned int ONE = 0xFF30CF;                 
long unsigned int TWO = "FF18E7";                 
long unsigned int THREE = "FF7A85";                  
long unsigned int FOUR = "FF10EF";                   
long unsigned int FIVE = "FF38C7";                    
long unsigned int SIX = "FF5AA5";                  
long unsigned int SEVEN = "FF42BD";                  
long unsigned int EIGHT = "FF4AB5";             
long unsigned int NINE = "FF52AD"; 
long unsigned int ZERO = "FF6897";

long unsigned int PLUS_100 = "FF9867";
long unsigned int PLUS_200 = "FFB04F";

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))
    {
     Serial.println(results.value, HEX);
     if ( results.value == ONE){
       Serial.println("Salio un uno");
     }
     irrecv.resume(); // Receive the next value
    }
}
