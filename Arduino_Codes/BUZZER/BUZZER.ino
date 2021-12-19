int buzzer = 8;
void setup() {
  pinMode(buzzer,OUTPUT);

}

void loop() {
  tone(buzzer,3000);
  delay(500);
  noTone(buzzer);
  delay(500);
}
