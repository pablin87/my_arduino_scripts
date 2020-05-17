#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  

int blue_RXD_pin = 2;
int blue_TXD_pin = 1;

// Motor A 
int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B
int enB = 3;
int in3 = 5;
int in4 = 4;

// Pins Leds RGB
int led_red = 10;
int led_green = 11;
int led_blue = 12;

const int VEL_ZERO = 0;
const int VEL_VERY_LOW = 120;
const int VEL_LOW = 170;
const int VEL_MEDIUM = 200;
const int VEL_HIGH = 255;

const int TURN_VEL_LOW = 80;
const int TURN_VEL_MEDIUM = 90;
const int TURN_VEL_HIGH = 95;

int current_vel = VEL_ZERO;
int current_turn_vel = VEL_ZERO;

int value_led_red = 0;
int value_led_green = 0;
int value_led_blue = 0;

SoftwareSerial BT(blue_RXD_pin, blue_TXD_pin);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth

void switch_led(int pin, int & analog_value){
  if (analog_value == 0){
    analog_value = 255;
  } else {
    analog_value = 0;
  }
  analogWrite(pin, analog_value);
}

void increase_current_velocity(){
  switch (current_vel) {
  case VEL_ZERO:
    current_vel = VEL_VERY_LOW;
    break;
  case VEL_VERY_LOW:
    current_vel = VEL_LOW;
    break;
  case VEL_LOW:
    current_vel = VEL_MEDIUM;
    break;
  case VEL_MEDIUM:
    current_vel = VEL_HIGH;
    break;
  case VEL_HIGH:
    break;
  default:
    break;
  }
}

void increase_turn_current_velocity(){
  switch (current_turn_vel) {
  case VEL_ZERO:
    current_turn_vel = TURN_VEL_LOW;
    break;
  case TURN_VEL_LOW:
    current_turn_vel = TURN_VEL_MEDIUM;
    break;
  case TURN_VEL_MEDIUM:
    current_turn_vel = TURN_VEL_HIGH;
  case TURN_VEL_HIGH:
    break;
  default:
    break;
  }
}

String velocity_to_string(int vel){
  switch (vel) {
  case VEL_ZERO:
    return "velocity ZERO";
    break;
  case VEL_VERY_LOW:
    return "velocity VERY LOW";
    break;
  case VEL_LOW:
    return "velocity LOW";
    break;
  case VEL_MEDIUM:
    return "velocity MEDIUM";
    break;
  case VEL_HIGH:
    return "velocity HIGH";
    break;
  case TURN_VEL_LOW:
    return "velocity TURN LOW";
    break;
  case TURN_VEL_MEDIUM:
    return "velocity TURN MEDIUM";
    break;
  case TURN_VEL_HIGH:
    return "velocity TURN HIGH";
    break;
  default:
    return "velocity UNKNOWN";
    break;
  }
}


void setup()
{
  Serial.begin(9600);

  BT.begin(9600);       // Inicializamos el puerto serie BT que hemos creado para el bluetooth

  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

int DELAY = 50;
enum STATE { STOP, MOVING_FORWARD, MOVING_BACKWARD, TURNING_RIGHT, TURNING_LEFT};
STATE state = STOP;

void loop()
{
  String bt_value = check_bluetooth();
  if (bt_value == "arriba"){
    if (state == STOP){
      avanzar();
      delay(DELAY);
    } else if ( state == MOVING_FORWARD){
      avanzar();
      delay(DELAY);
    } else {
      frenar();
      delay(DELAY);
    }
  } else if (bt_value == "abajo"){
    if (state == STOP){
      retroceder();
      delay(DELAY);
    } else if ( state == MOVING_BACKWARD){
      retroceder();
      delay(DELAY);
    } else {
      frenar();
      delay(DELAY);
    }
  } else if (bt_value == "derecha"){
    if (state == STOP){
      girar_derecha();
      delay(DELAY);
    } else if ( state == TURNING_RIGHT){
      girar_derecha();
      delay(DELAY);
    } else {
      frenar();
      delay(DELAY);
    }
  } else if (bt_value == "izquierda"){
    if (state == STOP){
      girar_izquierda();
      delay(DELAY);
    } else if ( state == TURNING_LEFT){
      girar_izquierda();
      delay(DELAY);
    } else {
      frenar();
      delay(DELAY);
    }
  } else if ( bt_value == "circulo"){
    on_circle();
  } else if ( bt_value == "equis"){
    on_X();
  } else if ( bt_value == "cuadrado"){
    on_square();
  } else if ( bt_value == "triangulo"){
    on_triangle();
  }
}

String check_bluetooth(){
  String buffer = "";
  if (BT.available()){
    char c = BT.read();
    buffer += c;
    while(BT.available())
    {
      char c = BT.read();
      buffer += c;
    }
    Serial.println("Recibido:");
    Serial.println(buffer);
  }
  return buffer;
}

void on_circle(){
  Serial.println("Circle pressed");
  switch_led(led_green, value_led_green);
}

void on_X(){
  Serial.println("X pressed");
  switch_led(led_blue, value_led_blue);
}

void on_square(){
  Serial.println("Square pressed");
  switch_led(led_red, value_led_red);
}

void on_triangle(){
  Serial.println("Triangle pressed");
}

void avanzar(){
  increase_current_velocity();
  state = MOVING_FORWARD;
  Serial.println("Avanzando: " + velocity_to_string(current_vel));
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  analogWrite(enA, current_vel);  
  analogWrite(enB, current_vel);  
}

void retroceder(){
  increase_current_velocity();
  state = MOVING_BACKWARD;
  Serial.println("Retrocendiendo: " + velocity_to_string(current_vel));
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(enA, current_vel);  
  analogWrite(enB, current_vel);  
}

void girar_izquierda(){
  increase_turn_current_velocity();
  state = TURNING_LEFT;
  Serial.println("Girando a la Izquierda: " + velocity_to_string(current_turn_vel));
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  analogWrite(enA, current_turn_vel);  
  analogWrite(enB, current_turn_vel);  

}

void girar_derecha(){
  increase_turn_current_velocity();
  state = TURNING_RIGHT;
  Serial.println("Girando a la Derecha: " + velocity_to_string(current_turn_vel));
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(enA, current_turn_vel);  
  analogWrite(enB, current_turn_vel);  
}


void frenar(){
  current_vel = VEL_ZERO;
  current_turn_vel = VEL_ZERO;
  state = STOP;
  Serial.println("Frenando");
  analogWrite(enA, current_vel);  
  digitalWrite(enB, current_vel);  
}

