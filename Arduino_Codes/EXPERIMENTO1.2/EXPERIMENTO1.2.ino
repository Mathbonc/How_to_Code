void setup(){
    Serial.begin(9600);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
}
void loop(){
  int x=0;
    int i;
    if(Serial.available()>0){
      x = Serial.read();
    Serial.println(x,DEC);
        if(x==48){
            digitalWrite(13,HIGH);
            digitalWrite(12,LOW);
            digitalWrite(11,LOW);
        }else if(x==49){
            digitalWrite(12,HIGH);
            digitalWrite(13,LOW);
            digitalWrite(11,LOW);
        }else if(x==50){
            digitalWrite(11,HIGH);
            digitalWrite(12,LOW);
            digitalWrite(13,LOW);
        }
    }
}
