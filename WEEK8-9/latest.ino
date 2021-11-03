// we are using D for data which is 68 in ASCI
// we are using R to see if the DE10 lite is ready for the data which is 82
// we will recieve r for  acknowledge from DE10 lite which is 114
// we will recieve d for  acknowledge from DE10 lite which is 100

int X=A1;
int Y=A0;
int Xval;
int Yval;
int currentMillis; 
unsigned long previousMillis = 0;
const long interval = 50;
int ss=0;
int buff[7][6];
int row,col;
int x_pos = 2;
int y_pos = 2;
int x_pos1;
int y_pos1;


void setup() {
  // put your setup code here, to run once:
  Serial1.begin(57600);
  SerialUSB.begin(57600);
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  while(!Serial1){
    // wait till connected
    }
   establishContact(); // send a byte to establish contact till response
}

void loop() {
  
  
  // put your main code here, to run repeatedly:
 
   if(Serial1.available()> 0){ // stuck here till you recive something
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
    // save the last time check the signal 
previousMillis = currentMillis;
  Xval=analogRead(X);
  Yval=analogRead(Y);
//1:Not moving


    // save the last time check the signal 
    previousMillis = currentMillis;
    Xval=analogRead(X);
    Yval=analogRead(Y);
    //2:up
if (Xval > 500 && Xval < 520 && Yval < 495 && y_pos  > 0) {  
  SerialUSB.print (" \n Joystick is moving up");
  y_pos = y_pos-1;
  
}
//3:down
else if (Xval > 500 && Xval < 520 && Yval > 510 && y_pos <5 ) {
  SerialUSB.print (" \n Joystick is moving down");
  y_pos = y_pos+1;
  
}
//4:Left
else if (Yval > 500 && Yval < 520 && Xval < 500 && x_pos > 0) { 
  SerialUSB.print (" \n Joystick is moving to the left");
  x_pos = x_pos - 1;
  
  
}
//5:Right
else if (Yval > 500 && Yval < 520 && Xval > 520 && x_pos < 5) { 
  SerialUSB.print (" \n Joystick is moving to the right");
  x_pos = x_pos +1;
  
}
//6:down-Left
else if (Xval < 500 && Yval > 520 && y_pos < 5 && x_pos > 0) {
  SerialUSB.print (" \n Joystick is moving to down-left");
  x_pos = x_pos -1;
  y_pos = y_pos +1;
  
}
//7:down-Right
else if (Xval > 520 && Yval > 520 && x_pos <5 && y_pos<5) {
  SerialUSB.print (" \n Joystick is moving to down-right");
  x_pos = x_pos +1;
  y_pos = y_pos +1;
  
}
//8:up-Left
else if (Xval < 500 && Yval < 500 && x_pos > 0 && y_pos>0) {
  SerialUSB.print (" \n Joystick is moving to up-left");
  x_pos = x_pos -1;
  y_pos = y_pos -1;
  
}
//9:up-Right
else if (Xval > 520 && Yval < 500 && x_pos<5 && y_pos>0) {
  SerialUSB.print (" \n Joystick is moving to up-right");
  x_pos = x_pos +1;
  y_pos = y_pos -1;
  
}
  
}
  int val = Serial1.read();
  if (val == 100){
    for (row=0;row<7;row++){
      if (row<6){
        Serial1.write(buff[row][0]);
        Serial1.write(buff[row][1]);
        Serial1.write(buff[row][2]);
        Serial1.write(buff[row][3]);
        Serial1.write(buff[row][4]);
        Serial1.write(buff[row][5]);
        SerialUSB.write(buff[row][0]);
        SerialUSB.write(buff[row][1]);
        SerialUSB.write(buff[row][2]);
        SerialUSB.write(buff[row][3]);
        SerialUSB.write(buff[row][4]);
        SerialUSB.write(buff[row][5]);        
        
        delayMicroseconds(500);
    }
      else{
       x_pos1 = x_pos +'0';
       y_pos1 = y_pos +'0';
       Serial1.write(x_pos1);
       Serial1.write(y_pos1);
       Serial1.write(57);
       Serial1.write(57);
       Serial1.write(57);
       Serial1.write(57);
       SerialUSB.write(x_pos);
       SerialUSB.write(y_pos);
       delayMicroseconds(500);
       }
      }
      val = 0;
    }
  if ( val == 114){
    Serial1.write(68);
    SerialUSB.println(" I send again");
    val = 0;
    }
   }
}
void establishContact(){
  if(Serial1.available()<=0){
    Serial1.write(68);
    delay(2000);
    for ( row = 0; row<7; row++){
      for ( col = 0; col<6; col++){
        ss  =random(6);
        buff[row][col]= ss + '0' ;
        }
     
      }
    
    }
  }
