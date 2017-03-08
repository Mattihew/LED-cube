int colum [9] = {30,32,34,36,38,40,42,44,46};
int row [3] = {48,50,52};
char serialchars[7];
char displaychars[7];
void setup() {
  
  for (int i = 0; i<= 8; i++) {
    if(i <= 2){
     pinMode(row[i],OUTPUT); 
    }
   pinMode(colum[i],OUTPUT); 
  }
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int r = 1;
  while(true){
  if(Serial.available() > 0){
    if(serialchars[0] == char(172)){
      serialchars[r] = Serial.read();
      r++;
    }else{
      serialchars[0] = Serial.read();
      
    }
  }
  
  if(r==7){
    r=1;
    
    
    for (int i = 0; i<=7;i++){
      displaychars[i] = serialchars[i];
     serialchars[i] = char(0); 
    }
  }
  TextParse(displaychars);
  }
  
}


void TextParse(char Layer[7]) {
  boolean Lights[9] [3];
  for (int i = 0; i<=7; i++) {
   Lights[i][0] = bitRead(Layer[1],i);
   Lights[i][1] = bitRead(Layer[3],i);
   Lights[i][2] = bitRead(Layer[5],i);
  }
  Lights[8][0] = bitRead(Layer[2],0);
  Lights[8][1] = bitRead(Layer[4],0);
  Lights[8][2] = bitRead(Layer[6],0);
  
  for (int j = 0; j<=3 ; j++) {
    for (int i = 0; i<=8 ; i++) {
       digitalWrite(colum[i],Lights[i][j]);
    }
    digitalWrite(row[j],HIGH);
    delayMicroseconds(1500);
    digitalWrite(row[j],LOW);
  }
  
}
void toggleLED(int led){
  digitalWrite(led,!digitalRead(led));
}
