#include <Arduino.h>
#include <math.h>

// ======================================================
//               PINOS - SENSOR TCS3200
// ======================================================
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// ======================================================
//                PINOS - MOTORES + PWM
// ======================================================

// Ponte H
#define MOTOR_A_IN1 10
#define MOTOR_A_IN2 11
#define MOTOR_B_IN1 12
#define MOTOR_B_IN2 13

// PWM
#define ENABLE_A 3
#define ENABLE_B 9

// Velocidade dos motores (0 - 255)
#define VELOCIDADE_MOTOR_A 90
#define VELOCIDADE_MOTOR_B 80

// ======================================================
//          BOTÃO/FIO USADO PARA ALTERAR ESTADO
// ======================================================

#define BUTTON 2

// ======================================================
//                      CORES
// ======================================================

#define red 0
#define green 1
#define blue 2

unsigned int rgb[3] = {0, 0, 0};

// Valores de calibração (guarda valor de cada cor pós calibração)
unsigned int red_color[3]   = {0, 0, 0};
unsigned int green_color[3] = {0, 0, 0};
unsigned int blue_color[3]  = {0, 0, 0};
unsigned int black_color[3] = {0, 0, 0};

// ======================================================
//                MÁQUINA DE ESTADOS
// ======================================================

int STATE = 0;
// (STATE = 0) - Calibrando vermelho 
// (STATE = 1) - Calibrando verde
// (STATE = 2) - Calibrando azul
// (STATE = 3) - Calibrando preto
// (STATE = 4) - Operando normalmente

// ======================================================
//                CONTROLE DE INTERRUPÇÃO
// ======================================================

volatile bool botaoPressionado = false; // Estado do botão
unsigned long ultimoTempoInterrupcao = 0; // Calcular se o tempo de espera entre interrupções foi atingido
const unsigned long tempoEspera = 500; // Tempo de espera entre interrupções


void setup() {
  Serial.begin(9600);

 
  // Configurar pino 2 como entrada com pull-up
  pinMode(BUTTON, INPUT_PULLUP);

  // Configurar interrupção hardware no pino 2 (falling edge - transição para LOW)
  attachInterrupt(digitalPinToInterrupt(BUTTON),trataInterrupcao,FALLING);

  // Configuração dos pinos do sensor TCS3200
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Frequência em 20% 
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Motores
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);

  pinMode(MOTOR_B_IN1, OUTPUT);
  pinMode(MOTOR_B_IN2, OUTPUT);

  // PWM
  pinMode(ENABLE_A, OUTPUT);
  pinMode(ENABLE_B, OUTPUT);

  parar();

  Serial.println("=================================");
  Serial.println("INICIANDO CALIBRACAO");
  Serial.println("Conecte/desconecte o fio no pino 2");
  Serial.println("=================================");
}

void loop() {
  // Verifica se o botão foi pressionado
  if (botaoPressionado) {
    botaoPressionado = false;
    
    if (STATE < 4) {
      // Imprime os valores calibrados
      printValoresCalibrados();
    }
  }

  // Operação normal do carrinho
  if (STATE == 4) {
    readRGB();
    decideAction();
  }
  
  delay(50);
}

// Função de Serviço de Interrupção (ISR)
void trataInterrupcao() {
  unsigned long tempoAtual = millis();
  if (tempoAtual - ultimoTempoInterrupcao > tempoEspera) {
    botaoPressionado = true;
    ultimoTempoInterrupcao = tempoAtual;
  }
}

void readRgbCalibration() {
  // Lê o valor vermelho
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  delay(10);
  
  // Atribui o valor da cor a partir do estado
  if (STATE == 0) {
    Serial.println("Calibrando VERMELHO");
    red_color[red] = pulseIn(sensorOut, LOW);
  } else if (STATE == 1) {
    Serial.println("Calibrando VERDE");
    green_color[red] = pulseIn(sensorOut, LOW);
  } else if (STATE == 2) {
    Serial.println("Calibrando AZUL");
    blue_color[red] = pulseIn(sensorOut, LOW);
  } else if (STATE == 3) {
    Serial.println("Calibrando PRETO");
    black_color[red] = pulseIn(sensorOut, LOW);
  }
  delay(10);

  // Lê o valor verde
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  delay(10);
   
  // Atribui o valor da cor a partir do estado
  if (STATE == 0) {
    red_color[green] = pulseIn(sensorOut, LOW);
  } else if (STATE == 1) {
    green_color[green] = pulseIn(sensorOut, LOW);
  } else if (STATE == 2) {
    blue_color[green] = pulseIn(sensorOut, LOW);
  } else if (STATE == 3) {
    black_color[green] = pulseIn(sensorOut, LOW);
  }
  delay(10);

  // Lê o valor azul
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  delay(10);
  
  // Atribui o valor da cor a partir do estado
  if (STATE == 0) {
    red_color[blue] = pulseIn(sensorOut, LOW);
  } else if (STATE == 1) {
    green_color[blue] = pulseIn(sensorOut, LOW);
  } else if (STATE == 2) {
    blue_color[blue] = pulseIn(sensorOut, LOW);
  } else if (STATE == 3) {
    black_color[blue] = pulseIn(sensorOut, LOW);
  }
  delay(10);

  STATE++;
}

