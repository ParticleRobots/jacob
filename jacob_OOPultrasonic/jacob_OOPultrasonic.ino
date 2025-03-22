class Ultrasonic
{
  int trigPin;
  int echopin;
  float duration;
  float distance;
  unsigned long previousMillis;
   long interval;

public:
Ultrasonic(int trig, int echo, long i)
{
  
  duration = 0;
  distance = 0;
  echopin = echo;
  trigPin = trig;
  previousMillis = 0;
  interval = i;
  pinMode(trigPin, OUTPUT);
  pinMode(echopin, INPUT);
}

void Update()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echopin, HIGH);
    distance = 0.017 * duration;
  
  Serial.print("distance:");
  Serial.print(interval);
  Serial.print(":");
  Serial.print(distance);
  Serial.println("cm");
    
  }
}

};

Ultrasonic sensor1( 2, 3, 500);
Ultrasonic sensor2( 4, 5, 1000);
Ultrasonic sensor3( 6, 7, 20);



void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 sensor1.Update();
 sensor2.Update();
  sensor3.Update();
}
