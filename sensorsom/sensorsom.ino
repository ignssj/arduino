int pinoLedBaixo = 11; //PINO DIGITAL UTILIZADO PELO LED
int pinoSensorBaixo = 3; //PINO DIGITAL UTILIZADO PELO SENSOR
int estadoSensorBaixo; //VARIÁVEL QUE ARMAZENA O ESTADO DA SAÍDA DO SENSOR (HIGH / LOW)
int pinoLedAlto = 12; 
int pinoSensorAlto = 4;
int estadoSensorAlto;

void setup(){
  pinMode(pinoSensorBaixo, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(pinoLedBaixo, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoSensorAlto, INPUT); 
  pinMode(pinoLedAlto, OUTPUT);
}

void loop(){
  if (digitalRead(pinoSensorBaixo) == HIGH){ //SE A LEITURA DO PINO FOR IGUAL A HIGH, FAZ
      estadoSensorBaixo = digitalRead(pinoLedBaixo); //LÊ O ESTADO ATUAL DO PINO E ARMAZENA NA VARIÁVEL
      digitalWrite(pinoLedBaixo, !estadoSensorBaixo); //MUDA O ESTADO ATUAL DO LED COMPARANDO COM O ESTADO
      //ARMAZENADO NA VARIÁVEL estadoSensor
      delay(500); //INTERVALO DE 500 MILISSEGUNDOS
  }
if (digitalRead(pinoSensorAlto) == HIGH){
      estadoSensorAlto = digitalRead(pinoLedAlto); 
      digitalWrite(pinoLedAlto, !estadoSensorAlto);
      delay(500);
}}
