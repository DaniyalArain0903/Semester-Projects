int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int led8 = 8;   // extra blue LED
int led7 = 7;   // new LED

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led7, OUTPUT);
}

// Turn all OFF
void allOff() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led7, LOW);
}

// Blink function
void blink(bool r, bool g, bool b, bool e8, bool e7) {
  digitalWrite(redPin, r);
  digitalWrite(greenPin, g);
  digitalWrite(bluePin, b);
  digitalWrite(led8, e8);
  digitalWrite(led7, e7);

  delay(2000);   // ON

  allOff();
  delay(2000);   // OFF

  delay(4000);   // GAP
}

void loop() {

  // 🔴🟢 Red + Green
  blink(HIGH, HIGH, LOW, LOW, LOW);

  // 🟢🔵 Green + Blue
  blink(LOW, HIGH, HIGH, LOW, LOW);

  // 🔵🔴 Blue + Red
  blink(HIGH, LOW, HIGH, LOW, LOW);

  // 🔵🔴 Combination of pin 8 + pin 7  ✅ (your request)
  blink(LOW, LOW, LOW, HIGH, HIGH);

  // ⚪ All LEDs
  blink(HIGH, HIGH, HIGH, LOW, LOW);
}