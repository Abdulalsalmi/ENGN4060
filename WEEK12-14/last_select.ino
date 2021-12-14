// we are using D for data which is 68 in ASCI
// we are using R to see if the DE10 lite is ready for the data which is 82
// we will recieve r for  acknowledge from DE10 lite which is 114
// we will recieve d for  acknowledge from DE10 lite which is 100

const int KEY_S1 = 11;  //  Pay attention

int KEY_S1_STATUS = 0;
float pressLength_milliSecond = 0;
int optionOne_milliSecond = 100;
int optionTwo_milliSecond = 700;
int X=A1;
int Y=A0;
int Xval;
int Yval;
int currentMillis; 
bool status = true;
unsigned long previousMillis = 0;
const long interval = 50;
int ss=0;
int buff[6][6] ;

                    
int match[6][6] = {{0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},};
                    
int select[6][6] = {{0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},};
int row,col;
int x_pos = 2;
int y_pos = 2;
int x_pos1;
int y_pos1;
int s_s;
int s;
int score = 0;
int level = 0;
int s_clear = 0;
void setup() {
  // put your setup code here, to run once:
  Serial1.begin(57600);
  SerialUSB.begin(57600);
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(KEY_S1, INPUT_PULLUP);
  
   establishContact(); // send a byte to establish contact till response
}

