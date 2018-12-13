#include "pixels.h"
#include "dataInput.h"
#include "christmasShow.h"
#include "whiteLight.h"

#define PIR_PIN 2
#define WHITE_PIN 4
#define RGB_PIN 5
#define NUMPIXELS 60

void setup() 
{
    Serial.begin(9600);
    pinMode(WHITE_PIN, OUTPUT);
    pinMode(PIR_PIN, INPUT_PULLUP);    

    attachInterrupt(digitalPinToInterrupt(PIR_PIN), intMotionDetected, FALLING);
        
    Serial.println("Rockin' around the christmas tree.");
    
    initPixels();
    lightOnNormal();
}

void loop() 
{
    if (Serial.available() > 0)
    {      
        String message = Serial.readString();
        
        Serial.print(message.length());
        Serial.print(": ");
        Serial.println(message);
    }

    checkReadyForAction();
    checkMotionSensor();
}

void intMotionDetected()
{
    motionDetected();
}
