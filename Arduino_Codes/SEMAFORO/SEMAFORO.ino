int LEDVm = 5;
int LEDAm = 6;
int LEDVe = 7;

void LuzVerde();
void Luzes();

void setup() {
  Serial.begin(9600);
  pinMode(LEDVm,OUTPUT);
  pinMode(LEDAm,OUTPUT);
  pinMode(LEDVe,OUTPUT);
  pinMode(2,INPUT_PULLUP);
}

void loop(){
  LuzVerde();
  Luzes();
}

void LuzVerde(){
  int i=0,tempo;
  int botao,cont=0,check=0;
  digitalWrite(LEDVe,HIGH);
  while(cont<200 && check!=1){
    delay(100);
    botao = digitalRead(2);
    Serial.println(check);
    if(botao==0){
      check=1;
    }
    cont++;
  }
  Serial.println(check);
  if(check==1){
    tempo=(20000-(100*cont));
    tempo/=2;
    delay(tempo);
  }
  digitalWrite(LEDVe,LOW);
  check=cont =0;
}

void Luzes(){
  digitalWrite(LEDAm,HIGH);
  delay(5000);
  digitalWrite(LEDAm,LOW);
  digitalWrite(LEDVm,HIGH);
  delay(7000);
  digitalWrite(LEDVm,LOW);
}
