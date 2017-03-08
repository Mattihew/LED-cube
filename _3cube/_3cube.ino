int colums [3] [3] = {{31,33,35},{37,39,41},{43,45,47}};
int rows [3] = {53,51,49};
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i <= 3; i++){
    for(int j = 0; j<= 3; j++){
      pinMode(colums[i][j],OUTPUT);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
 for ( int i = 0; i <=7 ; i++){
   for ( int j = 0; j <= 50; j++){
    spin(i);
    
   }
  
 } 
  
}

void LEDon(int x, int y, int z){
  digitalWrite(colums[x][y],HIGH);
  digitalWrite(rows[z],HIGH);  
}
void LEDoff(int x, int y, int z){
  digitalWrite(colums[x][y],LOW);
  digitalWrite(rows[z],LOW);
}
void ColumOn(int x, int y){
 digitalWrite(colums[x][y],HIGH); 
}
void ColumOff(int x, int y){
 digitalWrite(colums[x][y],LOW); 
}
void RowOn(int z){
 digitalWrite(rows[z],HIGH); 
}
void RowOff(int z){
 digitalWrite(rows[z],LOW); 
}
int numloop(int value,int offset ,int maxval){
  int retval;
  retval = value + offset;
  if(retval >= maxval){
   retval -= maxval; 
  }
  return retval;
}
// animations

void cycle() {
 
  int i  = 0;
  int j = 0;
  int k = 0;
  while(true){
    LEDon(i,j,k);
    delay(105);
    LEDoff(i,j,k);
    i++;
    if(i==3){
      i=0;
      j++; 
    }
    if(j==3){
      j=0;
      k++; 
    }
    if(k==3){
      k=0; 
    }
  } 
}

void spin(int frame){
  int frame2;
  frame2 = numloop(frame,4,8);
  int pattern [8] [2] = {{0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{1,0}};
  
  // top layer
  ColumOn(pattern[frame][0],pattern[frame][1]);
  ColumOn(pattern[frame2][0],pattern[frame2][1]);
  RowOn(2);
  delay(1);
  ColumOff(pattern[frame][0],pattern[frame][1]);
  ColumOff(pattern[frame2][0],pattern[frame2][1]);
  RowOff(2);
  // middle layer
  ColumOn(pattern[numloop(frame,1,8)][0],pattern[numloop(frame,1,8)][1]);
  ColumOn(pattern[numloop(frame2,1,8)][0],pattern[numloop(frame2,1,8)][1]);
  RowOn(1);
  delay(1);
  ColumOff(pattern[numloop(frame,1,8)][0],pattern[numloop(frame,1,8)][1]);
  ColumOff(pattern[numloop(frame2,1,8)][0],pattern[numloop(frame2,1,8)][1]);
  RowOff(1);
  //Bottom layer
  ColumOn(pattern[numloop(frame,2,8)][0],pattern[numloop(frame,2,8)][1]);
  ColumOn(pattern[numloop(frame2,2,8)][0],pattern[numloop(frame2,2,8)][1]);
  RowOn(0);
  delay(1);
  ColumOff(pattern[numloop(frame,2,8)][0],pattern[numloop(frame,2,8)][1]);
  ColumOff(pattern[numloop(frame2,2,8)][0],pattern[numloop(frame2,2,8)][1]);
  RowOff(0);
  
}
