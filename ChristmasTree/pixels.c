#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800);

rgbColor rgbOff, rgbRed, rgbGreen, rgbBlue;

void initPixels()
{
    pixels.begin(); // This initializes the NeoPixel library.
    initColors();
    colorOff(); 
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
