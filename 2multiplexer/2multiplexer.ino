int s0 = 7;
int s1 = 6;
int s2 = 5;

const int trig = 2;
const int echo = 4;
int dist = 0;
long duration = 0;

void setup() {
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}
void loop() {
  inputMultiplekser(0);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  dist = duration * 0.034 / 2;
  Serial.print("Sensor 1 :");
  Serial.print(dist);
  Serial.println(" cm");
  delay(1000);

  inputMultiplekser(1);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  dist = duration * 0.034 / 2;
  Serial.print("Sensor 2 : ");
  Serial.print(dist);
  Serial.println(" cm");
  delay(1000);
}

void inputMultiplekser(int y) {
  if (y == 0) {
    digitalWrite(s0, LOW);
    digitalWrite(s1, LOW);
    digitalWrite(s2, LOW);
  }
  else if (y == 1) {
    digitalWrite(s0, HIGH);
    digitalWrite(s1, LOW);
    digitalWrite(s2, LOW);
  }
  else if (y == 2) {
    digitalWrite(s0, LOW);
    digitalWrite(s1, HIGH);
    digitalWrite(s2, LOW);
  }
  else if (y == 3) {
    digitalWrite(s0, HIGH);
    digitalWrite(s1, HIGH);
    digitalWrite(s2, LOW);
  }
  else if (y == 4) {
    digitalWrite(s0, LOW);
    digitalWrite(s1, LOW);
    digitalWrite(s2, HIGH);
  }
  else if (y == 5) {
    digitalWrite(s0, HIGH);
    digitalWrite(s1, LOW);
    digitalWrite(s2, HIGH);
  }
  else if (y == 6) {
    digitalWrite(s0, LOW);
    digitalWrite(s1, HIGH);
    digitalWrite(s2, HIGH);
  }
  else if (y == 7) {
    digitalWrite(s0, HIGH);
    digitalWrite(s1, HIGH);
    digitalWrite(s2, HIGH);
  }
  //jika input bukan 0-7, maka jadikan saja y0
  else {
    digitalWrite(s0, LOW);
    digitalWrite(s1, LOW);
    digitalWrite(s2, LOW);
  }
}
