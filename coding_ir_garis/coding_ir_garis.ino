int s0 = 21;
int s1 = 22;
int s2 = 23;
int y = 14;

int nilaiInput = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 1; i < 8 ; i+=2){
  inputMultiplexer(i);
  nilaiInput = analogRead (y);
  Serial.println (nilaiInput);
  delay (500);
}
}
  void inputMultiplexer (int y) {
//    if (y == 0) {
//      digitalWrite (s0, LOW);
//      digitalWrite (s1, LOW);
//      digitalWrite (s2, LOW);
//      Serial.print ("sensor 0 : ");
//    }
     if (y == 1) {
      digitalWrite (s0, HIGH);
      digitalWrite (s1, LOW);
      digitalWrite (s2, LOW);
      Serial.print ("sensor 1 : ");
  }
//    else if (y == 2) {
//      digitalWrite (s0, LOW);
//      digitalWrite (s1, HIGH);
//      digitalWrite (s2, LOW);
//      Serial.print ("sensor 2 : ");
//    }
    else if (y == 3) {
      digitalWrite (s0, HIGH);
      digitalWrite (s1, HIGH);
      digitalWrite (s2, LOW);
      Serial.print ("sensor 3 : ");
    }
//    else if (y == 4) {
//      digitalWrite (s0, LOW);
//      digitalWrite (s1, LOW);
//      digitalWrite (s2, HIGH);
//      Serial.print ("sensor 4 : ");
//    }
    else if (y == 5) {
      digitalWrite (s0, HIGH);
      digitalWrite (s1, LOW);
      digitalWrite (s2, HIGH);
      Serial.print ("sensor 5 : ");
    }
//    else if (y == 6) {
//      digitalWrite (s0, LOW);
//      digitalWrite (s1, HIGH);
//      digitalWrite (s2, HIGH);
//      Serial.print ("sensor 6 : ");
//    }
    else if (y == 7) {
      digitalWrite (s0, HIGH);
      digitalWrite (s1, HIGH);
      digitalWrite (s2, HIGH);
      Serial.print ("sensor 7 : ");
    }
//    else {
//      digitalWrite (s0, LOW);
//      digitalWrite (s1, LOW);
//      digitalWrite (s2, LOW);
//    }
  }
