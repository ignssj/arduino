int pinA = 10;
int pinB = 11;
int pinC = 7;
int pinD = 8;
int pinE = 9;
int pinF = 12;
int pinG = 13;
int pin2A = 30;
int pin2B = 31;
int pin2C = 2;
int pin2D = 3;
int pin2E = 4;
int pin2F = 5;
int pin2G = 6;
int cont = 0;
bool last_state = HIGH;
boolean high = false;
int display2=0;
int display1=0;

void setup(){
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pin2A, OUTPUT);
  pinMode(pin2B, OUTPUT);
  pinMode(pin2D, OUTPUT);
  pinMode(pin2E, OUTPUT);
  pinMode(pin2C,OUTPUT);
  pinMode(pin2F,OUTPUT);
  pinMode(pin2G,OUTPUT);
  d1n0();
  d2n0();
  TCCR1A = 0;                        
  TCCR1B = 0;  
  TCCR1B |= (1<<CS10)|(1 << CS12);
  TCNT1 = 0xC2F7;                   
  TIMSK1 |= (1 << TOIE1);
  TCCR2A = 0;
 TCCR2B = 7;
TCNT2 = 0; //registrador de contagem
TIMSK2 = 1;//habilita interrupçao do timer2
}

void loop(){
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

void reset2(){
  digitalWrite(pin2A, HIGH);
  digitalWrite(pin2B, HIGH);
  digitalWrite(pin2C, HIGH);
  digitalWrite(pin2D, HIGH);
  digitalWrite(pin2E, HIGH);
  digitalWrite(pin2F, HIGH);
  digitalWrite(pin2G, HIGH);
}

void d1n0(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void d1n1(){
  reset();
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void d1n2(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void d1n3(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void d1n4(){
  reset();
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void d1n5(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void d1n6(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void d1n7(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

 void d1n8(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

 void d1n9(){
  reset();
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void d2n0(){
  reset2();
  digitalWrite(pin2A, LOW);
  digitalWrite(pin2B, LOW);
  digitalWrite(pin2C, LOW);
  digitalWrite(pin2D, LOW);
  digitalWrite(pin2E, LOW);
  digitalWrite(pin2F, LOW);
  digitalWrite(pin2G, HIGH);
}

void d2n1(){
  reset2();
  digitalWrite(pin2A, HIGH);
  digitalWrite(pin2B, LOW);
  digitalWrite(pin2C, LOW);
  digitalWrite(pin2D, HIGH);
  digitalWrite(pin2E, HIGH);
  digitalWrite(pin2F, HIGH);
  digitalWrite(pin2G, HIGH);
}

void d2n2(){
  reset2();
  digitalWrite(pin2A, LOW);
  digitalWrite(pin2B, LOW);
  digitalWrite(pin2C, HIGH);
  digitalWrite(pin2D, LOW);
  digitalWrite(pin2E, LOW);
  digitalWrite(pin2F, HIGH);
  digitalWrite(pin2G, LOW);
}

void d2n3(){
  reset2();
  digitalWrite(pin2A, LOW);
  digitalWrite(pin2B, LOW);
  digitalWrite(pin2C, LOW);
  digitalWrite(pin2D, LOW);
  digitalWrite(pin2E, HIGH);
  digitalWrite(pin2F, HIGH);
  digitalWrite(pin2G, LOW);
}

void d2n4(){
  reset2();
  digitalWrite(pin2A, HIGH);
  digitalWrite(pin2B, LOW);
  digitalWrite(pin2C, LOW);
  digitalWrite(pin2D, HIGH);
  digitalWrite(pin2E, HIGH);
  digitalWrite(pin2F, LOW);
  digitalWrite(pin2G, LOW);
}

void d2n5(){
  reset2();
  digitalWrite(pin2A, LOW);
  digitalWrite(pin2B, HIGH);
  digitalWrite(pin2C, LOW);
  digitalWrite(pin2D, LOW);
  digitalWrite(pin2E, HIGH);
  digitalWrite(pin2F, LOW);
  digitalWrite(pin2G, LOW);
}

void d2n6(){
  reset2();
  digitalWrite(pin2A, LOW);
  digitalWrite(pin2B, HIGH);
  digitalWrite(pin2C, LOW);
  digitalWrite(pin2D, LOW);
  digitalWrite(pin2E, LOW);
  digitalWrite(pin2F, LOW);
  digitalWrite(pin2G, LOW);
}

void d2n7(){
  reset2();
  digitalWrite(pin2A, LOW);
  digitalWrite(pin2B, LOW);
  digitalWrite(pin2C, LOW);
  digitalWrite(pin2D, HIGH);
  digitalWrite(pin2E, HIGH);
  digitalWrite(pin2F, HIGH);
  digitalWrite(pin2G, HIGH);
}

 void d2n8(){
  reset2();
  digitalWrite(pin2A, LOW);
  digitalWrite(pin2B, LOW);
  digitalWrite(pin2C, LOW);
  digitalWrite(pin2D, LOW);
  digitalWrite(pin2E, LOW);
  digitalWrite(pin2F, LOW);
  digitalWrite(pin2G, LOW);
}

 void d2n9(){
  reset2();
  digitalWrite(pin2A, LOW);
  digitalWrite(pin2B, LOW);
  digitalWrite(pin2C, LOW);
  digitalWrite(pin2D, LOW);
  digitalWrite(pin2E, HIGH);
  digitalWrite(pin2F, LOW);
  digitalWrite(pin2G, LOW);
}

ISR(TIMER1_OVF_vect){
  TCNT1 = 0xC2F7;
    display2++;
    switch(display2){
 case 10:
 display1++;
  display2=0;
  if(display1==10){
    display1=0;
  }
  break;
}
}

ISR(TIMER2_OVF_vect) {
  TCNT2 = 0;
      switch(display2){
      case 0:
      d2n0();
      break;
      case 1:
      d2n1();
      break;
      case 2:
      d2n2();
      break;
      case 3:
      d2n3();
      break;
      case 4:
      d2n4();
      break;
      case 5:
      d2n5();
      break;
      case 6:
      d2n6();
      break;
      case 7:
      d2n7();
      break;
      case 8:
      d2n8();
      break;
      case 9:
      d2n9();
      break; 
}
    switch(display1){
      case 0:
      d1n0();
      break;
      case 1:
      d1n1();
      break;
      case 2:
      d1n2();
      break;
      case 3:
      d1n3();
      break;
      case 4:
      d1n4();
      break;
      case 5:
      d1n5();
      break;
      case 6:
      d1n6();
      break;
      case 7:
      d1n7();
      break;
      case 8:
      d1n8();
      break;
      case 9:
      d1n9();
      break;
  }
delay(250);
}
