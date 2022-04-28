#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  
#include <Servo.h> 

Servo myservo1;
char data;
int IR1 = 2;
int IR2 = 4;

int Slot = 4;           
int flag1 = 0;
int flag2 = 0;

void setup() {
  lcd.init();                      // initialize the lcd
  
  lcd.begin(16,2);
  lcd.backlight();
pinMode(IR1, INPUT);
pinMode(IR2, INPUT);
  
myservo1.attach(9);
myservo1.write(100);

lcd.setCursor (0,0);
lcd.print("    Car  Parking   ");
lcd.setCursor (0,1);
lcd.print("  SYSTEM ");
delay (2000);
lcd.clear();  
Serial.begin(9600); //execution du serial monitor a 9600
}

void loop(){ 
  if(Serial.available())
  {data=Serial.read();
  
  if(data=='1' && Slot>0) /// 1qt 
  {myservo1.write(0);
  Slot=Slot-1;
  Serial.write('1');//write to qt 1
  
delay (2000);
myservo1.write(100);

  }
  else if (data=='0')// 0qt
  { myservo1.write(0);
    Slot=Slot+1;
  Serial.write('0');
   
  delay (2000);
myservo1.write(100);

    }
    /////////////////////////////////////////////////////////////

    else if (Slot<=0)
    {lcd.setCursor (0,0);
lcd.print("    SORRY     ");  
lcd.setCursor (0,1);
lcd.print("  Parking Full  "); 
delay (3000);
lcd.clear();
      }
  }


/////////////////////////////////////////////////////////////////////////////////////
if(digitalRead (IR1) == LOW && flag1==0 ) //entrée d'une voiture
{
if(Slot>0)
{flag1=1;
/////////////
if(flag2==0 )
{ 
  myservo1.write(0); 
Slot = Slot-1;

}
//////////////
}

else
{
lcd.setCursor (0,0);
lcd.print("    SORRY     ");  
lcd.setCursor (0,1);
lcd.print("  Parking Full  "); 
delay (3000);
lcd.clear();
 
}
}
//////////////////////////////////////////////////////////////

if(digitalRead (IR2) == LOW && flag2==0 ) //sortie d'une voiture
{
  flag2=1;


if(flag1==0 )

{
  
  myservo1.write(0); 
Slot = Slot+1;

}
}

if(flag1==1 && flag2==1 )
{
delay (2000);
myservo1.write(100);
flag1=0, flag2=0;
}



lcd.setCursor (0,0);
lcd.print("    WELCOME!    ");
lcd.setCursor (0,1);
lcd.print("Have  Space:  ");
lcd.print(Slot);
}
