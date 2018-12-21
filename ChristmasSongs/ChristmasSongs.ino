#include "pitches.h"

#define BUZZER_PIN 8
#define SPEAKER_PIN 7
#define RGB_PIN 5
#define NUMPIXELS 60

const String song1 = "song1";
const String song2 = "song2";
const String song3 = "song3";

int jingleBells[] = {
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

int wish_melody[] = {
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

int wish_tempo[] = {
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

int santa_melody[] = {
  NOTE_G4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
  NOTE_D4, NOTE_F4, NOTE_B3,
  NOTE_C4
};

int santa_tempo[] = {
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
void setup() 
{
    Serial.begin(9600);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(SPEAKER_PIN, OUTPUT);

    melodyPing = SPEAK_PIN;        
    Serial.println("Rockin' around the christmas tree.");
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
    }
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
