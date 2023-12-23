#ifdef ARDUINO
    #include <Adafruit_NeoPixel.h>
#else
  #include <../libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.h>
  #include "C:/Users/jorge/AppData/Local/Arduino15/packages/arduino/hardware/avr/1.8.6/cores/Arduino.h"
#endif

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define WHITE_PIN 3
#define RGB_PIN 4
#define NUMPIXELS 60
#define PIR_SENSOR 5

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800);

typedef struct rgbColors
{
    char r;
    char g;
    char b;    
} rgbColor;

rgbColor rgbOff, rgbRed, rgbGreen, rgbBlue;

#define INIT_WAIT_PERIOD 200

void setup() {
    Serial.begin(9600);
    pinMode(WHITE_PIN, OUTPUT);
    pinMode(PIR_SENSOR, INPUT);
    Serial.println("Rockin' around the christmas tree December 2023.");

    pixels.begin(); // This initializes the NeoPixel library.
    initColors();
    colorOff();

    analogWrite(WHITE_PIN, 255);
    Serial.println("Light");
    delay(INIT_WAIT_PERIOD);
    analogWrite(WHITE_PIN, 0);
    colorOff();

    redOn();
    Serial.println("Red");
    delay(INIT_WAIT_PERIOD);
    colorOff();

    greenOn();
    Serial.println("Green");
    delay(INIT_WAIT_PERIOD);
    colorOff();

    blueOn();
    Serial.println("Blue");
    delay(INIT_WAIT_PERIOD);
    colorOff();
    delay(INIT_WAIT_PERIOD);
    Serial.println("We're ready to go!");
}

bool isMotionDetected()
{
  byte pirSensor = digitalRead(PIR_SENSOR);
  if (pirSensor > 0)
    return true;
  else
    return false;
}

void loop() {
  // put your main code here, to run repeatedly:

  // for (int i = 0; i < NUMPIXELS; i++)
  // {
  //   pixels.setPixelColor(i, 50);
  //   delay(100);
  // }

  
  rainbowSlow();

  // int motion = isMotionDetected();

  // if (isMotionDetected()){}
  //   redOn();
  // }
  // else
  // {
  //   blueOn();
  // }
    


  //Serial.print("Motion detected:");
  //Serial.println(motion);
}

void initColors()
{
    rgbOff.r = 0;
    rgbOff.g = 0;
    rgbOff.b = 0;

    rgbRed.r = 255;
    rgbRed.g = 0;
    rgbRed.b = 0;
    
    rgbGreen.r = 0;
    rgbGreen.g = 255;
    rgbGreen.b = 0;
    
    rgbBlue.r = 0;
    rgbBlue.g = 0;
    rgbBlue.b = 255;   
}

void colorOff()
{
    setColor(rgbOff);
}

void greenOn()
{
    setColor(rgbGreen);
}

void redOn()
{
    setColor(rgbRed);
}

void blueOn()
{
    setColor(rgbBlue);
}

void lightOnMax() { light(255); }

int lightRand() { return random(1,255); }

int lightIntensity = 0;

int light(int intensity)
{
    if (intensity > 200)
      intensity = 200;
    if (intensity < 5)
      intensity = 5;

    lightIntensity = intensity;

    int intensityPercent = (100 * intensity) / 255;
    
    analogWrite(WHITE_PIN, intensity);
    //Serial.print("Light intensity: "); Serial.print(lightIntensity);
    //Serial.print(" "); Serial.print(intensityPercent);Serial.println("%");

    return intensity;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

int lightDimmer = 0;
int rainbowSpeed = 50;

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      delay(rainbowSpeed);
      for (uint16_t i=0; i < pixels.numPixels(); i=i+3) {
        pixels.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      pixels.show();

      light(lightDimmer++);

      if (lightDimmer > 255)
        lightDimmer = 0;

      for (uint16_t i=0; i < pixels.numPixels(); i=i+3) {
        pixels.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

bool lightIncrease = true;
void changeLightDirection()
{
  lightIncrease = !lightIncrease;
}

//Theatre-style crawling lights with rainbow effect
void rainbowSlow() 
{
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    delay(50);
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < pixels.numPixels(); i=i+3) {
        pixels.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      pixels.show();
    }
    
    if (lightIncrease)
      lightDimmer++;
    else
      lightDimmer--;
    int realIntensity = light(lightDimmer);
    Serial.println(realIntensity);
  }

  Serial.print("Light increase :");
  Serial.println(lightIncrease);

  changeLightDirection();
}

void setColor(rgbColor& color)
{
    for(int i = 0; i < NUMPIXELS; i++)
    {
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(color.r, color.g, color.b)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
    }     
}
