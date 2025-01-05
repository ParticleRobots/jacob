// jacob joy stick 
// this code reads the analog joy stick. 
//10/26 joystick control servo motor.
#include <Servo.h>
Servo motor;
Servo motor2;


int sensorUpDown = A2;
int sensorLeftRight = A4;
int sensorSwitch = 48;
int ValueUpDown = 0;
int ValueLeftRight = 0;
int ValueSwitch = 0;
int sensorpin = 0;

int sensorvalue = 0;


void setup() {
  // put your setup code here, to run once:
motor.attach(9);
motor2.attach(1);
Serial.begin(9600);
pinMode (sensorpin, INPUT_PULLUP);


}

void loop() {
  // put your main code here, to run repeatedly:
/*
motor.write(1);
delay(1000);
motor.write(121);
delay(1000);
*/
int mapvalue = 0;
ValueUpDown = analogRead(sensorUpDown);
mapvalue = map(ValueUpDown, 0, 1023, 0, 180);
motor.write(mapvalue);

int mapvalue2 = 0;
ValueLeftRight = analogRead(sensorLeftRight);
mapvalue2 = map(ValueLeftRight, 0, 1023, 0, 180);
motor2.write(mapvalue2);


sensorvalue = digitalRead(sensorpin);
Serial.print(sensorvalue);

delay(100);
print_joystick_information( );








}
void print_joystick_information( ){
 Serial.println (ValueUpDown);
if (ValueUpDown == 1023){
  Serial.println ("Joystick is up");
  
}
if (ValueUpDown == 0) {
  Serial.println ("Joystick is down");


} 
if (sensorvalue == 0) {
  Serial.println ("detected something");
}
}
