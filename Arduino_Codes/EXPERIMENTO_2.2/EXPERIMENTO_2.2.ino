void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop()
{
  int i;
  for(i=2;i<7;i++){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
  }
  for(i=7;i>2;i--){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
  }
}
