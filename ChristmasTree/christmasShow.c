
int pulseStep = 1;
int pulseWait = 10;
int pulseMax = 100;
int pulseMin = 1;

const int waitForAction = 60000;
const int waitForMotion = 10000;
long timeLastAction = 0;
bool motionDisabled = false;
unsigned long timeSinceMotion;

void checkMotionSensor()
{
    if ( (millis() - timeSinceMotion) > waitForMotion )
    {
        //Serial.println("Ready for new motion");
        motionDisabled = false;
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
