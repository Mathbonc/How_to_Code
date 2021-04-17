
void setup (){
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(10,INPUT_PULLUP);
}

void loop (){
  int botao;
  botao = digitalRead(10);
  Serial.println(10);

  if(botao==0){
    digitalWrite(8,HIGH);
  }else{
    digitalWrite(8,LOW);
  }
}
