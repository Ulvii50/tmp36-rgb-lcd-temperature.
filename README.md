# TMP36 ilə Temperatur Ölçmə və RGB LED ilə Göstərmə

## Layihənin məqsədi
TMP36 sensoru ilə temperatur ölçülür, LCD ekranda göstərilir və temperatura görə RGB LED-də rəng dəyişir:
- Yaşıl: temperatur < 25°C
- Sarı: 25°C ≤ temperatur ≤ 50°C
- Qırmızı: temperatur > 50°C

## İstifadə olunan komponentlər
- Arduino UNO
- TMP36 Temperatur Sensoru
- RGB LED
- 3 ədəd rezistor (220Ω və ya 330Ω)
- LCD 16x2 (I2C modulu ilə)
- Jumper kabellər
- Breadboard

## 🖥️ Tinkercad Simulyasiya Linki
https://www.tinkercad.com/things/hV1CeY2SLxF-surprising-wluff-hango

## 🧠 İş prinsipi
- TMP36 sensorundan analog siqnal oxunur.
- Siqnal voltaja çevrilir → temperatur hesablanır.
- Temperatur LCD-də göstərilir.
- Temperatur səviyyəsinə uyğun olaraq RGB LED rəngi dəyişir.

## 📄 Arduino Kodu

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
