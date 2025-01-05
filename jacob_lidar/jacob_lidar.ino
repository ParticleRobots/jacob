//Jacob lidar
#include <Servo.h>
Servo servo; 
Servo servo2;  
int pos = 0; 
int sensorpin = 0;
int sensorvalue = 0;

void setup() {
  // put your setup code here, to run once:
pinMode (sensorpin, INPUT_PULLUP);
Serial.begin(9600);
servo.attach(12);
servo2.attach(11);
}

void loop() {
  // put your main code here, to run repeatedly:
for (pos = 0; pos <= 90; pos+= 1) { 
  move_servos();
  detections();
}


for (pos = 90; pos >= 0; pos-=1) {
  move_servos();
  detections();
} 
}


// FUNCTIONS
//======================================
void move_servos(){
   servo.write(pos);
  delay(15);
  Serial.println(pos);
  servo2.write(pos);
}
void detections() {
  
if (sensorvalue == 1) {
  Serial.println ("detected something");
  
}
sensorvalue = digitalRead(sensorpin);
Serial.print(sensorvalue);
}
