#include <Servo.h>
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

// Define melody and note durations
int melody[] = {
  NOTE_G4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_G3, NOTE_G3, NOTE_B3, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 8, 8, 8, 8, 4, 4
};

class Music {
private:
  int* melody;
  int* noteDurations;
  int numNotes;
  int tonePin;
  unsigned long previousMillis;
  unsigned long previousMillisPause;
  unsigned long interval;
  unsigned long pauseInterval;
  int thisNote;
  bool notePlaying;

public:
  // Constructor to initialize values
  Music(int* melodyArray, int* noteDurationsArray, int totalNotes, int pin) {
    melody = melodyArray;
    noteDurations = noteDurationsArray;
    numNotes = totalNotes;
    tonePin = pin;
    previousMillis = 0;
    previousMillisPause = 0;
    interval = 0;
    pauseInterval = 0;
    thisNote = 0;
    notePlaying = false;
  }

  // Method to update and play the melody
  void Update() {
    unsigned long currentMillis = millis(); // Get the current time

    // If a note isn't currently playing, start the next one
    if (!notePlaying && currentMillis - previousMillis >= interval) {
      // Calculate note duration based on its type
      interval = 1000 / noteDurations[thisNote]; // Note duration

      // Start playing the note
      tone(tonePin, melody[thisNote], interval);
      notePlaying = true; // Set flag to indicate note is playing
      previousMillis = currentMillis; // Update last note play time
    }

    // If the note is playing, check if it's time to stop the note
    if (notePlaying && currentMillis - previousMillis >= interval) {
      noTone(tonePin); // Stop the note
      notePlaying = false; // Clear the flag
      previousMillis = currentMillis; // Update the time when the note stops

      // Now handle the pause between notes
      if (currentMillis - previousMillisPause >= pauseInterval) {
        // Move to the next note
        thisNote++;
        if (thisNote >= numNotes) { // If end of melody, reset to start
          thisNote = 0;
        }
        // Calculate the pause time as 10% of the note duration (for the gap between notes)
        pauseInterval = interval * 0.1;
        previousMillisPause = currentMillis; // Update the pause timer
      }
    }
  }
};
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

class Sweeper
{
  Servo servo;              // the servo
  int pos;              // current servo position 
  int increment;        // increment to move for each interval
  int  updateInterval;      // interval between updates
  unsigned long lastUpdate; // last update of position

public: 
  Sweeper(int interval)
  {
    updateInterval = interval;
    increment = 1;
  }
  
  void Attach(int pin)
  {
    servo.attach(pin);
  }
  
  void Detach()
  {
    servo.detach();
  }
  
  void Update()
  {
    if((millis() - lastUpdate) > updateInterval)  // time to update
    {
      lastUpdate = millis();
      pos += increment;
      servo.write(pos);
      Serial.println(pos);
      if ((pos >= 180) || (pos <= 0)) // end of sweep
      {
        // reverse direction
        increment = -increment;
      }
    }
  }
};



Sweeper sweeper1(20);
Sweeper sweeper2(50);
//Sweeper sweeper3(100);

Ultrasonic sensor1( 2, 3, 500);
Ultrasonic sensor2( 4, 5, 1000);
//Ultrasonic sensor3( 6, 7, 20);

Music peppaPig(melody, noteDurations, 11, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sweeper1.Attach(9);
  sweeper2.Attach(10);
  //sweeper3.Attach(11);
   pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sweeper1.Update();
  sweeper2.Update();
  //sweeper3.Update();
  sensor1.Update();
  sensor2.Update();
  //sensor3.Update();
  peppaPig.Update();
}
