int red = 3, blue = 4, green = 5;
int i = 0;
long h = 0;

void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  while(h == 0) {
    h = Serial.parseInt();
    Serial.println(h);
  }
}

void loop() {
  digitalWrite(red,i<4);
  digitalWrite(blue,(i%4)<3);
  digitalWrite(green,(i%2)==0);
  i=(i+1)%8;
  delay(1000);
}

/*void loop() {
  digitalWrite(red,HIGH);
  digitalWrite(blue,HIGH);
  digitalWrite(green,HIGH);
  delay(1000);
  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);
  delay(1000);
}*/
