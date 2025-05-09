#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);
#define redPin 3
#define bluePin 5
#define greenPin 6
void setup()
{
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  
}

void loop()
{
  int deyer = analogRead(A0);
  float voltaje = deyer * (5.0 / 1023.0);
  float temp = (voltaje - 0.5) * 100;
  
  lcd.setCursor(0,0);
  lcd.print("Temperatur:");
  lcd.setCursor(11,0);
  lcd.print(temp);
  
  if(temp < 25) 
  {
    setColor(0,255,0);
  }else if(temp >= 25 && temp <= 50)
  {
    setColor(255,255,0);
  }else
  {
    setColor(255,0,0);
  }
  
}


void setColor(int red, int green , int blue)
{
  analogWrite(redPin,red);
  analogWrite(greenPin,green);
  analogWrite(bluePin,blue);
}

