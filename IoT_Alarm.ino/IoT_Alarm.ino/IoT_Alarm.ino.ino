#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Wire.h>

// Keypad Setup
const byte ROWS = 4;
const byte COLS = 3;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// Digital
int red = 1, blue = 2, green = 3; // LED
int echo = 4, trig = 5; // Ping Sensor
int buzz = 6; // Buzzer
byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {9, 8, 7};

// Analog
LiquidCrystal_I2C lcd(0x27,16,2); // LCD Screen
int lit = 2; // Motion Sensor

Keypad newpad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  //pinMode(lit,INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Welcome to the");
  lcd.setCursor(0,1);
  lcd.print(" Smart Alarm");
  delay(2000);
  lcd.clear();
  
}

void loop() { 
  //Keypad base
  char customKey = newpad.getKey();
  if(customKey) Serial.println(customKey);
  
   // if(customKey != '*'){
    //  lcd.print("Press * to Arm");
    //  lcd.setCursor(0,1);
    //  lcd.print("the Alarm");
     // delay(1500);
    //  lcd.clear();
     // delay(500);
    // }
  //Ping Sensor base
  int duration, distance;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration/2)/29.1;
   if(distance <= 10){
    //Buzzer base
    tone(buzz,1200);
    noTone(buzz);
    digitalWrite(red,HIGH);
   }else{
    digitalWrite(red,LOW);
   }

}
  //LCD Screen base
  //lcd.setCursor(0,0);
  //lcd.print("Ardiuino");

  //Keypad base 
  //char customKey = customKeypad.getKey();
  //if(customKey) Serial.println(customKey);

 
