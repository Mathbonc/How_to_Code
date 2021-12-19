#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880
#include <LiquidCrystal.h> 
int buzzer = 8;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(){
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(2,INPUT);
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}
void loop(){
  int botao = digitalRead(9);
  Serial.println(botao);
  if(botao==1){
    lcd.clear();
    lcd.setCursor(0, 0);
    char String1[] = "O Imperador";
    char String2[] = "Ta on!";
    lcd.print(String1);
    lcd.setCursor(0,1);
    lcd.print(String2);
    Marcha_imperial();
  }
}
void Marcha_imperial(){
  beep(buzzer, a, 500); 
  beep(buzzer, a, 500);     
  beep(buzzer, a, 500); 
  beep(buzzer, f, 350); 
  beep(buzzer, cH, 150);
  beep(buzzer, a, 500);
  beep(buzzer, f, 350);
  beep(buzzer, cH, 150);
  beep(buzzer, a, 1000);

    //first bit
   
  beep(buzzer, eH, 500);
  beep(buzzer, eH, 500);
  beep(buzzer, eH, 500);    
  beep(buzzer, fH, 350); 
  beep(buzzer, cH, 150);
  beep(buzzer, gS, 500);
  beep(buzzer, f, 350);
  beep(buzzer, cH, 150);
  beep(buzzer, a, 1000);

    //second bit...

  beep(buzzer, aH, 500);
  beep(buzzer, a, 350); 
  beep(buzzer, a, 150);
  beep(buzzer, aH, 500);
  beep(buzzer, gSH, 250); 
  beep(buzzer, gH, 250);
  beep(buzzer, fSH, 125);
  beep(buzzer, fH, 125);    
  beep(buzzer, fSH, 250);

  delay(250);

  beep(buzzer, aS, 250);    
  beep(buzzer, dSH, 500);  
  beep(buzzer, dH, 250);  
  beep(buzzer, cSH, 250);  

  //start of the interesting bit

  beep(buzzer, cH, 125);  
  beep(buzzer, b, 125);  
  beep(buzzer, cH, 250);      
  
  delay(250);

  beep(buzzer, f, 125);  
  beep(buzzer, gS, 500);  
  beep(buzzer, f, 375);  
  beep(buzzer, a, 125); 
  beep(buzzer, cH, 500); 
  beep(buzzer, a, 375);  
  beep(buzzer, cH, 125); 
  beep(buzzer, eH, 1000); 

  //more interesting stuff (this doesn't quite get it right somehow)

  beep(buzzer, aH, 500);
  beep(buzzer, a, 350); 
  beep(buzzer, a, 150);
  beep(buzzer, aH, 500);
  beep(buzzer, gSH, 250); 
  beep(buzzer, gH, 250);
  beep(buzzer, fSH, 125);
  beep(buzzer, fH, 125);    
  beep(buzzer, fSH, 250);

  delay(250);

  beep(buzzer, aS, 250);    
  beep(buzzer, dSH, 500);  
  beep(buzzer, dH, 250);  
  beep(buzzer, cSH, 250);  

  //repeat... repeat

  beep(buzzer, cH, 125);  
  beep(buzzer, b, 125);  
  beep(buzzer, cH, 250);   
  
  delay(250);
  
  beep(buzzer, f, 250);  
  beep(buzzer, gS, 500);  
  beep(buzzer, f, 375);  
  beep(buzzer, cH, 125); 
  beep(buzzer, a, 500);            
  beep(buzzer, f, 375);            
  beep(buzzer, c, 125);            
  beep(buzzer, a, 1000);       

}

void beep (unsigned char buzzer, int frequencyInHertz, long timeInMilliseconds)

{ 

    int x;   
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));

    for (x=0;x<loopTime;x++)   
    {    

        digitalWrite(buzzer,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(buzzer,LOW);
        delayMicroseconds(delayAmount);
    }    

    delay(20);
}    
