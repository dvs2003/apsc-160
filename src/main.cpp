/*
LAB : 
Email : singhania.devesh@outlook.com
UBC Email : dsingh34@student.ubc.ca
*/
/*
Features
- If the button is pushed when the sequence is being shown, you Loose.
- If button is being pushed while visual feedback is shown or level change
indicator is shown, you loose.
- Program responds to both short taps and long press and holds
- timeout
- (TBD) button hold timeout
- Game auto resetarts after a win or loss
- Easiliy modifiable code by using the parameters defined below.
Changelog
- Visual feedback now during button click, and no loss on viusal feedback loop.
*/
#include <Arduino.h>

/*Parameters of the game*/
#define LEVELS 5                  //MAX numebr of LEVELS
#define OPTIONS 4                 //Number of LEDs and BUTTONs
#define LED_SEQUENCE_START 9      //The SEQUENCE of LED PINS start from this pin
#define BUTTON_SEQUENCE_START 4   //The SEQUENCE of BUTTON PINS start from this pin
#define LED_TIME 700              //Milliseconds the LED pin must be ON and OFF
#define DEBOUNCE 50               //Milliseconds of DEBOUNCE
#define SIGNAL_COUNT 3            //Number of times the GREEN or RED LED will BLINK on win or loss respectively.
#define TIMEOUT 6000              //AFK Timer

/*
The LEDs are connected adjecently and the green pin is numerically the start of
the sequence, and the LEDs can be looped through
*/
/*Name the win and loss LEDs tho*/
const uint8_t WIN_LED = 8;
const uint8_t LOSS_LED = 13;
//change this in the above code

/*Variables*/
int generated_Level[LEVELS] = { 0 };
int count_User_Inputs = 0;
int check = 0;
int button = 0;
unsigned long int afk_Timer = 0;

/*Functions*/
bool generate_Level(int, int*, int);
bool display_Pattern(int, int*);
int button_Check();
int termination(int);
bool level_Change();
bool visual_Feedback(int);

void setup() {
  /*Begin Serial Comms*/
  Serial.begin(9600);
  /*Setting buttons and LEDs to input and ouput*/
  for (int component = 0; component < OPTIONS; component++)
  {
    pinMode(component + LED_SEQUENCE_START, OUTPUT);
    pinMode(component + BUTTON_SEQUENCE_START, INPUT);
  }

  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  /*Set a seed for random function*/
  randomSeed(analogRead(0));  //Put it in the loop is possible

}

