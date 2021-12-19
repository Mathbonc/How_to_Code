bool digits[10][7] = {   { 1,1,1,1,1,1,0 },  // = Digito 0
                        { 0,1,1,0,0,0,0 },  // = Digito 1
                        { 1,1,0,1,1,0,1 },  // = Digito 2
                        { 1,1,1,1,0,0,1 },  // = Digito 3
                        { 0,1,1,0,0,1,1 },  // = Digito 4
                        { 1,0,1,1,0,1,1 },  // = Digito 5
                        { 1,0,1,1,1,1,1 },  // = Digito 6
                        { 1,1,1,0,0,0,0 },  // = Digito 7
                        { 1,1,1,1,1,1,1 },  // = Digito 8
                        { 1,1,1,1,0,1,1 },  // = Digito 9
                     };
void SalvarSenha(int *Senha, int i, int *s){
  int a;
  if((*s)<4){
    Senha[*s]=i;
    s++;
  }else if((*s)==4){
    for(a=0;a<4;a++){
      Serial.println(Senha[a]);
    }
  }else{
    Serial.println(-1);
    (*s) = 0;
    delay(1000);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT); //Pino 2 segmento A  
  pinMode(3, OUTPUT); //Pino 3 segmento B  
  pinMode(4, OUTPUT); //Pino 4 segmento F  
  pinMode(5, OUTPUT); //Pino 5 segmento G
  pinMode(6, OUTPUT); //Pino 6 segmento C  
  pinMode(7, OUTPUT); //Pino 7 segmento D  
  pinMode(8, OUTPUT); //Pino 8 segmento E
  
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
}

void loop(){
  int botao1 = digitalRead(9);
  int i;
  static int s=0,Senha[4];
  for(i=0; i<10; i++){
    while(digitalRead(9)==1){
      if(digits[i][0]) digitalWrite(2, HIGH);
      if(digits[i][1]) digitalWrite(3, HIGH);
      if(digits[i][2]) digitalWrite(4, HIGH);
      if(digits[i][3]) digitalWrite(5, HIGH);
      if(digits[i][4]) digitalWrite(6, HIGH);
      if(digits[i][5]) digitalWrite(7, HIGH);
      if(digits[i][6]) digitalWrite(8, HIGH);
      
      if(digitalRead(10)==1){        
        SalvarSenha(Senha, i, &s);
      }
    }
    
  }
}