void printValoresCalibrados() {
    Serial.println("Estado atual:");
    Serial.println(STATE);
    
    // FAZ a calibração aqui
    readRgbCalibration();
    
    delay(5000);
    Serial.println("Estado Após calibração:");
    Serial.println(STATE);
    Serial.println("VALORES(calibrados):");
    Serial.print("Red: ");
    Serial.print(red_color[0]);
    Serial.print(", ");
    Serial.print(red_color[1]);
    Serial.print(", ");
    Serial.println(red_color[2]);
    Serial.print("Green: ");
    Serial.print(green_color[0]);
    Serial.print(", ");
    Serial.print(green_color[1]);
    Serial.print(", ");
    Serial.println(green_color[2]);
    Serial.print("Blue: ");
    Serial.print(blue_color[0]);
    Serial.print(", ");
    Serial.print(blue_color[1]);
    Serial.print(", ");
    Serial.println(blue_color[2]);
    Serial.print("Black: ");
    Serial.print(black_color[0]);
    Serial.print(", ");
    Serial.print(black_color[1]);
    Serial.print(", ");
    Serial.println(black_color[2]);
}


// Leitura da porcentagem de cada cor em dada superfície
void readRGB() {

  // ---------------- RED ----------------
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  delay(10);

  rgb[red] = pulseIn(sensorOut, LOW);

  delay(10);

  // ---------------- GREEN ----------------
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  delay(10);

  rgb[green] = pulseIn(sensorOut, LOW);

  delay(10);

  // ---------------- BLUE ----------------
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  delay(10);

  rgb[blue] = pulseIn(sensorOut, LOW);

  delay(10);

  // Mostrar na tela
  Serial.print("R: ");
  Serial.print(rgb[red]);

  Serial.print("G: ");
  Serial.print(rgb[green]);

  Serial.print("B: ");
  Serial.println(rgb[blue]);
}


// Função que retorna a distância entre duas cores
float calcularDistancia(unsigned int cor1[3], unsigned int cor2[3]) {
  long soma = 0;
  for (int i = 0; i < 3; i++) {
    long diferenca = (long)cor1[i] - (long)cor2[i];
    soma += diferenca * diferenca;
  }
  return sqrt(soma);
}


// Controle dos Motores
// PRETO
void parar() {

  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, HIGH);

  digitalWrite(MOTOR_B_IN1, HIGH);
  digitalWrite(MOTOR_B_IN2, HIGH);

  analogWrite(ENABLE_A, VELOCIDADE_MOTOR_A);
  analogWrite(ENABLE_B, VELOCIDADE_MOTOR_B);
}

// VERDE
void irParaFrente() {

  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);

  digitalWrite(MOTOR_B_IN1, LOW);
  digitalWrite(MOTOR_B_IN2, HIGH);

  analogWrite(ENABLE_A, VELOCIDADE_MOTOR_A);
  analogWrite(ENABLE_B, VELOCIDADE_MOTOR_B);
}

// VERMELHO
void irParaDireita() {

  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);

  digitalWrite(MOTOR_B_IN1, HIGH);
  digitalWrite(MOTOR_B_IN2, HIGH);

  analogWrite(ENABLE_A, VELOCIDADE_MOTOR_A);
  analogWrite(ENABLE_B, VELOCIDADE_MOTOR_B);
}

// AZUL
void irParaEsquerda() {

  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, HIGH);

  digitalWrite(MOTOR_B_IN1, LOW);
  digitalWrite(MOTOR_B_IN2, HIGH);

  analogWrite(ENABLE_A, VELOCIDADE_MOTOR_A);
  analogWrite(ENABLE_B, VELOCIDADE_MOTOR_B);
}

// Processo de decisão do movimento com base na leitura do sensor de cores
void decideAction() {
  if (STATE != 4) {
    parar();
    return;
  }

  // Calcula distâncias para cada cor de referência
  float dist_vermelho = calcularDistancia(rgb, red_color);
  float dist_verde = calcularDistancia(rgb, green_color);
  float dist_azul = calcularDistancia(rgb, blue_color);
  float dist_preto = calcularDistancia(rgb, black_color);

  // Encontra a menor distância
  float menor_distancia = dist_vermelho;
  int cor_detectada = 0; // 0=vermelho, 1=verde, 2=azul, 3=preto

  if (dist_verde < menor_distancia) {
    menor_distancia = dist_verde;
    cor_detectada = 1;
  }
  if (dist_azul < menor_distancia) {
    menor_distancia = dist_azul;
    cor_detectada = 2;
  }
  if (dist_preto < menor_distancia) {
    menor_distancia = dist_preto;
    cor_detectada = 3;
  }

  // Executa ações baseado na cor detectada
  switch (cor_detectada) {
    case 0: // Vermelho
      Serial.println("Vermelho detectado - (Direita)");
      irParaDireita();
      delay(120);
      irParaFrente();
      break;
      
    case 1: // Verde
      Serial.println("Verde detectado - (Frente)");
      irParaFrente();
      break;
      
    case 2: // Azul
      Serial.println("Azul detectado - (Esquerda)");
      irParaEsquerda();
      delay(120);
      irParaFrente();
      break;
      
    case 3: // Preto
      Serial.println("Preto detectado - (Parar)");
      parar();
      break;
  }
}
