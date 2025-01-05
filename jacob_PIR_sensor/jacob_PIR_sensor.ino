//11/16/2024
//PIR sensor 
//Jacob PIR sensor

int sensor_detection = 0;
int sensor_pin = 1;
int sensor_led = 13;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("detecting...");
pinMode(sensor_pin, INPUT);
pinMode(sensor_led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
sensor_detection = digitalRead(sensor_pin);
Serial.println(sensor_detection);
delay(100);
}
