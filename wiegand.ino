const int data0 = 0; // Interrupt 0, digital pin 2
const int data1 = 1; // Interrupt 1, digital pin 3

volatile long readerdata = 0;

void setup() {
  attachInterrupt(data0, readerdata0, CHANGE);
  attachInterrupt(data1, readerdata1, CHANGE);
  Serial.begin(9600);
  Serial.println("\n--Ready--");
}

void readerdata0() {
  int status = digitalRead(data0+2);
  if (status == LOW)
    readerdata = readerdata << 1;
  else if (digitalRead(data1+2) == HIGH) {
    Serial.print(readerdata, BIN);
    readerdata = 0;
  }
}

void readerdata1() {
  int status = digitalRead(data1+2);
  if (status == LOW)
    readerdata = (readerdata << 1) | 1;
  else if (digitalRead(data0+2) == HIGH) {
    Serial.print(readerdata, BIN);
    readerdata = 0;
  }
}

void loop() {}
