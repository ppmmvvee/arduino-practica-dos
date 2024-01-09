// Definición de pines para el botón y los LEDs
const int buttonPin = 2;
const int redLedPin = 9;
const int greenLedPin = 10;

int buttonPressCount = 0;//Inicializa una variable para contar las veces que se presiona el botón.
bool redLedState = false;//Inicializa una variable booleana para el estado del LED rojo (encendido o apagado).
bool greenLedState = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);//Configura el pin del botón como entrada con resistencia pull-up interna.
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  // Verificar si el botón ha sido presionado
  if (digitalRead(buttonPin) == LOW) {
    delay(50); 
    if (digitalRead(buttonPin) == LOW) {
      buttonPressCount++; //Incrementa el contador de pulsaciones del botón.
      
      // Controlar el comportamiento según la cantidad de veces que se presiona el botón
      if (buttonPressCount > 15) {
        bothLedsBlink();
      } else if (buttonPressCount > 10) {
        redLedOn();
      } else if (buttonPressCount >= 5 && buttonPressCount <= 10) {
        greenLedOn();
      }
    }
    while (digitalRead(buttonPin) == LOW) {//Espera hasta que se suelte el botón.
      delay(50); // Esperar hasta que se suelte el botón
    }
  }
}

// Encender el LED rojo y apagar el verde
void redLedOn() {
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
  redLedState = true;
  greenLedState = false;
}

// Encender el LED verde y apagar el rojo
void greenLedOn() {
  digitalWrite(greenLedPin, HIGH);
  digitalWrite(redLedPin, LOW);
  greenLedState = true;
  redLedState = false;
}

// Parpadear ambos LEDs
void bothLedsBlink() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, HIGH);
    delay(500);
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    delay(500);
  }
  redLedState = false;//Enciende el LED rojo y apaga el verde.
  greenLedState = false;//Enciende el LED verde y apaga el rojo.
  buttonPressCount = 0;//Parpadea ambos LEDs 4 veces.
}

