#include <Arduino.h>

#define LEVELS 5
#define LEDS 4
#define LED_START 9
#define BUTTON_START 4
#define greenLED 8
#define redLED 13
void setup(){
    true;
    /*Code*/
}
int levelCreation(int counter, int* level){
    while (counter > 0)
    {
        counter--;
        level[counter] = random(LEDS);
        Serial.print(level[counter]);
        Serial.print(" ");
    }
    return 1;
}
int showLeds(int level, int* array){
    long int timer;
    for (int i = 0; i <= level; i++)
    {
        for (int f = 1; f >= 0; f++)
        {
            digitalWrite(array[i] + LED_START, f);
            timer = millis();

            while (millis() - timer < 1000)
            {
                if (check_for_button() < LEDS)
                {
                    Serial.println("Lost!");
                    return 0;
                }
                
            }
            
        }
        
    }
    
    return 1;
}

int check_for_button(){
    long timer;
    for (int i = 0; i < LEDS; i++)
    {
        if (digitalRead(i + BUTTON_START))
        {
            while (digitalRead(i + BUTTON_START))
            {
                continue;
            }
            return i;
        }
        
    }
    
    return LEDS;
}

int allFlash(){
    for (int i = 0; i < LEDS; i++)
    {
        digitalWrite(LED_START + i, HIGH);
    }
    delay(500);
    for (int i = 0; i < LEDS; i++)
    {
        digitalWrite(LED_START + i, LOW);
    }
    
    
}

int won(){
    digitalWrite(greenLED, HIGH);
    delay(1000);
    digitalWrite(greenLED, LOW);
}

int lost(){
    digitalWrite(redLED, HIGH);
    delay(1000);
    digitalWrite(redLED, LOW);
}
void loop(){
    int array[LEDS] = { 0 };
    int level = 0;
    
    levelCreation(LEVELS, array);
    while (level < LEVELS)
    {
        if (!showLeds(level, array))
        {
            lost();
            allFlash();
            break;
        }

        else
        {
            int numUSERinputs = 0;
            int timeout = millis();

            while (numUSERinputs <= level)
            {
                if(millis() - timeout > 10000){
                    lost();
                    allFlash();
                    level = LEVELS;
                    numUSERinputs = LEVELS;
                    break;
                }

                int button = check_for_button();

                if (button != array[numUSERinputs])
                {
                    level = LEVELS;
                    lost();
                    allFlash();
                    break;
                    //LOST
                }

                else
                {
                    if (numUSERinputs == level)
                    {
                        //level change
                        if (level == LEVELS - 1)
                        {
                            Serial.println("Won");
                            won();
                            //leds on and off
                            allFlash();
                        }
                        break;
                    }
                    else
                    {
                        allFlash();
                        timeout = millis();
                        numUSERinputs ++;
                    }
                    
                }
                
                
            }
            
        }
        
        
    }
    true;
}