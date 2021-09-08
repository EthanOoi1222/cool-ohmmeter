int analogPin = 0;
int raw = 0;
int Vin = 5;
float Vout = 0;
float R2 = 0;
float R1 = 200;
float buffer = 0;

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows


void setup(){
  Serial.begin(9600);
  lcd.init(); 
  lcd.backlight();

}

void loop(){
  raw = analogRead(analogPin);
  if (raw){
    buffer = raw * Vin;
    Vout = (buffer) / 1024.0;
    buffer = (Vin / Vout) - 1;
    R1 = R2 * buffer;
    Serial.print("Vout: "); 
    Serial.println(Vout);
    Serial.print("R1: ");
    Serial.println(R1);
    delay(1000);
  }
if(R1>5000){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Coolest Ohmmeter");
    lcd.setCursor(0,1);
    lcd.print("no resistor");
  }
  else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Coolest Ohmmeter");  
    lcd.setCursor(0,1);
    lcd.print(R1);
  }
  }
