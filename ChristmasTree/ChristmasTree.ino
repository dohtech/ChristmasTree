#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIR_PIN 2
#define WHITE_PIN 4
#define RGB_PIN 5
#define NUMPIXELS 60

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800);

int pulseStep = 1;
int pulseWait = 10;
int pulseMax = 100;
int pulseMin = 1;

const int waitForAction = 60000;
const int waitForMotion = 10000;
long timeLastAction = 0;
bool motionDisabled = false;
unsigned long timeSinceMotion;

const String soundBlue = "Blue";
const String soundRed = "red";
const String soundGreen = "Green";
const String soundGronn = "grønn"; 
const String soundPa = "på";
const String soundJul = "jul";
const String soundAv = "av";
const String soundDim = "dim";
const String soundFade = "fade";
const String soundMer = "mer";
const String soundMindre = "mindre";
const String soundDisco = "disco";
const String soundMaks = "maks";
const String soundMax = "Max";
const String soundMinst = "minst";
const String soundOpp = "opp";
const String soundNed = "ned";
const String soundRolig = "rolig";
const String sound1 = "1";
const String sound2 = "2";
const String sound3 = "3";
const String sound4 = "4";
const String sound5 = "5";
const String soundEvig ="alltid";
const String soundRegnbue = "regnbue";
const String soundKarljohansvern = "Karljohansvern";

typedef struct rgbColors
{
    char r;
    char g;
    char b;    
} rgbColor;

rgbColor rgbOff, rgbRed, rgbGreen, rgbBlue;

void setup() 
{
    Serial.begin(9600);
    pinMode(WHITE_PIN, OUTPUT);
    pinMode(PIR_PIN, INPUT_PULLUP);
    pixels.begin(); // This initializes the NeoPixel library.
    initColors();
    colorOff(); 
    attachInterrupt(digitalPinToInterrupt(PIR_PIN), motionDetected, FALLING);
        
    Serial.println("Rockin' around the christmas tree.");
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
        
        if (message.indexOf(soundJul) >= 0)
            lightOnNormal();
        else if (message.indexOf(soundMaks) >= 0 || message.indexOf(soundMax) >= 0 )
            lightOnMax();
        else if (message.indexOf(soundMinst) >= 0)
            light(1);      
        else if (message.indexOf(soundAv) >= 0)
            lightOff();
        else if (message.indexOf(soundMer) >= 0)
            lightMore();
        else if (message.indexOf(soundMindre) >= 0)
            lightLess();
        else if (message.indexOf(soundOpp) >= 0)
            lightUp();
        else if (message.indexOf(soundNed) >= 0)
            lightDown();
        else if (message.indexOf(soundDisco) >= 0)
            discoTime();
        else if (message.indexOf(soundGreen) >= 0)
            greenOn();
        else if (message.indexOf(soundRed) >= 0)
            redOn();
        else if (message.indexOf(soundBlue) >= 0)
            blueOn();
        else if (message.indexOf(soundKarljohansvern) >= 0)
            kjvShow(50);
        else if (message.indexOf(soundRegnbue) >= 0)
            regnbue(20);
        else if (message.indexOf(soundRolig) >= 0)
        {
            if (message.indexOf(sound1) >= 0)
                rolig1();
            else if (message.indexOf(sound1) >= 0)
                rolig2();         
            else if (message.indexOf(soundEvig) >= 0)
                rolig3();    
            else if (message.indexOf(sound1) >= 0)
                rolig4();       
            else if (message.indexOf(sound1) >= 0)
                rolig5();                                
        }
                          
        else if (isNumerical(message))
            lightNumber(message);
    }

    checkReadyForAction();
    checkMotionSensor();
}

void checkReadyForAction()
{
    if ((millis() - timeLastAction) > waitForAction)
    {
        timeLastAction = millis();
        randColorOn();
        Serial.print("New color ");
        Serial.println(millis());
    }
}

void motionDetected()
{
    if (motionDisabled == true)
    {
        Serial.print("Motion not yet enabled ");
        Serial.println((millis() - timeSinceMotion));
        return;
    }
    
    motionDisabled = true;
    Serial.println("Motion detected");
    randColorOn();
    lightOff();
    delay(200);
    lightOnMax();

    delay(4000);
    
    lightOnNormal();   
    timeSinceMotion = millis();
}

