#define NUM_LEDS 5
#define LEFT_BUTTON_PIN 7
#define RIGHT_BUTTON_PIN 8

int ledPins[NUM_LEDS] = {2, 3, 4, 5, 6};
int currentLed = 2;

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(LEFT_BUTTON_PIN, INPUT);
  pinMode(RIGHT_BUTTON_PIN, INPUT);

  digitalWrite(ledPins[currentLed], HIGH);
}

void loop() {
  if (digitalRead(LEFT_BUTTON_PIN) == LOW) {
    digitalWrite(ledPins[currentLed], LOW);
    currentLed--;
    if (currentLed < 0) {
      currentLed = NUM_LEDS - 1;
      blinkAll(4);
    }
    blink(ledPins[currentLed], 3);
  }

  if (digitalRead(RIGHT_BUTTON_PIN) == LOW) {
    digitalWrite(ledPins[currentLed], LOW);
    currentLed++;
    if (currentLed >= NUM_LEDS) {
      currentLed = 0;
      blinkAll(4);
    }
    blink(ledPins[currentLed], 3);
  }
}

void blink(int pin, int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
    delay(500);
  }
  digitalWrite(pin, HIGH);
}

void blinkAll(int times) {
  for (int i = 0; i < times; i++) {
    for (int j = 0; j < NUM_LEDS; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(500);
    for (int j = 0; j < NUM_LEDS; j++) {
      digitalWrite(ledPins[j], LOW);
    }
    delay(500);
  }
}