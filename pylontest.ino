#include <Adafruit_NeoPixel.h>

#define PIN            6
#define NUMPIXELS      16
#define PULL_PY 1
#define PUSH_PY 0
#define SHORT_PY 4
#define RECESSED 3 //might be 2
#define ROT 2
#define IRLEDb 40
#define IRLEDr 42

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(9, 6, NEO_GRB + NEO_KHZ800);
byte inc;

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  for (int i = 0; i <= 9; i++) {
    pixels.setPixelColor(i, 255, 0, 0);
    pixels.show();
  }
  delay(100);
  for (int i = 0; i <= 9; i++) {
    pixels.setPixelColor(i, 0, 255, 0);
    pixels.show();
  }
  delay(100);
  for (int i = 0; i <= 9; i++) {
    pixels.setPixelColor(i, 0, 0, 255);
    pixels.show();
  }

  delay(100);
  for (int i = 0; i < 10; i++) {
    pixels.setPixelColor(i, 0, 200, 0);
    pixels.show();
    delay(10);
  }

  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(IRLEDb, OUTPUT);
  pinMode(IRLEDr, OUTPUT);
  Serial.begin(9600);
  boolean waiting = true;
  digitalWrite(IRLEDb, HIGH);
  digitalWrite(IRLEDr, HIGH);
  while (waiting)
  {
    if (Serial.available()) {

      if (Serial.read() == '1') {
        waiting = false;
        digitalWrite(IRLEDb, LOW);
        digitalWrite(IRLEDr, LOW);
      }
      else {
        pixels.setPixelColor(6, pixels.Color(255, 0, 0));
        pixels.setPixelColor(7, pixels.Color(255, 0, 0));
        pixels.setPixelColor(8, pixels.Color(255, 0, 0));
        pixels.setPixelColor(5, pixels.Color(255, 0, 0));
        pixels.show();
        Serial.write(Serial.read());
      }

    }
  }
  pixels.setPixelColor(5, pixels.Color(255, 0, 255));
  pixels.setPixelColor(6, pixels.Color(255, 0, 255));
  pixels.setPixelColor(7, pixels.Color(255, 0, 255));
  pixels.setPixelColor(8, pixels.Color(255, 0, 255));
  pixels.show();
  delay(100);
  pixels.setPixelColor(5, pixels.Color(0, 0, 0));
  pixels.setPixelColor(6, pixels.Color(0, 0, 0));
  pixels.setPixelColor(7, pixels.Color(0, 0, 0));
  pixels.setPixelColor(8, pixels.Color(0, 0, 0));
  pixels.show();
  delay(100);
  pixels.setPixelColor(5, pixels.Color(255, 0, 255));
  pixels.setPixelColor(6, pixels.Color(255, 0, 255));
  pixels.setPixelColor(7, pixels.Color(255, 0, 255));
  pixels.setPixelColor(8, pixels.Color(255, 0, 255));
  pixels.show();

}



void loop() {



  if (digitalRead(8) == HIGH)
  {
    pixels.setPixelColor(PULL_PY, pixels.Color(255, 0, 0));
    pixels.show();
    Serial.write((int)'R');
    Serial.write(8);
    Serial.println();

  }
  if (digitalRead(9) == HIGH)
  {
    pixels.setPixelColor(PULL_PY, pixels.Color(0, 0, 255));
    pixels.show();
    Serial.write((int)'B');
    Serial.write(8);
    Serial.println();


  }
  if (digitalRead(10) == LOW)
  {
    pixels.setPixelColor(PUSH_PY, pixels.Color(255, 0, 0));
    pixels.show();
    Serial.write((int)'R');
    Serial.write(7);
    Serial.println();

  }
  if (digitalRead(11) == LOW)
  {
    pixels.setPixelColor(PUSH_PY, pixels.Color(0, 0, 255));
    pixels.show();
    Serial.write((int)'B');
    Serial.write(7);
    Serial.println();

  }
  if (digitalRead(11) == LOW)
  {
    pixels.setPixelColor(PUSH_PY, pixels.Color(0, 0, 255));
    pixels.show();
    Serial.write((int)'B');
    Serial.write(7);
    Serial.println();

  }
  //Serial.println(analogRead(A0));
  //delay(10);
  if (analogRead(A8) > 500)//blue
  {
    pixels.setPixelColor(SHORT_PY, pixels.Color(255, 0, 0));
    pixels.show();
    Serial.write((int)'R');
    Serial.write(9);
    Serial.println();

  }

  if (analogRead(A9) > 500)
  {
    pixels.setPixelColor(SHORT_PY, pixels.Color(0, 0, 255));
    pixels.show();
    Serial.write((int)'B');
    Serial.write(9);
    Serial.println();

  }
  if (analogRead(A10) > 500)//blue
  {
    pixels.setPixelColor(RECESSED, pixels.Color(255, 0, 0));
    pixels.show();
    Serial.write((int)'R');
    Serial.write(10);
    Serial.println();
  }

  if (analogRead(A11) > 500)
  {
    pixels.setPixelColor(RECESSED, pixels.Color(0, 0, 255));
    pixels.show();
    Serial.write((int)'B');
    Serial.write(10);
    Serial.println();
  }
  if (digitalRead(26) == HIGH)
  {
    pixels.setPixelColor(ROT, pixels.Color(0, 0, 255));
    pixels.show();
    Serial.write((int)'B');
    Serial.write(11);
    Serial.println();

  }
  if (digitalRead(28) == HIGH)
  {
    pixels.setPixelColor(ROT, pixels.Color(255, 0, 0));
    pixels.show();
    Serial.write((int)'R');
    Serial.write(11);
    Serial.println();

  }
  /*if (analogRead(A1) > 500)
  {
    Serial.write((int)'B');
    Serial.write(12);
    Serial.println();
  }
  if (analogRead(A0) > 500)
  {
    Serial.write((int)'B');
    Serial.write(12);
    Serial.println();
  }*/

  if (Serial.available()) {
    inc = Serial.read();
    switch (inc) {
      case '3':
        digitalWrite(50, HIGH);
        digitalWrite(52, LOW);
        digitalWrite(51, HIGH);
        digitalWrite(53, LOW);
        Serial.println('3');
        break;
      case '4':
        digitalWrite(50, LOW);
        digitalWrite(52, HIGH);
        digitalWrite(53, HIGH);
        digitalWrite(51, LOW);
        Serial.println('4');
        break;
      case '5':
        digitalWrite(51, LOW);
        digitalWrite(53, LOW);
        digitalWrite(52, LOW);
        digitalWrite(54, LOW);
        Serial.println('5');
        break;
      case 80:
        pixels.setPixelColor(6, pixels.Color(0, 0, 255));
        pixels.setPixelColor(7, pixels.Color(0, 0, 255));
        pixels.setPixelColor(8, pixels.Color(0, 0, 255));
        pixels.setPixelColor(5, pixels.Color(0, 0, 255));
        pixels.show();
        break;
      case 90:
        pixels.setPixelColor(6, pixels.Color(255, 0, 0));
        pixels.setPixelColor(7, pixels.Color(255, 0, 0));
        pixels.setPixelColor(8, pixels.Color(255, 0, 0));
        pixels.setPixelColor(5, pixels.Color(255, 0, 0));
        break;
      default:
        break;
    }
    delay(1);
  }
}
