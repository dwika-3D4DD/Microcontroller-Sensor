int pin_trig [4] = {2, 3, 4, 5};  //pin trig
int pin_echo [4] = {6, 7, 8, 9};  //pin echo

int SRFVal[4];  //array untuk nampung hasil jarak

boolean enable_belok = true;  //boolean agar belok dijalankan sekali pada loop

void setup() {
  //atur pinmode
  for (int i = 0; i < 4; i++) {
    pinMode(pin_trig[i], OUTPUT);
    pinMode(pin_echo[i], INPUT);
  }
  Serial.begin (9600);
}

void loop() {
  if (enable_belok)belok(1);
  
  //baca seluruh ultrasonic
  for (int i = 0; i < 4; i++) {
    delay(1000);
    readUltrasonic(i);
  }
  enable_belok = false;
}

void belok(int value) {
  for (int i = 0; i < 4; i++) {
    pin_trig[i] += value;
    pin_echo[i] += value;
    if (pin_trig[i] > 5) {
      pin_trig[i] -= 4;
      pin_echo[i] -= 4;
    }
  }
}

void readUltrasonic(int T) {
  digitalWrite(pin_trig[T], LOW);
  delayMicroseconds(2);
  digitalWrite(pin_trig[T], HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig[T], LOW);
  long duration = pulseIn(pin_echo[T], HIGH, 8000);
  SRFVal[T] = duration / 29.1 / 2;
  Serial.print("Hasil baca ultrasonic ");
  Serial.print(T);
  Serial.print(" : ");
  Serial.println(SRFVal[T]);
  
}
