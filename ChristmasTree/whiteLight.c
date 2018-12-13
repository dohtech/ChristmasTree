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
