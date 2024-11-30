int sensorSom = 2; // Pino sensor de som
int led = 13; // Pino led
int contPalmas = 0; // Contador de Palmas
unsigned long tempMaxSom = 1000; // Tempo máximo entre o pulso seguinte
unsigned long tempMinSom = 300; // Tempo minimo entre o pulso seguinte
unsigned long compriSom = 100; // Comprimento do som esperado
unsigned long time;
unsigned long startTime = 0;

void setup() {
  pinMode(sensorSom, INPUT); // Inicia o pino do sensor como entrada
  pinMode(led, OUTPUT); // Inicia os pino do led como saída
  // Desliga led (o led é invertido HIGH desliga / LOW liga)
  digitalWrite(led, HIGH);
}
void loop() {

  // Inicia a contagem de tempo
  time = millis();
  // Verifica o tempo entre o pulso inicial e o seguinte
  unsigned long tempoAposPalma = time - startTime;
  if (tempoAposPalma >= compriSom && digitalRead(sensorSom) == LOW) {
    // Verifica se o pulso recebido respeita o intervalo
    if (tempoAposPalma < tempMinSom || tempoAposPalma > tempMaxSom) {
      // Caso não respeite reseta a contagem e o tempo
      contPalmas = 0;
      startTime = millis();
    }

    else {
      // Iniciada a contagem de pulso e o tempo
      contPalmas ++;
      startTime = millis();
    }
    // Verifica se a contagem de palma é igual a 1 e se o led esta desligado
    if ((contPalmas >= 1) && (digitalRead(led) == HIGH)) {
      // se led estiver desligado, Liga e zera a contagem
      digitalWrite(led, LOW);
      contPalmas = 0;
    }
    // Verifica se a contagem de palma é igual a 1 e se o led esta ligado
    if ((contPalmas >= 1) && (digitalRead(led) == LOW)) {
      // se led estiver ligado, desliga e zera a contagem
      digitalWrite(led, HIGH);
      contPalmas = 0;
    }
  }
}