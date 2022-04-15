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
bool animate = false;
unsigned long previousMillis = 0;
int new_round = 0;
const long interval = 50;
int ss=0;
char buff[6][6] ;
int score_th = 0;
int score_h = 0;
int score_t = 0;
int score_o = 0;
int round_th = 0;
int round_h = 0;
int round_t = 0;
int round_o = 0;
int stat = 0;
bool finish = false;
bool ani_st = false;           
int final_round = 0;
int match[6][6] = {{0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},};
int new_buff[6][6] = {{0, 0, 0, 0, 0, 0},
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
int cont = 0;
int pre_pos = 0;
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

  check:
    // save the last time check the signal 
    previousMillis = currentMillis;
    Xval=analogRead(X);
    Yval=analogRead(Y);
    //2:up
if (Xval > 500 && Xval < 530 && Yval < 500 && y_pos  > 0 && pre_pos != 1) {  
  SerialUSB.print (" \n Joystick is moving up");
  y_pos = y_pos-1;
  status = true;
  pre_pos = 1;   // state 1
  if (stat !=1){
    stat=3; 
  }
  
}
else if (Xval > 500 && Xval < 530 && Yval > 500 && Yval < 530 && pre_pos != 0){
  y_pos = y_pos;
  x_pos = x_pos;
  pre_pos = 0;
  SerialUSB.print (" \n Joystick is moving still");
  }
//3:down
else if (Xval > 500 && Xval < 530 && Yval > 530 && y_pos <5 && pre_pos != 2) {
  SerialUSB.print (" \n Joystick is moving down");
  y_pos = y_pos+1;
  status = true;
  pre_pos = 2;
    if (stat !=1){
    stat=3; 
  }
}
//4:Left
else if (Yval > 500 && Yval < 530 && Xval < 500 && x_pos > 0 && pre_pos != 3) { 
  SerialUSB.print (" \n Joystick is moving to the left");
  x_pos = x_pos - 1;
  status = true;
  pre_pos = 3;
    if (stat !=1){
    stat=3; 
  }
}
//5:Right
else if (Yval > 500 && Yval < 530 && Xval > 540 && x_pos < 5&& pre_pos != 4) { 
  SerialUSB.print (" \n Joystick is moving to the right");
  x_pos = x_pos +1;
  status = true;
  pre_pos = 4;
    if (stat !=1){
    stat=3; 
  }
}
/*
//6:down-Left
else if (Xval < 500 && Yval > 520 && y_pos < 5 && x_pos > 0 && pre_pos != 5) {
  SerialUSB.print (" \n Joystick is moving to down-left");
  x_pos = x_pos -1;
  y_pos = y_pos +1;
  status = true;
  pre_pos = 5;
}
//7:down-Right
else if (Xval > 520 && Yval > 520 && x_pos <5 && y_pos<5 && pre_pos != 6) {
  SerialUSB.print (" \n Joystick is moving to down-right");
  x_pos = x_pos +1;
  y_pos = y_pos +1;
  status = true;
  pre_pos = 6;
}
//8:up-Left
else if (Xval < 500 && Yval < 500 && x_pos > 0 && y_pos>0 && pre_pos != 7) {
  SerialUSB.print (" \n Joystick is moving to up-left");
  x_pos = x_pos -1;
  y_pos = y_pos -1;
  status = true;
  pre_pos = 7;
}
//9:up-Right
else if (Xval > 520 && Yval < 500 && x_pos<5 && y_pos>0&& pre_pos != 8) {
  SerialUSB.print (" \n Joystick is moving to up-right");
  x_pos = x_pos +1;
  y_pos = y_pos -1;
  status = true;
  pre_pos = 8;
}
*/ 
}

 KEY_S1_STATUS = digitalRead (KEY_S1);


 while(digitalRead (KEY_S1) == HIGH)
 {
  delay(100);
  
  pressLength_milliSecond = pressLength_milliSecond +100;
 }
 if (pressLength_milliSecond>=optionTwo_milliSecond ){
  
  clearing();
  stat = 2;
  
 }
 else if (pressLength_milliSecond>=optionOne_milliSecond){
   selection();
   stat = 1;
 }
 
 delayMicroseconds(1000);
 
 if (ani_st == true && new_round == 4 ){
    delay(750);
    animation();
    status = true;
    
  }
 if (animate == true && new_round == 5 ){
    delay(750);
    generate();
    status = true;
    
  }
 if (status ==false && new_round > 6 && ani_st == false ){
    goto check;
  }
 
    for (row=0;row<9;row++){
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
      if(row ==6){
       x_pos1 = x_pos +'0';
       y_pos1 = y_pos +'0';
       s = s_s + '0';
       
       Serial1.write(x_pos1);
       Serial1.write(y_pos1);
       Serial1.write(s);
       Serial1.write(s_clear);
       Serial1.write(score_th);
       Serial1.write(score_h);
       SerialUSB.write(x_pos1);
       SerialUSB.write(y_pos1);
       delayMicroseconds(1000);
       }
      if(row ==7) {
       
       
       Serial1.write(score_t);
       Serial1.write(score_o);
       Serial1.write(round_th);
       Serial1.write(round_h);
       Serial1.write(round_t);
       Serial1.write(round_o);
       delayMicroseconds(1000);
        }
        if(row ==8) {
       
       
       Serial1.write(stat);
       Serial1.write(9);
       Serial1.write(9);
       Serial1.write(9);
       Serial1.write(9);
       Serial1.write(9);
       delayMicroseconds(1000);
        }     
      }
      
    }
  if ( val == 114 ){
    
    Serial1.write(68);
    SerialUSB.println(" I send again");
    status = false;
    new_round = new_round +1;
    cont = cont+1;
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
        
        ss  =random(4);
        buff[row][col]= ss  ;
        
      }
      }
      
    
    Serial1.write(68);
    
    }
  }
  void selection(){
    for ( row = 0; row<6; row++){
      for ( col = 0; col<6; col++){
        if (buff[row][col] != 9) {
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
        if (buff[row][col] == 9){
          match[row][col]=0;
        }
      }
      }
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
  void clearing(){
    SerialUSB.println(" I clearing baby");
    for ( row = 0; row<6; row++){  
      for ( col = 0; col<6; col++){
        if (buff[row][col]!=9){
        if(((select[row][col]== 1) && (select[row][col+1] == 1)&& (select[row][col+2] == 1)) ){ // horizental matching
          if(((buff[row][col]== buff[row][col+1]) && (buff[row][col] == buff[row][col+2])) && (col + 2 <6)){ // horizental matching
          new_buff[row][col]=9;
          new_buff[row][col+1]=9;
          new_buff[row][col+2]=9;
          new_round = 2;
          s_clear = 1;
          ani_st = true;
          status = true;
          }
          }
         else if(((select[row][col]== 1) && (select[row+1][col] == 1) && select[row+2][col]==1) ){ // vertical buffing
          if(((buff[row][col]== buff[row+1][col]) && (buff[row][col] == buff[row+2][col])) && (row + 2 <6)){ // vertical matching
          new_buff[row][col]=9;
          new_buff[row+1][col]=9;
          new_buff[row+2][col]=9;
          new_round = 2;
          ani_st = true;
          s_clear = 1;
          
          status = true;
          }
          }
        
        
         
        else if(select[row][col]== 1 && select[row+1][col+1]== 1  && select[row+2][col+2]==1){ // digonal LR buffing
          if(buff[row][col]== buff[row+1][col+1] && buff[row][col] == buff[row+2][col+2] && row + 2 <6 && col +2 < 6){ // digonal LR matching
          new_buff[row][col]=9;
          new_buff[row+1][col+1]=9;
          new_buff[row+2][col+2]=9;
          new_round = 2;
          ani_st = true;
          s_clear = 1;
          status = true;
          }
          }
        else if(select[row][col]== 1 && select[row-1][col+1] == 1 && select[row-2][col+2]==1 ){ // digonal RL buffing
          if(buff[row][col]== buff[row-1][col+1] && buff[row][col] == buff[row-2][col+2] && row - 2 >=0 && col +2 <6){ // digonal RL matching
          new_buff[row][col]=9;
          new_buff[row-1][col+1]=9;
          new_buff[row-2][col+2]=9;
          new_round = 2;
          ani_st = true;
          s_clear = 1;
          status = true;
          }
          }
        }
        }
     
      }
        for ( row = 0; row<6; row++){  
      for ( col = 0; col<6; col++){
        if(new_buff[row][col]==9){
          buff[row][col]=9;
        }
      }
      }
    }
 
void animation(){
       
      for (int con = 0; con <5; con ++){
      for (row =5; row >=0; row--){
        for (col = 0; col <6 ; col++){
          match[row][col]=0;
          select[row][col]=0;
          
          if (buff[row][col]==9 && row >0){
            buff[row][col]= buff[row-1][col];
            buff[row-1][col]=9; 
            status = true;
            ani_st = false;
            animate = true;
            }
          }
        }
        
   }
  
 
}
void generate(){
  for ( row = 0; row<6; row++){  
      for ( col = 0; col<6; col++){
        new_buff[row][col]=0;
        if (buff[row][col]==9){
          score = score + 1;
          buff[row][col] = random(4);
          
        }
      }
      }
      stat=5;
      status = true;
      finish = true;
      final_round= final_round+1;
      score_th = score/1000;
      score_h = (score - (score_th*1000)) / 100;
      score_t = (score - ((score_th* 1000) + (score_h*100))) / 10;
      score_o = (score -((score_th* 1000) + (score_h*100)+ (score_t*10))) / 1;
      SerialUSB.print(" Score is  ");
      SerialUSB.println(score);
      round_th = final_round/1000;
      round_h = (final_round - (round_th*1000)) / 100;
      round_t = (final_round - ((round_th* 1000) + (round_h*100))) / 10;
      round_o = (final_round -((round_th* 1000) + (round_h*100)+ (round_t*10))) / 1;
      SerialUSB.print(" round is  ");
      SerialUSB.println(final_round);
      game_over();
}
void game_over(){
      for ( row = 0; row<6; row++){
      for ( col = 0; col<6; col++){
          if(((buff[row][col]== buff[row][col+1]) && (buff[row][col] == buff[row][col+2])) && (col + 2 <6)){ // horizental matching
          finish = false;
          }
         else if(((buff[row][col]== buff[row+1][col]) && (buff[row][col] == buff[row+2][col])) && (row + 2 <6)){ // vertical matching
          finish = false;
          }
        else if(buff[row][col]== buff[row+1][col+1] && buff[row][col] == buff[row+2][col+2] && row + 2 <6 && col +2 < 6){ // digonal LR matching
          finish = false;
          }
        else if(buff[row][col]== buff[row-1][col+1] && buff[row][col] == buff[row-2][col+2] && row - 2 >=0 && col +2 <6){ // digonal RL matching
          finish = false;
          }
      }
      }
      if (finish == true){
        stat = 4;
      }
  }
