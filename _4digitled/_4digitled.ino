

int digit1 = 2;
int digit2 = 3;
int digit3 = 4;
int digit4 = 5;

int pos_a = 6;
int pos_b = 7;
int pos_c = 8;
int pos_d = 9;
int pos_e = 10;
int pos_f = 11;
int pos_g = 12;
int point = 13;

void setup() {

  Serial.begin(9600);
  
  pinMode(digit1, OUTPUT); 
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);

  pinMode(pos_a, OUTPUT);
  pinMode(pos_b, OUTPUT);
  pinMode(pos_c, OUTPUT);
  pinMode(pos_d, OUTPUT);
  pinMode(pos_e, OUTPUT);
  pinMode(pos_f, OUTPUT);
  pinMode(pos_g, OUTPUT);
  pinMode(point, OUTPUT);
}

void write_one(){
  digitalWrite(pos_b, HIGH);
  digitalWrite(pos_c, HIGH);
}

void write_two(){
  digitalWrite(pos_a, HIGH);
  digitalWrite(pos_b, HIGH);
  digitalWrite(pos_d, HIGH);
  digitalWrite(pos_e, HIGH);
  digitalWrite(pos_g, HIGH);
}

void write_three(){
  digitalWrite(pos_a, HIGH);
  digitalWrite(pos_b, HIGH);
  digitalWrite(pos_c, HIGH);
  digitalWrite(pos_d, HIGH);
  digitalWrite(pos_g, HIGH);
}

void write_four(){
  digitalWrite(pos_b, HIGH);
  digitalWrite(pos_c, HIGH);
  digitalWrite(pos_f, HIGH);
  digitalWrite(pos_g, HIGH);
}


void clean (){
  digitalWrite(digit1, HIGH);
  digitalWrite(digit2, HIGH);
  digitalWrite(digit3, HIGH);
  digitalWrite(digit4, HIGH);

  digitalWrite(pos_a, LOW);
  digitalWrite(pos_b, LOW);
  digitalWrite(pos_c, LOW);
  digitalWrite(pos_d, LOW);
  digitalWrite(pos_e, LOW);
  digitalWrite(pos_f, LOW);
  digitalWrite(pos_g, LOW);
  digitalWrite(point, LOW);
}

int get_delay(){
  int sensorValue = analogRead(A0);
  int value = sensorValue * ( 100.0 /1023.0 );
  return value;
}
4
void loop() {
  int del = get_delay();
  Serial.print("Valor del sensor: ");
  Serial.println(del);
  
  clean();
  digitalWrite(digit1, LOW);
  write_one();
  delay(del);

  clean();
  digitalWrite(digit2, LOW);
  write_two();
  delay(del);
  
  clean();
  digitalWrite(digit3, LOW);
  write_three();
  delay(del);
  
  clean();
  digitalWrite(digit4, LOW);
  write_four();
  delay(del);
}

