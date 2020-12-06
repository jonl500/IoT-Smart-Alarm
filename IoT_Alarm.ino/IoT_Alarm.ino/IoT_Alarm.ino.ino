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
int red = 2, blue = 2, green = 3; // LED
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

  byte h = 0;
  while(h == 0) {
    h = Serial.parseInt();
    Serial.println(h);
  }
}
   
}

void loop() { 
  //Keypad base
  char customKey = newpad.getKey();
  if(customKey) Serial.println(customKey);
  delay(1);
  lcd.setCursor(0,0);
  lcd.print("Press * to Arm");
  lcd.setCursor(0,1);
  lcd.print("the Alarm System");
      delay(1000);
      lcd.clear();
  // while(customKey=='*'){
   //   lcd.print("Alarm is Armed");
   //   delay(1000);
  //    lcd.clear();
        //Ping Sensor base
//int duration, distance;
//  digitalWrite(trig,LOW);
//  delayMicroseconds(2);
 // digitalWrite(trig,HIGH);
//  delayMicroseconds(10);
 // digitalWrite(trig,LOW);
//  duration = pulseIn(echo,HIGH);
 // distance = (duration/2)/29.1;
 // Serial.print("Distance ");
 // Serial.print(distance);
//  Serial.println(" cm");
 //char pass = newpad.getKey();
// if(customKey != '*'){
// customKey = '0';
// }
  //buzzer
  
  //if(distance <= 10) {
 //   tone(buzz,1200);
   // digitalWrite(red,HIGH);
   // delay(1000);
  //  noTone(buzz);
  //  digitalWrite(red,LOW);
    
 // }
      
   // }
 


 
  //delay(1000);
}
  //LCD Screen base
  //lcd.setCursor(0,0);
  //lcd.print("Ardiuino");

  //Keypad base 
  //char customKey = customKeypad.getKey();
  //if(customKey) Serial.println(customKey);

 
