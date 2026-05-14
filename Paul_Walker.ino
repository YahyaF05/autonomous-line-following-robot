int LS = 2; 
int RS = 3; 
int LM1 = 6; 
int LM2 = 7; 
int RM1 = 4; 
int RM2 = 5; 

int trigPin = 8;
int echoPin = 9;

int leftSpeed = 250; 
int rightSpeed = 250; 

static bool isBlocked = false;

void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // 1. Check Distance
  long distance = getAverageDistance();

  // 2. Braking Logic (25cm Stop / 30cm Resume)
  if (distance > 0 && distance <= 15) { 
    isBlocked = true;
  } 
  else if (distance > 30 || distance == 0) { 
    isBlocked = false;
  }

  if (isBlocked) {
    stopMotors();
  } 
  else {
    // 3. Pulse Movement Phase (Brings back controlled speed)
    if(!(digitalRead(LS)) && !(digitalRead(RS))) {
      // Both Forward
      analogWrite(LM1, leftSpeed);
      digitalWrite(LM2, LOW);
      analogWrite(RM1, rightSpeed);
      digitalWrite(RM2, LOW);
    }
    else if(digitalRead(LS) && !(digitalRead(RS))) {
      // Pivot Turn Right: Left forward, Right STOPPED
      analogWrite(LM1, leftSpeed);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW); 
      digitalWrite(RM2, LOW); 
    }
    else if(!(digitalRead(LS)) && digitalRead(RS)) {
      // Pivot Turn Left: Right forward, Left STOPPED
      digitalWrite(LM1, LOW); 
      digitalWrite(LM2, LOW); 
      analogWrite(RM1, rightSpeed);
      digitalWrite(RM2, LOW);
    }
    else {
      stopMotors();
    }

    // --- PULSE LOGIC CONTROL ---
    // This creates the "burst" movement to keep the car's speed manageable
    delay(35);        // Move for 30 milliseconds
    stopMotors();     // Stop briefly
    delay(5);        // Rest for 10 milliseconds
  }
}

long getAverageDistance() {
  long sum = 0;
  for(int i = 0; i < 2; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH, 20000); 
    sum += (duration / 2) / 29.1;
  }
  return sum / 2;
}

void stopMotors() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}
