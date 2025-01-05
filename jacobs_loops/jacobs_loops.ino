//jacob program about loops.
int i;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // put your main code here, to run repeatedly:
  // Serial.println("Hello World");

  int i;
  int j;


  for (i = 0; i < 5; i++) {
    Serial.println();
    while (j < 5) {
      Serial.print(j);
      j++;
    }
    j = 0;
  }



}

void loop() {





}
