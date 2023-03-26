int s0 = 7;
int s1 = 6;
int s2 = 5;
int trigger = 2;
int echo = 4;
int distance = 0;
int duration = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (s0, OUTPUT);
  pinMode (s1, OUTPUT);
  pinMode (s2, OUTPUT);
  pinMode (trigger, OUTPUT);
  pinMode (echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  inputMultiplekser(0);
  digitalWrite (trigger, LOW);
  delayMicroseconds (2);
  digitalWrite (trigger, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigger, LOW);
  duration = pulseIn (echo, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Sensor 1 : ");
  Serial.print (distance);
  Serial.println (" cm");
  delay (1000);

  inputMultiplekser (1);
  digitalWrite (trigger, LOW);
  delayMicroseconds (2);
  digitalWrite (trigger, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigger, HIGH);
  duration = pulseIn (echo, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print ("Sensor 2: ");
  Serial.print (distance);
  Serial.println (" cm");
  delay (1000);
}
void inputMultiplekser (int y) {
  if (y == 0) {
    digitalWrite (s0, LOW);
    digitalWrite (s1, LOW);
    digitalWrite (s2, LOW);
  }
  else if (y == 1) {
    digitalWrite (s0, HIGH);
    digitalWrite (s1, LOW);
    digitalWrite (s2, LOW);
  }
  else if (y == 2) {
    digitalWrite (s0, LOW);
    digitalWrite (s1, HIGH);
    digitalWrite (s2, LOW);
  }
  else if (y == 3) {
    digitalWrite (s0, HIGH);
    digitalWrite (s1, HIGH);
    digitalWrite (s2, LOW);
  }
  else if (y == 4) {
    digitalWrite (s0, LOW);
    digitalWrite (s1, LOW);
    digitalWrite (s2, HIGH);
  }
  else if (y == 5) {
    digitalWrite (s0, HIGH);
    digitalWrite (s1, LOW);
    digitalWrite (s2, HIGH);
  }
  else if (y == 6) {
    digitalWrite (s0, LOW);
    digitalWrite (s1, HIGH);
    digitalWrite (s2, HIGH);
  }
  else if (y == 7) {
    digitalWrite (s0, HIGH);
    digitalWrite (s1, HIGH);
    digitalWrite (s2, HIGH);
  }
  else {
    digitalWrite (s0, LOW);
    digitalWrite (s1, LOW);
    digitalWrite (s2, LOW);
  }
}
