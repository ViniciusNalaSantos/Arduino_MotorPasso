// Código para controlar motor de passo sem usar biblioteca
// Arduino Uno

# define pinoBobina1 3 // Essa linha apelida pino 3 como "pinoBobina1" 
# define pinoBobina2 4 // idem
# define pinoBobina3 5 // idem
# define pinoBobina4 6 // idem

int intervaloEntreBobinasMs=50; // declaração global de variável do tipo inteira

void setup() {
  Serial.begin(115200);            // iniciando a comunicação serial da porta USB 115200 bits por seg
  pinMode(pinoBobina1, OUTPUT);    // define o comportamento do respectivo pino. Nesse caso, saída
  pinMode(pinoBobina2, OUTPUT);
  pinMode(pinoBobina3, OUTPUT);
  pinMode(pinoBobina4, OUTPUT);
  digitalWrite(pinoBobina1, HIGH); // aqui estamos iniciando o motor no desligado (HIGH = desligado, LOW = ligado)
  digitalWrite(pinoBobina2, HIGH);
  digitalWrite(pinoBobina3, HIGH);
  digitalWrite(pinoBobina4, HIGH); 
}

void loop() {
  for (int i = 0; i < 4096;) { // Essa rotina faz um giro de 360° no eixo do motor.
    // Quantas iterações ter para girar 360°?
    // Primeiro, descubra o passo do motor. Para o motor azul, passo: 5,625° além de possuir uma caixa de redução de 1/64.
    // Portanto, o passo final: 5,625/64 = 0,08789°.
    // Considerando que vamos energizar as bobinas no modo half-step (vai parar entre bobinas).
    // Então: 0,08789° (passo half-step)
    // então, quantos passos full-step são necessários para 360°?
    // N = 360 / 0,08789 = 4096
    // *i++ é o mesmo que i=i+1

    // Para ter um torque elevado, acionamos duas bobinas por ciclo

    digitalWrite(pinoBobina1, LOW);
    delay(intervaloEntreBobinasMs);
    i++;
    Serial.println("Passo:");
    Serial.println(i);
    digitalWrite(pinoBobina4, HIGH);
    delay(intervaloEntreBobinasMs);
    i++;
    Serial.println("Passo:");
    Serial.println(i);
    digitalWrite(pinoBobina2, LOW);
    delay(intervaloEntreBobinasMs);
    i++;
    Serial.println("Passo:");
    Serial.println(i);
    digitalWrite(pinoBobina1, HIGH);
    delay(intervaloEntreBobinasMs);
    i++;
    Serial.println("Passo:");
    Serial.println(i);
    digitalWrite(pinoBobina3, LOW);
    delay(intervaloEntreBobinasMs);
    i++;
    Serial.println("Passo:");
    Serial.println(i);
    digitalWrite(pinoBobina2, HIGH);
    delay(intervaloEntreBobinasMs);
    i++;
    Serial.println("Passo:");
    Serial.println(i);
    digitalWrite(pinoBobina4, LOW);
    delay(intervaloEntreBobinasMs);
    i++;
    Serial.println("Passo:");
    Serial.println(i);
    digitalWrite(pinoBobina3, HIGH);
    delay(intervaloEntreBobinasMs);
    i++;
    Serial.println("Passo:");
    Serial.println(i);
  }
  delay(1000); // Quando der 360° ele para por 1 segundo (1000 ms = 1 s).
}
