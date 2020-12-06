#include <LiquidCrystal_I2C.h>

// Digital
int red = 7, blue = 5, green = 6; // LED
int echo = 3, trig = 4; // Ping Sensor
int buzz = 10; // Buzzer
int button = 9; // Button
// Analog
LiquidCrystal_I2C lcd(0x27,16,2); // LCD Screen
int lit = 2; // Motion Sensor

int qwe;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  //pinMode(lit,INPUT);
  pinMode(button,INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  //lcd.print("Ardiuino");
}

void loop() {
  int duration, distance;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration/2)/29.1;
  Serial.print("Distance ");
  Serial.print(distance);
  Serial.println(" cm");
  
  int buttonState = digitalRead(button);
  if(buttonState==HIGH){
    digitalWrite(green,HIGH);
    lcd.print("alarm arming ");
    //delay(1000);
  }else{
    digitalWrite(green,LOW);
  }
  
  if(distance <= 10) {
    tone(buzz,1200);
    digitalWrite(red,HIGH);
    delay(1000);
    noTone(buzz);
    digitalWrite(red,LOW);
  }
 
  //if(analogRead(button) < 200) qwe = 1;
  //else qwe = 0;
  //Serial.print(qwe);
  Serial.print(digitalRead(button));
  Serial.print(" - ");
  //Serial.println(analogRead(lit));
  delay(1000);

}
