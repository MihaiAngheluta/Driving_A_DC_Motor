//Includem libraria pentru LCD
#include <LiquidCrystal.h>

//Initializam intrarile IN1 si IN2 precum si controlul ENA ale motorului
int IN1 = 8;
int IN2 = 9;
int ENA = 10;
int led1 = 6;
int led2 = 7;
int led3 = 13; 

//Initiliazam pinii de date si control ai lcd-ului
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal LCD (rs, en, d4, d5, d6, d7);

//Setam pinii motorului si ai lcd-ului ca pini de iesire
void setup() 
{
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
//Afisam textul "PROIECT: ACTIONARI ELECTRICE REGLABILE" 
  LCD.begin(16,2);
  LCD.setCursor (4, 0);
  LCD.print("PROIECT:");
  delay(2000);
  LCD.setCursor (3, 1);
  LCD.print("ACTIONARI");
  delay(2000);
  LCD.begin(16,2);
   LCD.setCursor (3, 0);
  LCD.print("ELECTRICE");
  delay(2000);
  LCD.setCursor (3, 1);
  LCD.print("REGLABILE");
  delay(2000);  
  digitalWrite(led1, HIGH);
 }
 
//Incepe bucla continua
void loop() 
{
//Afisam textul "Motor Speed" 
  LCD.begin(16,2);
  LCD.clear();
  LCD.home();
  LCD.print("Motor Speed:");
 // digitalWrite(led1,HIGH);
  delay(2000);
  digitalWrite(led2,HIGH);
  
//Rotim motorul la dreapta
  digitalWrite(IN1,LOW);
  digitalWrite(IN2, HIGH);
//Motorul porneste si va avea o turatie de la 0 la 256
  for (int i=0; i<255; i++)
  {
    analogWrite(ENA,i);
    //Setam sa ne afiseze turatia in procente de la 0 la 100%   
    int speed= map(i,0,255,0,100);
    LCD.setCursor(0,1);
    LCD.print("                    ");
    LCD.setCursor(0,1);
    LCD.print(speed);
    LCD.print("%");
    LCD.print(" Rot.Dreapta ");
    delay(50); 
    
    //Daca turatia a ajuns la maloarea maxima ne afiseara acest lucru
    if (speed==100) 
    { 
       LCD.setCursor(0,1);
       LCD.print("                    ");
       LCD.setCursor(0,1);
       LCD.print(speed);
       LCD.print("%");
       LCD.print(" Max.Dreapta ");
    } 
  }
  //Stai cu turatia la maxim timp de 3 secunde
  digitalWrite(ENA,HIGH);
  delay(3000);

 //Motorul se opreste si va avea turatia de la 256 la 0
  for (int i=255; i>  0; i--)
  {
   // digitalWrite(led1, HIGH);
    digitalWrite(led2,LOW);
    analogWrite(ENA,i);
    //Setam sa ne afiseze turatia in procente de la 100 la 0%      
    int speed= map(i,0,255,0,100);
    LCD.setCursor(0,1);
    LCD.print("                    ");
    LCD.setCursor(0,1);
    LCD.print(speed);
    LCD.print("%");
    LCD.print(" Oprire ");
    delay(50);
    
    //Daca turatia a ajuns la maloarea minima ne afiseara acest lucru
    if (speed==0) 
    { 
       LCD.setCursor(0,1);
       LCD.print("                    ");
       LCD.setCursor(0,1);
       LCD.print(speed);
       LCD.print("%");
       LCD.print(" Pauza ");
    }  
  }
  //Pauza
  digitalWrite(ENA,LOW);
  delay(3000);
 
 //digitalWrite(led1, HIGH);
 digitalWrite(led3,HIGH); 
 ////Rotim motorul la stanga 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
//Motorul porneste si va avea o turatie de la 0 la 256  
for (int i=0; i<255; i++)
{
  analogWrite(ENA,i);
  //Setam sa ne afiseze turatia in procente de la 0 la 100%
       int speed= map(i,0,255,0,100);
       LCD.setCursor(0,1);
       LCD.print("                    ");
       LCD.setCursor(0,1);
       LCD.print(speed);
       LCD.print("%");
       LCD.print(" Rot.Stanga ");
       delay(50);
       
    //Daca turatia a ajuns la maloarea maxima ne afiseara acest lucru
     if (speed==100) 
    { 
       LCD.setCursor(0,1);
       LCD.print("                    ");
       LCD.setCursor(0,1);
       LCD.print(speed);
       LCD.print("%");
       LCD.print(" Max.Stanga ");
    }
}
//Stai cu turatia la maxim timp de 3 secunde
  digitalWrite(ENA,HIGH);
  delay(3000);

//Motorul se opreste si va avea turatia de la 256 la 0
  for (int i=255; i>0; i--)
{
    //digitalWrite (led1, HIGH); 
    digitalWrite(led3, LOW);
    analogWrite(ENA,i);
   //Setam sa ne afiseze turatia in procente de la 100 la 0%
    int speed= map(i,0,255,0,100);
    LCD.setCursor(0,1);
    LCD.print("                    ");
    LCD.setCursor(0,1);
    LCD.print(speed);
    LCD.print("%");
    LCD.print(" Oprire ");
    delay(50);
    
  //Daca turatia a ajuns la maloarea minima ne afiseara acest lucru
     if (speed==0) 
    { 
       LCD.setCursor(0,1);
       LCD.print("                    ");
       LCD.setCursor(0,1);
       LCD.print(speed);
       LCD.print("%");
       LCD.print(" Pauza ");
    }
}
//Pauza
  digitalWrite(ENA,LOW);
  delay(3000);
}
