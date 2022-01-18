int pinA = 10;
int pinB = 11;
int pinC = 7;
int pinD = 8;
int pinE = 9;
int pinF = 4;
int pinG = 5;
int pinDP = 6;
int cont = 0;
bool last_state = HIGH;
boolean high = false;

void setup(){
  pinMode(A0, INPUT_PULLUP);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  PCICR =2;
  PCMSK1 = 7;
}

void loop(){
  blinkDP();
}

void blinkDP(){
  if(high){
    digitalWrite(pinDP, HIGH);
  }else{
    digitalWrite(pinDP, LOW);
  } 
  high = !high;
  delay(1000);
}

void reset(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letraH(){
  reset();
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void letraE(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void letraL(){
  reset();
  digitalWrite(pinA, HIGH); 
  digitalWrite(pinB, HIGH); 
  digitalWrite(pinC, HIGH); 
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH); 
}

void letraO(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void vazio(){
  reset();
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void letraA(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void letraT(){
  reset();
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void n3(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void n2(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

 void n8(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

 void letraP(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

ISR(PCINT1_vect){
  if((digitalRead(A0)==0) && (last_state==HIGH)){
  switch(cont){
      case 0:
      letraH();
      blinkDP();
      cont++;
      last_state=LOW;
  break;
      case 1:
      letraE();
      blinkDP();
      cont++;
      last_state=LOW;
   break;
      case 2:
      letraL();
      blinkDP();
      cont++;
      last_state=LOW;
    break;
      case 3:
      letraL();
    blinkDP();
      cont++;
      last_state=LOW;
    break;
      case 4:
      letraO();
      blinkDP();
      cont++;
      last_state=LOW;
    break;
      case 5:
      vazio();
      blinkDP();
      cont++;
      last_state=LOW;
    break;
      case 6:
      letraA();
      blinkDP();
      cont++;
      last_state=LOW;
    break;
      case 7:
      letraT();
      blinkDP();
      cont++;
      last_state=LOW;
    break;
      case 8:
      n3();
    blinkDP();
      cont++;
      last_state=LOW;
    break;
      case 9:
      n2();
      blinkDP();
      cont++;
      last_state=LOW;
    break;
      case 10:
      n8();
      blinkDP();
      cont++;
      last_state=LOW;
    break;
      case 11:
    letraP();
      blinkDP();
      cont++;
      last_state=LOW;
    break;
      case 12:
      vazio();
      blinkDP();
      cont=0;
      last_state=LOW;
  break;
  }}else{
    if((digitalRead(A0)==1) && (last_state==LOW)){
    last_state=HIGH;
}}
}
