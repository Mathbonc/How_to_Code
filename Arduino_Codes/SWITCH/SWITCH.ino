void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop(){
  int botao;
  botao = digitalRead(2);
  
  if(botao==1){
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
  }
  else{
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
  }
}
