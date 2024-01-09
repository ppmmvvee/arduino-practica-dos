const int sensorPin = A0; // Pin analógico donde está conectado el sensor
const int outputPins[] = {9, 10, 11}; // Pines de salida (ajusta según tu configuración)

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(outputPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Valor del sensor: ");
  Serial.println(sensorValue);

  if (sensorValue >= 0 && sensorValue <= 500) {
    // Secuencia #1
    sequence1();
  } else if (sensorValue > 500 && sensorValue <= 1000) {
    // Secuencia #2
    sequence2();
  }

  delay(1000); // Puedes ajustar el tiempo de espera entre lecturas si es necesario
}

void sequence1() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(outputPins[i], HIGH);
    delay(1000);
  }

  for (int i = 0; i < 3; i++) {
    digitalWrite(outputPins[i], LOW);
  }
}

void sequence2() {
  for (int i = 2; i >= 0; i--) {
    digitalWrite(outputPins[i], HIGH);
    delay(1000);
    digitalWrite(outputPins[i], LOW);
  }
}
