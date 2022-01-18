int pinA = 10;
int pinB = 11;
int pinC = 7;
int pinD = 8;
int pinE = 9;
int pinF = 4;
int pinG = 5;
int pinDP = 6;
int  cont=0;

boolean ctrl = true;
boolean high = false;

void setup(){
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);     
  pinMode(A2, INPUT_PULLUP);    
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  attachInterrupt(0, direita, RISING);
  attachInterrupt(1, esquerda, RISING);
  // Configuração do timer1 
  TCCR1A = 0;                        //confira timer para operação normal pinos OC1A e OC1B desconectados
  TCCR1B = 0;                        //limpa registrador
  TCCR1B |= (1<<CS10)|(1 << CS12);   // configura prescaler para 1024: CS12 = 1 e CS10 = 1
  TCNT1 = 0xC2F7;                   
  TIMSK1 |= (1 << TOIE1);           // habilita a interrupção do TIMER1
  PCICR =13;    //ou 0x02;       // Enable PCINT1 interrupt PINOS de [28:23] ou PCINT[14:8] (Analogicos A0-A5) 
  PCMSK1 = 7; //ou 0b00000111;  // Seta a mascara para PCINT1 (PCINT0|PCINT1|PCINT2)
  sei();
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
  if(ctrl){
  switch(cont){
      case 0:
      letraH();
      blinkDP();
      cont++;
      TCNT1 = 0xC2F7;
  break;
      case 1:
      letraE();
      blinkDP();
      cont++;
      TCNT1 = 0xC2F7;
   break;
      case 2:
      letraL();
      blinkDP();
      cont++;
      TCNT1 = 0xC2F7;
    break;
      case 3:
      letraL();
      blinkDP();
      cont++;
      TCNT1 = 0xC2F7;
    break;
      case 4:
      letraO();
      blinkDP();
      cont++;
      TCNT1 = 0xC2F7;
    break;
      case 5:
      vazio();
      blinkDP();
      cont++;
      TCNT1 = 0xC2F7;
    break;
      case 6:
      letraA();
      blinkDP();
      cont++;
      TCNT1 = 0xC2F7;
    break;
      case 7:
      letraT();
      blinkDP();
      cont++;
      TCNT1 = 0xC2F7;
    break;
      case 8:
      n3();
      blinkDP();
      cont++;
      TCNT1 = 0xC2F7;
    break;
      case 9:
      n2();
      blinkDP();
      cont++;
      TCNT1 = 0xC2F7;
    break;
      case 10:
      n8();
      blinkDP();
      cont++;
      TCNT1 = 0xC2F7;
      break;
      case 11:
      letraP();
      blinkDP();
      cont++;
      TCNT1 = 0xC2F7;
    break;
      case 12:
      vazio();
      blinkDP();
      cont=0;
      TCNT1 = 0xC2F7;
  break;
  }}
  }

void direita(){
  switch(cont){
      case 0:
      letraH();
      blinkDP();
  break;
      case 1:
      letraE();
      blinkDP();
   break;
      case 2:
      letraL();
      blinkDP();
    break;
      case 3:
      letraL();
    blinkDP();
    break;
      case 4:
      letraO();
      blinkDP();
    break;
      case 5:
      vazio();
      blinkDP();
    break;
      case 6:
      letraA();
      blinkDP();
    break;
      case 7:
      letraT();
      blinkDP();
    break;
      case 8:
      n3();
      blinkDP();
    break;
      case 9:
      n2();
      blinkDP();
    break;
      case 10:
      n8();
      blinkDP();
    break;
      case 11:
    letraP();
      blinkDP();
    break;
      case 12:
      vazio();
      blinkDP();
  break;
  }
  if(cont != 12){
    cont++;
  }else{
    cont=0;
  }
}

void esquerda(){
  switch(cont){
      case 0:
      letraH();
      blinkDP();
  break;
      case 1:
      letraE();
      blinkDP();
   break;
      case 2:
      letraL();
      blinkDP();
    break;
      case 3:
      letraL();
    blinkDP();
    break;
      case 4:
      letraO();
      blinkDP();
    break;
      case 5:
      vazio();
      blinkDP();
    break;
      case 6:
      letraA();
      blinkDP();
    break;
      case 7:
      letraT();
      blinkDP();
    break;
      case 8:
      n3();
      blinkDP();
    break;
      case 9:
      n2();
      blinkDP();
    break;
      case 10:
      n8();
      blinkDP();
    break;
      case 11:
    letraP();
      blinkDP();
    break;
      case 12:
      vazio();
      blinkDP();
  break;
  }
  if(cont != 0){
    cont--;
  }else{
    cont=12;
  }
}

ISR(PCINT1_vect) {    // Interrupt service routine. Every single PCINT8..14 (=ADC0..5) change
  if (digitalRead(A0)==0)  ctrl=!ctrl;
}
