const char WHITE_PIN = 3;
int pulseStep = 1;
int pulseWait = 10;
int pulseMax = 200;
int pulseMin = 20;

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

void setup() 
{
    Serial.begin(9600);
    pinMode(WHITE_PIN, OUTPUT);
    Serial.println("Let's try again.");
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

void lightOff() { light(0); }

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