void loop() {
  Serial.println("A new Game has begun.");
  delay(500);
  /*Start each GAME iteration by GENERATING a new LEVEL*/
  generate_Level(LEVELS, generated_Level, OPTIONS);
  /*Delay for debugging, remove it*/
  delay(500);
  /*Displaying the generated LEVEL to the SERIAL port*/
  for (int i = 0; i < LEVELS; i++)
  {
    Serial.print(generated_Level[i]);
    Serial.print(" ");
  }
  Serial.print("\n");
  /*Remove this delay in a bit*/
  delay(1000);
  /*START of MAIN GAME LOOP*/
  for (int i = 0; i < LEVELS; i++)
  {
    /*Continue to USER INPUT STAGE if user hasn't lost in the PATTERN DISPLAY STAGE*/
    if (!(display_Pattern(i, generated_Level)))
    {
      termination(13);
      level_Change();
      break;
    }
    else{
      //AFK Reset
      count_User_Inputs = 0;
      afk_Timer = millis();
      /*Loop to take USER INPUT from buttons*/
      while (count_User_Inputs <= i)
      {
        /*AFK TIMEOUT -> LOOSE*/
        if (millis() - afk_Timer > TIMEOUT)
        {
          Serial.println("Timeout.");
          /*
          Reminder : All these game end steps are kinda the same so make a func and pass a reference
          to these to make this spagetti more eradable.
          */
          termination(13);
          level_Change();
          i = LEVELS;
          count_User_Inputs = LEVELS;
          /*
          Reminder : remove all the useless breaks in the code
          */
          break;
        }
        
        check = button_Check(); 
        /*
        VALIS INPUTS include 0, 1, 2, 3;
        OPTIONS constant is one above that range 
        and is the default return of the button check
        So it will only check for right and wrong
        if a button press is detected.
        */
        if (check < OPTIONS)
        {
          /*Check if the button pushed is currect corruspoding to the generated array*/
          if (check != generated_Level[count_User_Inputs])
          {
            //make this terminate the whole ting
            termination(13);
            count_User_Inputs = LEVELS;
            i = LEVELS;
            level_Change();
            break;
          }
          else
          {
            /*If the loop is at the last input of each level*/
            if (count_User_Inputs == i)
            {
              Serial.println("Level Passed\n");
              level_Change();
              /*LAST INPUT of the LAST LEVEL*/
              if (i == LEVELS - 1)
              {
                termination(8);
                Serial.println("Game Won!");
                level_Change();
              }
              
              break;
              //won
            }
            else
            {
              /*
              If the loop hasnt terminated the input was 
              valid and the level hasnt ended
              */
              Serial.println("Valid Input\n");
              afk_Timer = millis();
              count_User_Inputs ++;

            }
            
            
          }
          
          
        }
        
      }
      

    }
  }
  Serial.println("Game Ended!");
}
/*Generate an array with random values and options number of elements*/
bool generate_Level(int count, int* array, int options){
  while (count-- > 0)
  {
    array[count] = random(options);
  }

  return true;
}
/*Display the pattern of LEDs at the start of each level*/
bool display_Pattern(int current_Level, int* array){
  unsigned long int timer;
  /*Loop through each LED in the level*/
  for (int i = 0; i <= current_Level; i++)
  {
    /*
    The state goes from 1 to 0, turning the LED ON then OFF
    With a delay using the while loop that checks for pre mature input
    */
    for (int state = 1; state >= 0; state--)
    {
      Serial.print("LED State ");
      Serial.print(state);
      Serial.print("\n");
      /*Write the corresponding LED a STATE ON then OFF*/
      digitalWrite(array[i] + LED_SEQUENCE_START, state);
      timer = millis();
      /*DELAY*/
      while (millis() - timer < LED_TIME)
      {
        /*Checking for user INPUT in between the SEQUENCE GENERATION*/
        if (button_Check() < OPTIONS)
        {
          Serial.println("LOST THE GAME!");
          return false;
        }
        
      }
      
    }
  }
  
  return true;
}
/*Make a function for is valis*/
/*Check which button has been pressed and give visual feedback*/
int button_Check(){
  unsigned long int timer = 0;
  for (int i = 0; i < OPTIONS; i++)
  {
    /*Looping through each button chekcing for input*/
    if (digitalRead(i + BUTTON_SEQUENCE_START))
    {
      //Debounce
      digitalWrite(i + LED_SEQUENCE_START, 1);
      /*Debounce along with long hold*/
      while (millis() - timer < DEBOUNCE || digitalRead(i + BUTTON_SEQUENCE_START))
      {
        true;
      }
      digitalWrite(i + LED_SEQUENCE_START, 0);
      
      return i;
    }
    
  }
  return OPTIONS;
}
/*The next 2 functions are just for displaying LED in a different style*/
int termination(int LED){
  unsigned long int timer = 0;

  for (int i = 0; i < SIGNAL_COUNT; i++)
  {
    for (int state = 1; state >= 0; state--)
    {
      digitalWrite(LED, state);
      timer = millis();
      
      while (millis() - timer < LED_TIME)
      {
        //Serial.println(millis() - timer);
        continue;
      }
      
    }
    
  }

  return 0;
}
/*Turns on all the LEDs and then Turns them off.*/
bool level_Change(){
  unsigned long int timer = 0;
  int button = 0;
  for (int state = 1; state >= 0; state--)
  {
    for (int i = 0; i < OPTIONS; i++)
    {
      digitalWrite(LED_SEQUENCE_START + i, state);
    }
    timer = millis();
    while (millis() - timer < LED_TIME)
    {
      if (button_Check() < OPTIONS)
      {
        return false;
      }
      
    }
    
  }
  return true;
}
