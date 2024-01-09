const int buttonPin = 12;          // Pin del botón
const int potentiometerPin = A0;  // Pin del potenciómetro
const int ledPins[] = {2, 4, 5, 6, 8};  // Pines de los 5 LEDs

int ledCount = 1;                  // Número inicial de LEDs encendidos
int lastButtonState = LOW;         // Estado anterior del botón
int currentButtonState = LOW;      // Estado actual del botón
int potValue = 0;                  // Valor del potenciómetro
int ledSpeed = 1000;               // Velocidad inicial de cambio de LED (en milisegundos)
unsigned long previousMillis = 0;  // Tiempo del último cambio de LED

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); //se declaran los pins y el potenciometro input de entrada
  pinMode(potentiometerPin, INPUT);
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Leer el estado del botón
  currentButtonState = digitalRead(buttonPin);

  // Cambiar el número de LEDs cuando se presiona el botón
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    ledCount = (ledCount % 5) + 1;  // Incrementar el número de LEDs (cíclico de 1 a 5)
    encenderAleatorios(ledCount);
  }

  // Actualizar el estado del botón
  lastButtonState = currentButtonState;

  // Leer el valor del potenciómetro
  potValue = analogRead(potentiometerPin);

  // Ajustar la velocidad de cambio de LED según el valor del potenciómetro
  ledSpeed = map(potValue, 0, 1023, 500, 2000);

  // Cambiar el LED cada segundo (o según la velocidad ajustada)
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= ledSpeed) {
    previousMillis = currentMillis;
    encenderAleatorio();
  }
}

void encenderAleatorio() {
  // Apagar todos los LEDs
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  // Encender un LED de forma aleatoria
  int randomLed = random(5);
  digitalWrite(ledPins[randomLed], HIGH);
}

void encenderAleatorios(int count) {
  // Apagar todos los LEDs
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  // Encender 'count' LEDs de forma aleatoria
  for (int i = 0; i < count; i++) {
    int randomLed = random(5);
    digitalWrite(ledPins[randomLed], HIGH);
  }
}
