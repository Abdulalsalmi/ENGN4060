// we are using D for data which is 68 in ASCI
// we are using R to see if the DE10 lite is ready for the data which is 82
// we will recieve r for  acknowledge from DE10 lite which is 114
// we will recieve d for  acknowledge from DE10 lite which is 100





void setup() {
  // put your setup code here, to run once:
  Serial1.begin(57600);
  SerialUSB.begin(57600);
  while(!Serial1){
    // wait till connected
    }
   establishContact(); // send a byte to establish contact till response
}

void loop() {
  
  int ss=0;
  int buff[7][6];
  int row,col;
  // put your main code here, to run repeatedly:
 
   if(Serial1.available()> 0){ // stuck here till you recive something 
  int val = Serial1.read();
  if (val == 100){
    for ( row = 0; row<7; row++){
      for ( col = 0; col<6; col++){
        ss  =random(6);
        buff[row][col]= ss + '0' ;
        }
     
      }
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
      else if (row ==6){
       Serial1.write(57);
       Serial1.write(57);
       Serial1.write(57);
       Serial1.write(57);
       Serial1.write(57);
       Serial1.write(57);
       SerialUSB.write(57);
       SerialUSB.write(57);
       SerialUSB.write(57);
       SerialUSB.write(57);
       SerialUSB.write(57);
       SerialUSB.write(57);
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
    }
  }
