int i;
void setup() {
  Serial.begin(9600);
  i = 0;

}

void loop() {
  Serial.println(i++);
  delay(500);
}