void loop() {
  
  
  // put your main code here, to run repeatedly:
 
   if(Serial1.available()> 0){ // stuck here till you recive something
   
  s_s=3;
  s_clear = 3;
  int val = Serial1.read();
  if (val == 100){
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
    // save the last time check the signal 
previousMillis = currentMillis;
  Xval=analogRead(X);
  Yval=analogRead(Y);
//1:Not moving

  check:
    // save the last time check the signal 
    previousMillis = currentMillis;
    Xval=analogRead(X);
    Yval=analogRead(Y);
    //2:up
if (Xval > 500 && Xval < 520 && Yval < 495 && y_pos  > 0) {  
  SerialUSB.print (" \n Joystick is moving up");
  y_pos = y_pos-1;
  status = true;
  
}
//3:down
else if (Xval > 500 && Xval < 520 && Yval > 520 && y_pos <5 ) {
  SerialUSB.print (" \n Joystick is moving down");
  y_pos = y_pos+1;
  status = true;
}
//4:Left
else if (Yval > 500 && Yval < 520 && Xval < 500 && x_pos > 0) { 
  SerialUSB.print (" \n Joystick is moving to the left");
  x_pos = x_pos - 1;
  status = true;
  
}
//5:Right
else if (Yval > 500 && Yval < 520 && Xval > 525 && x_pos < 5) { 
  SerialUSB.print (" \n Joystick is moving to the right");
  x_pos = x_pos +1;
  status = true;
}
//6:down-Left
else if (Xval < 500 && Yval > 520 && y_pos < 5 && x_pos > 0) {
  SerialUSB.print (" \n Joystick is moving to down-left");
  x_pos = x_pos -1;
  y_pos = y_pos +1;
  status = true;
}
//7:down-Right
else if (Xval > 520 && Yval > 520 && x_pos <5 && y_pos<5) {
  SerialUSB.print (" \n Joystick is moving to down-right");
  x_pos = x_pos +1;
  y_pos = y_pos +1;
  status = true;
}
//8:up-Left
else if (Xval < 500 && Yval < 500 && x_pos > 0 && y_pos>0) {
  SerialUSB.print (" \n Joystick is moving to up-left");
  x_pos = x_pos -1;
  y_pos = y_pos -1;
  status = true;
}
//9:up-Right
else if (Xval > 520 && Yval < 500 && x_pos<5 && y_pos>0) {
  SerialUSB.print (" \n Joystick is moving to up-right");
  x_pos = x_pos +1;
  y_pos = y_pos -1;
  status = true;
} 
}

 KEY_S1_STATUS = digitalRead (KEY_S1);


 while(digitalRead (KEY_S1) == HIGH)
 {
  delay(100);
  
  pressLength_milliSecond = pressLength_milliSecond +100;
 }
 if (pressLength_milliSecond>=optionTwo_milliSecond ){
  clearing();
  
  
 }
 else if (pressLength_milliSecond>=optionOne_milliSecond){
   if(match[y_pos][x_pos]==1){
    if (select[y_pos][x_pos]==0){
      s_s = 1;
      select[y_pos][x_pos]=1;
   
   status = true;
    }
    else if (select[y_pos][x_pos]==1){
      s_s = 0;
      select[y_pos][x_pos]=0;
      SerialUSB.println("LOW ");
      status = true;
    }
   }
   else if(match[y_pos][x_pos]==0){
    s_s = 0;
    select[y_pos][x_pos]=0;
    status = true;
    }
 }
 
 delayMicroseconds(1000);
 if (status ==false){
    goto check;
  }
    for (row=0;row<7;row++){
      if (row<6){
        Serial1.write(buff[row][0]);
        Serial1.write(buff[row][1]);
        Serial1.write(buff[row][2]);
        Serial1.write(buff[row][3]);
        Serial1.write(buff[row][4]);
        Serial1.write(buff[row][5]);
        SerialUSB.write(buff[row][0]+'0');
        SerialUSB.write(buff[row][1]+'0');
        SerialUSB.write(buff[row][2]+'0');
        SerialUSB.write(buff[row][3]+'0');
        SerialUSB.write(buff[row][4]+'0');
        SerialUSB.write(buff[row][5]+'0');        
        
        delayMicroseconds(1000);
    }
      else{
       x_pos1 = x_pos +'0';
       y_pos1 = y_pos +'0';
       s = s_s + '0';
       Serial1.write(x_pos1);
       Serial1.write(y_pos1);
       Serial1.write(s);
       Serial1.write(s_clear);
       Serial1.write(57);
       Serial1.write(57);
       SerialUSB.write(x_pos1);
       SerialUSB.write(y_pos1);
       SerialUSB.println(s_s+'0');
       SerialUSB.println(s_clear +'0');
       delayMicroseconds(1000);
       }
      }
      
    }
  if ( val == 114 ){
    Serial1.write(68);
    SerialUSB.println(" I send again");
    status = false;
    
    delayMicroseconds(1000);
    }
   }
   pressLength_milliSecond=0;
  
}
void establishContact(){
  if(Serial1.available()<=0){
    
    status = true;
    for ( row = 0; row<6; row++){
      for ( col = 0; col<6; col++){
        
        ss  =random(2);
        buff[row][col]= ss  ;
        
      }
      }
      for ( row = 0; row<6; row++){
      for ( col = 0; col<6; col++){
        if(((buff[row][col]== buff[row][col+1]) && (buff[row][col] == buff[row][col+2])) && (col + 2 <6)){ // horizental matching
          match[row][col]=1;
          match[row][col+1]=1;
          match[row][col+2]=1;
          }
         else if(((buff[row][col]== buff[row+1][col]) && (buff[row][col] == buff[row+2][col])) && (row + 2 <6)){ // vertical matching
          match[row][col]=1;
          match[row+1][col]=1;
          match[row+2][col]=1;
          }
        
        else if(((buff[row][col]== buff[row+1][col]) && (buff[row][col] == buff[row+2][col])) && (row + 2 <6)){ // vertical matching
          match[row][col]=1;
          match[row+1][col]=1;
          match[row+2][col]=1;
          }
         
        else if(buff[row][col]== buff[row+1][col+1] && buff[row][col] == buff[row+2][col+2] && row + 2 <6 && col +2 < 6){ // digonal LR matching
          match[row][col]=1;
          match[row+1][col+1]=1;
          match[row+2][col+2]=1;
          }
        else if(buff[row][col]== buff[row-1][col+1] && buff[row][col] == buff[row-2][col+2] && row - 2 >=0 && col +2 <6){ // digonal RL matching
          match[row][col]=1;
          match[row-1][col+1]=1;
          match[row-2][col+2]=1;
          }
        }
     
      }
    
    Serial1.write(68);
    delay(1000);
    }
  }
  void clearing(){
    SerialUSB.println(" I clearing baby");
    for ( row = 0; row<6; row++){
    
      for ( col = 0; col<6; col++){
        if(((select[row][col]== 1) && (select[row][col+1] == 1)&& (select[row][col+2] == 1)) ){ // horizental matching
          buff[row][col]=9;
          buff[row][col+1]=9;
          buff[row][col+2]=9;
          score = score+3;
          s_clear = 1;
          status = true;
          }
         else if(((select[row][col]== 1) && (select[row+1][col] == 1) && select[row+2][col]==1) ){ // vertical buffing
          buff[row][col]=9;
          buff[row+1][col]=9;
          buff[row+2][col]=9;
          score = score+3;
          s_clear = 1;
          status = true;
          }
        
        
         
        else if(select[row][col]== 1 && select[row+1][col+1]== 1  && select[row+2][col+2]==1){ // digonal LR buffing
          buff[row][col]=9;
          buff[row+1][col+1]=9;
          buff[row+2][col+2]=9;
          score = score+3;
          s_clear = 1;
          status = true;
          }
        else if(select[row][col]== 1 && select[row-1][col+1] == 1 && select[row-2][col+2]==1 ){ // digonal RL buffing
          buff[row][col]=9;
          buff[row-1][col+1]=9;
          buff[row-2][col+2]=9;
          score = score+3;
          s_clear = 1;
          status = true;
          }
        }
     
      }
    
    }
