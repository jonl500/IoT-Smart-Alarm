#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// Keypad Setup
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// Digital
int red = 0, blue = 1, green = 2; // LED
int echo = 3, trig = 4; // Ping Sensor
int buzz = 5; // Buzzer
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {12, 11, 10};

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
  //lcd.setCursor(0,0);
  //lcd.print("Ardiuino");
}

void loop() {
  
}
  //LCD Screen base
  //lcd.setCursor(0,0);
  //lcd.print("Ardiuino");

  //Keypad base 
  //char customKey = customKeypad.getKey();
  //if(customKey) Serial.println(customKey);

  //Ping Sensor base
  //int duration, distance;
  //digitalWrite(trig,LOW);
  //delayMicroseconds(2);
  //digitalWrite(trig,HIGH);
  //delayMicroseconds(10);
  //digitalWrite(trig,LOW);
  //duration = pulseIn(echo,HIGH);
  //distance = (duration/2)/29.1;
  
  //Buzzer base
  //tone(buzz,1200);
  //noTone(buzz);
