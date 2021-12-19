void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  int x,i,cont=0;
  x = analogRead(A0);
  Serial.println(x);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  for(i=0;i<5;i++){
    x = analogRead(A0);
    if(600<=x && x<=700){
       cont++;
        delay(1000);
        Serial.println(x);
    }else{
      cont=0;
        break;
    }
  }
  if(cont==5){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    delay(10000);
  }
}
