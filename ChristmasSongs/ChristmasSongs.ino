#include "pitches.h"

#define BUZZER_PIN 8
#define SPEAKER_PIN 7
#define PIR_PIN 2

const String song1 = "song1";
const String song2 = "song2";
const String song3 = "song3";
const String mario1 = "mario";
const String mario2 = "underworld";

const int marioSong[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
const int marioTempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
//Underworld melody
const int underworldSong[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
const int underworldTempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

const int jingleBells[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

int tempo[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

// We wish you a merry Christmas

const int wish_melody[] = {
  NOTE_B3, 
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_G4, NOTE_E4,
  NOTE_F4
};

const int wish_tempo[] = {
  4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,
  2
};

// Santa Claus is coming to town

const int santa_melody[] = {
  NOTE_G4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
  NOTE_D4, NOTE_F4, NOTE_B3,
  NOTE_C4
};

const int santa_tempo[] = {
  8,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 2,
  4, 4, 4, 4,
  4, 2, 4,
  1
};

int melodyPin;

bool motionDisabled = false;
unsigned long timeWhenMotion = 0;
const unsigned long waitForMotion = 60000;

void setup() 
{
    Serial.begin(9600);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(SPEAKER_PIN, OUTPUT);
    pinMode(PIR_PIN, INPUT_PULLUP); 

    melodyPin = SPEAKER_PIN;        
    Serial.println("Rockin' around the christmas tree.");

    //attachInterrupt(digitalPinToInterrupt(PIR_PIN), intMotionDetected, FALLING);
}

void loop() 
{
    if (Serial.available() > 0)
    {      
        String message = Serial.readString();
        
        Serial.print(message.length());
        Serial.print(": ");
        Serial.println(message);
        
        if (message.indexOf(song1) >= 0)
            playSong(1);
        else if (message.indexOf(song2) >= 0)
            playSong(2);
        else if (message.indexOf(song3) >= 0)
            playSong(3);
        else if (message.indexOf(mario1) >= 0)
            playSong(4);
        else if (message.indexOf(mario2) >= 0)
            playSong(5);
    }

    if (digitalRead(PIR_PIN) == LOW)
        intMotionDetected();
    
    checkMotionSensor();
}

void checkMotionSensor()
{
    long timeWaited = (millis() - timeWhenMotion);    
    
    if ( timeWaited > waitForMotion )
    {
        //Serial.println("Ready for new motion");
        motionDisabled = false;
    }     
}

void intMotionDetected()
{
    if (motionDisabled == true)
    {
        long timeWaited = (millis() - timeWhenMotion);    
        
        Serial.print("Motion not yet enabled. Count down ");
        Serial.println(waitForMotion - timeWaited);
        return;
    }
    
    motionDisabled = true;

    int randSong = random(1, 5);
    Serial.print("Motion detected. Play song:");
    Serial.println(randSong);
    playSong(randSong);

    
    timeWhenMotion = millis();
}

void playSong(int songNumber)
{
    if (songNumber == 1)
    {
        Serial.println(" 'We wish you a Merry Christmas'");
        int size = sizeof(wish_melody) / sizeof(int);
        for (int thisNote = 0; thisNote < size; thisNote++) 
        {
            // to calculate the note duration, take one second
            // divided by the note type.
            //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
            int noteDuration = 1000 / wish_tempo[thisNote];

            buzz(melodyPin, wish_melody[thisNote], noteDuration);

            // to distinguish the notes, set a minimum time between them.
            // the note's duration + 30% seems to work well:
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);

            // stop the tone playing:
            buzz(melodyPin, 0, noteDuration);
        }

    }

    else if (songNumber == 2)
    {
        Serial.println(" 'Santa Claus is coming to town'");
        int size = sizeof(santa_melody) / sizeof(int);
        for (int thisNote = 0; thisNote < size; thisNote++) 
        {
            // to calculate the note duration, take one second
            // divided by the note type.
            //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
            int noteDuration = 900 / santa_tempo[thisNote];

            buzz(melodyPin, santa_melody[thisNote], noteDuration);

            // to distinguish the notes, set a minimum time between them.
            // the note's duration + 30% seems to work well:
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);

            // stop the tone playing:
            buzz(melodyPin, 0, noteDuration);
        }
    }
    else if (songNumber == 3)
    {
        Serial.println(" 'Jingle Bells'");
        int size = sizeof(jingleBells) / sizeof(int);
        for (int thisNote = 0; thisNote < size; thisNote++) 
        {
            // to calculate the note duration, take one second
            // divided by the note type.
            //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
            int noteDuration = 1000 / tempo[thisNote];

            buzz(melodyPin, jingleBells[thisNote], noteDuration);

            // to distinguish the notes, set a minimum time between them.
            // the note's duration + 30% seems to work well:
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);

            // stop the tone playing:
            buzz(melodyPin, 0, noteDuration);
        }
    }
    else if (songNumber == 5)
    {
        Serial.println(" 'Underworld Theme'");
        int size = sizeof(underworldSong) / sizeof(int);
        for (int thisNote = 0; thisNote < size; thisNote++) 
        {     
            // to calculate the note duration, take one second
            // divided by the note type.
            //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
            int noteDuration = 1000 / underworldTempo[thisNote];
            
            buzz(melodyPin, underworldSong[thisNote], noteDuration);
            
            // to distinguish the notes, set a minimum time between them.
            // the note's duration + 30% seems to work well:
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);
            
            // stop the tone playing:
            buzz(melodyPin, 0, noteDuration);
        }
    }
    else if (songNumber == 4)
    {
        Serial.println(" 'Mario Theme'");
        int size = sizeof(marioSong) / sizeof(int);
        for (int thisNote = 0; thisNote < size; thisNote++) 
        {
            // to calculate the note duration, take one second
            // divided by the note type.
            //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
            int noteDuration = 1000 / marioTempo[thisNote];
            
            buzz(melodyPin, marioSong[thisNote], noteDuration);
            
            // to distinguish the notes, set a minimum time between them.
            // the note's duration + 30% seems to work well:
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);
            
            // stop the tone playing:
            buzz(melodyPin, 0, noteDuration);
        }
    }
}

void buzz(int targetPin, long frequency, long length) 
{
    long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
    //// 1 second's worth of microseconds, divided by the frequency, then split in half since
    //// there are two phases to each cycle
    long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
    //// multiply frequency, which is really cycles per second, by the number of seconds to
    //// get the total number of cycles to produce
    for (long i = 0; i < numCycles; i++) 
    { // for the calculated length of time...
        digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
        delayMicroseconds(delayValue); // wait for the calculated delay value
        digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
        delayMicroseconds(delayValue); // wait again or the calculated delay value
    }
}
