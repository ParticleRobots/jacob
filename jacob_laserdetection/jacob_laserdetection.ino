int sensor_detection = 0;
int sensor_pin = A5;
int sensor_led = 13;
int sensor_speaker = 8;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("detecting...");
pinMode(sensor_pin, INPUT);
pinMode(sensor_led, OUTPUT);
pinMode(sensor_speaker, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sensor_detection = analogRead(sensor_pin);
Serial.println(sensor_detection);
// range 200 to 496
if ((sensor_detection >= 200) and (sensor_detection <= 1023)){
  Serial.println("detection");
  digitalWrite(sensor_speaker, HIGH);
}
if ((sensor_detection <= 50)){
  Serial.println("detected nothing");
  digitalWrite(sensor_speaker, LOW);
}
delay(100);
}
