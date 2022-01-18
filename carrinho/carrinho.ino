#include <Ultrasonic.h>
#define pino_trigger 4
#define pino_echo 5

const int motorDIR_RE  = 9;    // Pin  5 of L293.
const int motorDIR_FRENTE  = 3;    // Pin  6 of L293.
const int motorESQ_RE  = 11;   // Pin 10 of L293.
const int motorESQ_FRENTE  = 10;   // Pin 9 of L293.



// Variáveis Úteis
int i = 0;
int j = 0;
int state_rec;
int vSpeed = 250;
char state;
int correcoes=0;
int counter=0;
boolean ajuste=false;
float cmMsec;
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() {
  pinMode(motorDIR_RE, OUTPUT);
  pinMode(motorDIR_FRENTE, OUTPUT);
  pinMode(motorESQ_RE, OUTPUT);
  pinMode(motorESQ_FRENTE, OUTPUT);
  Serial.begin(9600);  
}

  void frente(){
    digitalWrite(motorESQ_RE, 0);
    digitalWrite(motorDIR_RE, 0);
    digitalWrite(motorDIR_FRENTE, HIGH);
    digitalWrite(motorESQ_FRENTE, HIGH);
  }

  void atras() { 
    digitalWrite(motorDIR_RE, 0);
    digitalWrite(motorESQ_RE, 0);
    digitalWrite(motorESQ_FRENTE, HIGH);
    digitalWrite(motorDIR_FRENTE, HIGH);
  }

  void esquerda(){   // Se o estado recebido for igual a 'L', o carro se movimenta para esquerda.
    digitalWrite(motorDIR_RE, 0);
    digitalWrite(motorDIR_FRENTE, HIGH);
    digitalWrite(motorESQ_RE, HIGH);
    digitalWrite(motorESQ_FRENTE, 0);
  }
  
  void direita(){   // Se o estado recebido for igual a 'R', o carro se movimenta para direita.
    digitalWrite(motorDIR_RE, HIGH);
    digitalWrite(motorDIR_FRENTE, 0);
    digitalWrite(motorESQ_RE, 0);
    digitalWrite(motorESQ_FRENTE, HIGH);
  }
  
 void para(){   // Se o estado recebido for igual a 'S', o carro permanece parado.
    digitalWrite(motorDIR_RE, 0);
    digitalWrite(motorDIR_FRENTE, 0);
    digitalWrite(motorESQ_RE, 0);
    digitalWrite(motorESQ_FRENTE, 0);
  }

void leitura(){
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
}

void loop() {
  leitura();
 // Serial.println(cmMsec);
  if(cmMsec <= 50 ){
    ajuste=true;
  }
  if(ajuste){    
        Serial.println("Mandei a direita");
        ajuste=false;
        esquerda();
        delay(400);
        para();
        delay(500);
        leitura();
         if(cmMsec <= 50){
         Serial.println("Mandei a esquerda");
         direita();
         delay(400);
         para();
         direita();
         delay(400);
         para();
        }
  }else{
    frente();
  }
  }
