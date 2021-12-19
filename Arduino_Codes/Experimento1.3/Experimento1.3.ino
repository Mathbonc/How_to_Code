int buzzer = 8;
void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(2,INPUT);
}

void loop() {
  int botao;
  botao = digitalRead(2);
  Serial.println(botao);
  if(botao==1){
    tone(buzzer,1000);
    delay(500);
    noTone(buzzer);
  }
}
