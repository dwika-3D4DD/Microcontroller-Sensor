int buzzer = 10;
int trigPin = 8;
int echoPin = 12;
int freq = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {

  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);

  int distance = duration / 58.2;

  delay(100);

  Serial.println(distance);

  if (distance < 290 && distance > 190) {
    for (int i = 0; i < 3; i++) {
      tone(buzzer, freq); // Send 1KHz sound signal...
      delay(500);        // ...for 1 sec
      noTone(buzzer);     // Stop sound...
      delay(10);        // ...for 1sec
      freq += 300;
    }
  } else if (distance < 190) {
    for (int i = 0; i < 5; i++) {
      tone(buzzer, freq); // Send 1KHz sound signal...
      delay(500);        // ...for 1 sec
      noTone(buzzer);     // Stop sound...
      delay(10);        // ...for 1sec
      freq += 500;
    }
  }
  freq = 1000;
}
