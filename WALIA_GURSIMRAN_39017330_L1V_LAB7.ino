/*
NAME GURSIMRAN SINGH WALIA
STUDENT NO. 57919953
EMAIL gwalia@student.ubc.ca
LAB  L1V
*/
#define LEFT LOW
#define RIGHT HIGH

//symbolic constants for INPUT/OUTPUT pins
int const A = 11;
int const B = 10;
int const C = 7;
int const D = 8;
int const E = 9;
int const F = 12;
int const G = 13;
int const H = 6;

int switchbutton=5;


// define any function(s), constants required to implement your program

//initialization

void setup(void)
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
}

void off(void)
{
   digitalWrite(A, LOW); 
   digitalWrite(B, LOW); 
   digitalWrite(C, LOW); 
   digitalWrite(D, LOW); 
   digitalWrite(E, LOW); 
   digitalWrite(F, LOW); 
   digitalWrite(G, LOW); 
   digitalWrite(H, LOW);
}
  

void letter_G(void)//output letter g

  {
  if(digitalRead(switchbutton)==1){
   digitalWrite(A, HIGH); 
   digitalWrite(B, LOW); 
   digitalWrite(C, HIGH); 
   digitalWrite(D, HIGH); 
   digitalWrite(E, HIGH); 
   digitalWrite(F, HIGH); 
   digitalWrite(G, HIGH); 
   digitalWrite(H, LOW);
  }
   else
   { off();
    }
  }

void letter_U(void)//output letter u

  {
  if(digitalRead(switchbutton)==1){
   digitalWrite(A, LOW); 
   digitalWrite(B, LOW); 
   digitalWrite(C, HIGH); 
   digitalWrite(D, HIGH); 
   digitalWrite(E, HIGH); 
   digitalWrite(F, LOW); 
   digitalWrite(G, LOW); 
   digitalWrite(H, LOW);
  }
   else
   { off();
    }
  }

void letter_r(void)//output letter r

  {
  if(digitalRead(switchbutton)==1){
   digitalWrite(A, HIGH); 
   digitalWrite(B, LOW); 
   digitalWrite(C, LOW); 
   digitalWrite(D, LOW); 
   digitalWrite(E, HIGH); 
   digitalWrite(F, HIGH); 
   digitalWrite(G, LOW); 
   digitalWrite(H, LOW);
  }
   else
   { off();
    }
  }

void letter_s(void)//output letter s

  {
  if(digitalRead(switchbutton)==1){
   digitalWrite(A, HIGH); 
   digitalWrite(B, LOW); 
   digitalWrite(C, HIGH); 
   digitalWrite(D, HIGH); 
   digitalWrite(E, LOW); 
   digitalWrite(F, HIGH); 
   digitalWrite(G, HIGH); 
   digitalWrite(H, LOW);
  }
   else
   { off();
    }
  }

void letter_I(void)//output letter i

  {
  if(digitalRead(switchbutton)==1){
   digitalWrite(A, LOW); 
   digitalWrite(B, LOW); 
   digitalWrite(C, LOW); 
   digitalWrite(D, LOW); 
   digitalWrite(E, HIGH); 
   digitalWrite(F, HIGH); 
   digitalWrite(G, LOW); 
   digitalWrite(H, LOW);
  }
   else
   { off();
    }
  }

void letter_m(void)//output letter m

  {
  if(digitalRead(switchbutton)==1){
   digitalWrite(A, LOW); 
   digitalWrite(B, LOW); 
   digitalWrite(C, HIGH); 
   digitalWrite(D, LOW); 
   digitalWrite(E, HIGH); 
   digitalWrite(F, LOW); 
   digitalWrite(G, HIGH); 
   digitalWrite(H, LOW);
  }
   else
   { off();
    }
  }

void letter_a(void)//output letter a

  {
  if(digitalRead(switchbutton)==1){
   digitalWrite(A, HIGH); 
   digitalWrite(B, HIGH); 
   digitalWrite(C, HIGH); 
   digitalWrite(D, HIGH); 
   digitalWrite(E, HIGH); 
   digitalWrite(F, LOW); 
   digitalWrite(G, HIGH); 
   digitalWrite(H, LOW);
  }
   else
   { off();
    }
  }

void letter_N(void)//output letter n

  {
  if(digitalRead(switchbutton)==1){
   digitalWrite(A, LOW); 
   digitalWrite(B, LOW); 
   digitalWrite(C, HIGH); 
   digitalWrite(D, LOW); 
   digitalWrite(E, HIGH); 
   digitalWrite(F, LOW); 
   digitalWrite(G, HIGH); 
   digitalWrite(H, LOW);
  }
   else
   { off();
    }
  }

void letter_W(void)//output letter W

  {
  if(digitalRead(switchbutton)==1){
   digitalWrite(A, LOW); 
   digitalWrite(B, LOW); 
   digitalWrite(C, HIGH); 
   digitalWrite(D, HIGH); 
   digitalWrite(E, HIGH); 
   digitalWrite(F, LOW); 
   digitalWrite(G, LOW); 
   digitalWrite(H, LOW);
  }
   else
   { off();
    }
  }

void letter_l(void)//output letter l

  {
  if(digitalRead(switchbutton)==1){
   digitalWrite(A, LOW); 
   digitalWrite(B, LOW); 
   digitalWrite(C, LOW); 
   digitalWrite(D, HIGH); 
   digitalWrite(E, HIGH); 
   digitalWrite(F, HIGH); 
   digitalWrite(G, LOW); 
   digitalWrite(H, LOW);
  }
   else
   { off();
    }
  }
void loop(void)
{
  while(digitalRead(switchbutton)==1){
    letter_G(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;
    }
    delay(1000);
    
    letter_U(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;
    }delay(1000);
    
    letter_r(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;
    }
    
    delay(1000);
    
    letter_s(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;
    }
    delay(1000);
    
    letter_I(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;
    }
    delay(1000);
    
    letter_m(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;
    }
    delay(1000);
    
    letter_r(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;
    }
    delay(1000);
    
    letter_a(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;
    }
    delay(1000);
    
    letter_N(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;
    }
    delay(1000);
    
     letter_W(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;
    }
    delay(1000);
    
     letter_a(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;
    }
    delay(1000);
    
     letter_l(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;}
     delay(1000);
     
      letter_I(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;
    }
    delay(1000);
    
  
   letter_a(); 
        if(digitalRead(switchbutton)==0)
    { off();
     break;
    }
    delay(1000);
  }

}



















