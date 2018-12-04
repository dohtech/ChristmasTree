#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define WHITE_PIN 3
#define RGB_PIN 4
#define NUMPIXELS 60

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800);

int pulseStep = 1;
int pulseWait = 10;
int pulseMax = 200;
int pulseMin = 20;

String soundBlue = "Blue";
String soundRed = "red";
String soundGreen = "Green";
String soundGronn = "grønn"; 
String soundPa = "på";
String soundJul = "jul";
String soundAv = "av";
String soundDim = "dim";
String soundFade = "fade";
String soundMer = "mer";
String soundMindre = "mindre";
String soundDisco = "disco";
String soundMaks = "maks";
String soundMax = "Max";
String soundOpp = "opp";
String soundNed = "ned";

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
    Serial.println("Let's try again.");
    
    pixels.begin(); // This initializes the NeoPixel library.
    initColors();
    colorOff(); 
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
        else if (isNumerical(message))
            lightNumber(message);
   }
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

int lightIntensity = 0;

void light(int intensity)
{
    lightIntensity = intensity;

    int intensityPercent = (100 * intensity) / 255;
    
    analogWrite(WHITE_PIN, intensity);
    Serial.print("Light intensity: "); Serial.print(lightIntensity);
    Serial.print(" "); Serial.print(intensityPercent);Serial.println("%");
}

void lightOnNormal() { light(100); }

void lightOnMax() { light(255); }

void lightOff() 
{ 
    light(0);
    colorOff();   
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

int lightRand() { return random(1,255); }

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

void colorOff()
{
    setColor(rgbOff);
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

