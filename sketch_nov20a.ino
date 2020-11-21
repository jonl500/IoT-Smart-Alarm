#include <LiquidCrystal_I2C.h>

// Digital
int red = 7, blue = 5, green = 6; // LED
int echo = 3, trig = 4; // Ping Sensor
int buzz = 11; // Buzzer

// Analog
LiquidCrystal_I2C lcd(0x27,16,2); // LCD Screen
int lit = 1; // Motion Sensor
int swi = 0; // Button
int qwe;

void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig,INPUT);
  lcd.init();
  lcd.backlight();
  //lcd.setCursor(0,0);
  //lcd.print("Ardiuino");
}

void loop() {
  //if(analogRead(swi) < 200) qwe = 1;
  //else qwe = 0;
  //Serial.print(qwe);
  Serial.print(analogRead(swi));
  Serial.print(" - ");
  Serial.println(analogRead(lit));
  delay(1000);

}