bool isNumerical(String message)
{
    String messageStart = message.substring(0,1);
    
    int numberTest = messageStart.toInt();
    
    Serial.println(numberTest);

    if (message.indexOf("00") >= 0)
        numberTest = 1;

    if (numberTest > 0)
        return true;
    else
        return false;
}



void checkMotionSensor()
{
    if ( (millis() - timeSinceMotion) > waitForMotion )
    {
        //Serial.println("Ready for new motion");
        motionDisabled = false;
    }     
}

int lightIntensity = 0;

void light(int intensity)
{
    lightIntensity = intensity;

    int intensityPercent = (100 * intensity) / 255;
    
    analogWrite(WHITE_PIN, intensity);
    Serial.print("Light intensity: "); Serial.print(lightIntensity);
    Serial.print(" "); Serial.print(intensityPercent);Serial.println("%");
}

void lightOnNormal() { light(150); }

void lightOnMax() { light(255); }

int lightRand() { return random(1, 255); }

void lightOff() 
{ 
    light(0);
}

void lightMore()
{
    lightIntensity += 10;
    if (lightIntensity > 255)
        lightIntensity = 255;
    light(lightIntensity);
}

void lightLess()
{
    lightIntensity -= 10;
    if (lightIntensity < 0)
        lightIntensity = 1;
    light(lightIntensity);
}

void lightUp()
{
    for (int pulseWidth = pulseMin; pulseWidth <= pulseMax; pulseWidth += pulseStep)
    {
        Serial.println(pulseWidth);
        light(pulseWidth);
        delay(pulseWait);
    }
}

void lightDown()
{
    for (int pulseWidth = pulseMax; pulseWidth >= pulseMin; pulseWidth -= pulseStep)
    {
        Serial.println(pulseWidth);
        light(pulseWidth);
        delay(pulseWait);
    }
}



void discoTime()
{
    for (int i = 0; i < 20; i++)
    {
        light(lightRand());
        delay(random(50,200));
        light(0);
        delay(random(10,100));
    }
}

void rolig1()
{
    int turns = 10;

    for (byte i = 0; i < turns; i++)
    {
        lightUp();
        lightDown();
    }    
}

void rolig2()
{
    int turns = 10;
    int wait = 10;
    
    for (byte i = 0; i < turns; i++)
    {
        lightUp();
        regnbue(wait);
        lightDown();
    }
}

void rolig3()
{
    while(1)
    {
        rolig2();
    }
}

void rolig4()
{
    
}

void rolig5()
{
    
}

void regnbue(uint8_t wait)
{
    uint16_t i, j;

    for(j=0; j<256*5; j++) // 5 cycles of all colors on wheel
    { 
        for(i=0; i< pixels.numPixels(); i++) 
        {
            pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
        }
    
        pixels.show();
        delay(wait);
        light(20);
    }
}

void kjvShow(uint8_t wait)
{
    theaterChaseRainbow(wait);
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < pixels.numPixels(); i=i+3) {
        pixels.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      pixels.show();

      delay(wait);
      light(lightRand());

      for (uint16_t i=0; i < pixels.numPixels(); i=i+3) {
        pixels.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
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

void lightNumber(String message)
{
    Serial.println("Number detected");
    String subMessage = message.substring(message.length()-3, message.length());
    Serial.print("String with number: ");
    Serial.println(subMessage);
    int subValue;
    
    if (subMessage.toInt() > 255)
    {
        String subMessage2 = subMessage.substring(subMessage.length() - 2, subMessage.length() );
        subValue = subMessage2.toInt();
    }
    else
        subValue = subMessage.toInt();
    
    light(subValue);
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

void randColorOn()
{
    rgbColor color;
    randRgb(color);
    setColor(color);
}

void colorOff()
{
    setColor(rgbOff);
}

char randPixel()
{
    return random(0, NUMPIXELS);
}

char randColor() { return random(0, 255); }

void randRgb(rgbColor& inRgb)
{
    inRgb.r = randColor();
    inRgb.g = randColor();
    inRgb.b = randColor();
}

void oneColor(int pixel, rgbColor& color)
{
    pixels.setPixelColor(pixel, pixels.Color(color.r, color.g, color.b)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
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
