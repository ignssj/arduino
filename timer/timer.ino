int pinA = 10;
int pinB = 11;
int pinC = 7;
int pinD = 8;
int pinE = 9;
int pinF = 4;
int pinG = 5;
int pinDP = 6;
int  cont=0;

boolean high = false;

void setup(){
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  TCCR1A = 0;                        //confira timer para operação normal pinos OC1A e OC1B desconectados
  TCCR1B = 0;                        //limpa registrador
  TCCR1B |= (1<<CS10)|(1 << CS12);   // configura prescaler para 1024: CS12 = 1 e CS10 = 1
  TCNT1 = 0xC2F7;                   
  TIMSK1 |= (1 << TOIE1);           // habilita a interrupção do TIMER1
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

ISR(TIMER1_OVF_vect){
  switch(cont){
      case 0:
      letraH();
      blinkDP();
      TCNT1 = 0xC2F7;
  break;
      case 1:
      letraE();
      blinkDP();
      TCNT1 = 0xC2F7;
   break;
      case 2:
      letraL();
      blinkDP();
      TCNT1 = 0xC2F7;
    break;
      case 3:
      letraL();
      blinkDP();
      TCNT1 = 0xC2F7;
    break;
      case 4:
      letraO();
      blinkDP();
      TCNT1 = 0xC2F7;
    break;
      case 5:
      vazio();
      blinkDP();
      TCNT1 = 0xC2F7;
    break;
      case 6:
      letraA();
      blinkDP();
      TCNT1 = 0xC2F7;
    break;
      case 7:
      letraT();
      blinkDP();
      TCNT1 = 0xC2F7;
    break;
      case 8:
      n3();
      blinkDP();
      TCNT1 = 0xC2F7;
    break;
      case 9:
      n2();
      blinkDP();
      TCNT1 = 0xC2F7;
    break;
      case 10:
      n8();
      blinkDP();
      TCNT1 = 0xC2F7;
      break;
      case 11:
      letraP();
      blinkDP();
      TCNT1 = 0xC2F7;
    break;
      case 12:
      vazio();
      blinkDP();
      TCNT1 = 0xC2F7;
  break;
  }
  if(cont!=12){
    cont++;
  }else{
    cont=0;
  }
  }
