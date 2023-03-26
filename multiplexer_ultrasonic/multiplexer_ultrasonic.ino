int echoPin = 2 ;//Echo Pin
int trigPin = 3 ;//Trigger Pin

int s0 = 4;
int s1 = 5;
int s2 = 6;

float arr [8];

void setup() {
  // put your setup code here, to run once:
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
}

void loop() {

  for (int i = 0; i < 8 ; i++) {
    inputMultiplexer(i, i);
    arr [i] = readUltra();
    Serial.println (arr[i]);
    delay (500);
  }
}
void inputMultiplexer (int y, int x) {
  if (y == 0 && x == 0) {
    digitalWrite (s0, LOW);
    digitalWrite (s1, LOW);
    digitalWrite (s2, LOW);
    Serial.print ("sensor 0 : ");
  }
  if (y == 1 && x == 1) {
    digitalWrite (s0, HIGH);
    digitalWrite (s1, LOW);
    digitalWrite (s2, LOW);
    Serial.print ("sensor 1 : ");
  }
  if (y == 2 && x == 2) {
    digitalWrite (s0, LOW);
    digitalWrite (s1, HIGH);
    digitalWrite (s2, LOW);
    Serial.print ("sensor 2 : ");
  }
  if (y == 3 && x == 3) {
    digitalWrite (s0, HIGH);
    digitalWrite (s1, HIGH);
    digitalWrite (s2, LOW);
    Serial.print ("sensor 3 : ");
  }
    if (y == 4 && x == 4) {
    digitalWrite (s0, LOW);
    digitalWrite (s1, LOW);
    digitalWrite (s2, HIGH);
    Serial.print ("sensor 4 : ");
  }
    if (y == 5 && x == 5) {
    digitalWrite (s0, HIGH);
    digitalWrite (s1, LOW);
    digitalWrite (s2, HIGH);
    Serial.print ("sensor 5 : ");
  }
    if (y == 6 && x == 6) {
    digitalWrite (s0, LOW);
    digitalWrite (s1, HIGH);
    digitalWrite (s2, HIGH);
    Serial.print ("sensor 6 : ");
  }
    if (y == 7 && x == 7) {
    digitalWrite (s0, HIGH);
    digitalWrite (s1, HIGH);
    digitalWrite (s2, HIGH);
    Serial.print ("sensor 7 : ");
  }
}
float readUltra () {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  float dist = duration / 29 / 2;

  return dist;
}
