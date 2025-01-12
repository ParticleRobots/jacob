
//jacob 1/4/2025 ultrasonic sensor

int trig = 9;
int echo = 8;


float duration = 0;
float distance = 0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);


duration = pulseIn(echo, HIGH);

distance = 0.017 * duration;


delay(250);


if (distance > 500){
  Serial.println("ERROR");
} else{

  
Serial.print("distance: ");
Serial.print(distance);
Serial.println("cm");

  
}










}
