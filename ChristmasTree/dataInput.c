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

void parseInput(String message)
{
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
