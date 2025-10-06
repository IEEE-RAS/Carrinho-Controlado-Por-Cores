#include <Arduino.h>

// Defina os pinos para o sensor TCS3200
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

//pinos de controle dos motores de mesmo PWM
#define MOTOR_A_IN1 13 // D3
#define MOTOR_A_IN2 12 // D5
#define MOTOR_B_IN1 10 // D6
#define MOTOR_B_IN2 11 // D9
#define ENABLE_A 3
#define ENABLE_B 9
#define VELOCIDADE 100

//define o valor pra cada cor nos pinos
#define red 0
#define green 1
#define blue 2


unsigned int rgb[] = {0,0,0};


void setup() {
  Serial.begin(9600);
  
  // Configuração dos pinos do sensor TCS3200
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Configuração dos pinos da ponte H
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_B_IN1, OUTPUT);
  pinMode(MOTOR_B_IN2, OUTPUT);
  pinMode(ENABLE_A, OUTPUT);
  pinMode(ENABLE_B, OUTPUT);
  
  // Inicialmente, ambos os motores estao parados
  parar();
}

void loop() {
  // Lê os valores RGB
  readRGB();
  
  // Decide a ação com base nos valores RGB
  decideAction();
  
  delay(25); // Pode ajustar este delay conforme necessário
}

void readRGB() {
  // Lê o valor vermelho
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  rgb[red] = pulseIn(sensorOut, LOW);
  delay(10);

  // Lê o valor verde
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  rgb[green] = pulseIn(sensorOut, LOW);
  delay(10);

  // Lê o valor azul
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  rgb[blue] = pulseIn(sensorOut, LOW);
  delay(10);

  // Imprime os valores RGB no monitor serial
  Serial.print("R: ");
  Serial.print(rgb[red]);
  Serial.print("\tG: ");
  Serial.print(rgb[green]);
  Serial.print("\tB: ");
  Serial.println(rgb[blue]);
}

void parar() {
  // motor 1: parar
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, HIGH);
  //motor 2: parar
  digitalWrite(MOTOR_B_IN1, HIGH);
  digitalWrite(MOTOR_B_IN2, HIGH);

  // Velocidade dos motores em ~35%
  analogWrite(ENABLE_A, VELOCIDADE);
  analogWrite(ENABLE_B, VELOCIDADE);
}

void irParaFrente() {
  // motor 1: ligar
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  //motor 2: ligar
  digitalWrite(MOTOR_B_IN1, LOW);
  digitalWrite(MOTOR_B_IN2, HIGH);

  // Velocidade dos motores em ~35%
  analogWrite(ENABLE_A, VELOCIDADE);
  analogWrite(ENABLE_B, VELOCIDADE);
}

void irParaDireita() {
  // motor 1: ligar
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  //motor 2: parar
  digitalWrite(MOTOR_B_IN1, HIGH);
  digitalWrite(MOTOR_B_IN2, HIGH);

  // Velocidade dos motores em ~35%
  analogWrite(ENABLE_A, VELOCIDADE);
  analogWrite(ENABLE_B, VELOCIDADE);
}

void irParaEsquerda() {
  // motor 1: parar
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, HIGH);
  //motor 2: ligar
  digitalWrite(MOTOR_B_IN1, LOW);
  digitalWrite(MOTOR_B_IN2, HIGH);

  // Velocidade dos motores em ~35%
  analogWrite(ENABLE_A, VELOCIDADE);
  analogWrite(ENABLE_B, VELOCIDADE);
}

void decideAction() {
  if ((rgb[red] > 120 && rgb[green] > 110 && rgb[blue] > 60) || (rgb[red] < 30 && rgb[green] < 30 && rgb[blue] < 30)) {
  // Preto: Parar
  Serial.println("Preto");
  parar();
  
  } 

  //azul entre 35 e 50
  else if (rgb[blue] >= 35 && rgb[blue] <= 50) {
    // Azul: Vai para a esquerda
    Serial.println("Azul");
    irParaEsquerda();
    delay(120);  // Vira por 500ms. Ajuste conforme necessário.
    irParaFrente();
    delay(10);
  }

  //verde entre 60 e 95
  else if (rgb[green] >= 60 && rgb[green] <= 95) {
    Serial.println("Verde");
    // Verde: Vai para frente
    irParaFrente();
  }
  
  //vermelho entre 30 e 60
  else if (rgb[red] >= 30 && rgb[red] <= 60) {
    // Vermelho: Vai para a direita
    Serial.println("Vermelho");
    irParaDireita();
    delay(120);  // Vira por 500ms. Ajuste conforme necessário.
    irParaFrente();
    delay(10);
  } 
}
