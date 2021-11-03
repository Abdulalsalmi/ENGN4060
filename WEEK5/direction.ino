int X=A1;
int Y=A0;
int Xval;
int Yval;
int x_pos =2;
int y_pos =2;
int currentMillis; 
unsigned long previousMillis = 0;
const long interval = 50;
// interval 20 times per sec 
void setup() {
  // put your setup code here, to run once:
SerialUSB.begin(9600);
pinMode(X, INPUT);
pinMode(Y, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
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
    //2:down
if (Xval > 490 && Xval < 540 && Yval < 480 && y_pos>0) {  
  SerialUSB.println(" \n Joystick is moving down");
  y_pos=y_pos-1;
  SerialUSB.print(" x pos = ");
  SerialUSB.println(x_pos);
  SerialUSB.print(" y pos = ");
  SerialUSB.println(y_pos);
}
//3:up 
else if (Xval > 490 && Xval < 540 && Yval > 540 && y_pos < 5) {
  SerialUSB.println(" \n Joystick is moving up");
  y_pos = y_pos+1;
  SerialUSB.print(" x pos = ");
  SerialUSB.println(x_pos);
  SerialUSB.print(" y pos = ");
  SerialUSB.println(y_pos);
}
//4:Left
else if (Yval > 490 && Yval < 540 && Xval < 480 && x_pos > 0) { 
  SerialUSB.println(" \n Joystick is moving to the left");
  x_pos = x_pos - 1;
  SerialUSB.print(" x pos = ");
  SerialUSB.println(x_pos);
  SerialUSB.print(" y pos = ");
  SerialUSB.println(y_pos);
  
}
//5:Right
else if (Yval > 490 && Yval < 540 && Xval > 540 && x_pos < 5) { 
  SerialUSB.println(" \n Joystick is moving to the right");
  x_pos = x_pos +1;
  SerialUSB.print(" x pos = ");
  SerialUSB.println(x_pos);
  SerialUSB.print(" y pos = ");
  SerialUSB.println(y_pos);
}
//6:down-Left
else if (Xval < 480 && Yval > 540 && y_pos < 5 && x_pos > 0) {
  SerialUSB.println(" \n Joystick is moving to up-left");
  x_pos = x_pos -1;
  y_pos = y_pos +1;
  SerialUSB.print(" x pos = ");
  SerialUSB.println(x_pos);
  SerialUSB.print(" y pos = ");
  SerialUSB.println(y_pos);
}
//7:down-Right
else if (Xval > 540 && Yval > 540 && x_pos <5 && y_pos>0) {
  SerialUSB.println(" \n Joystick is moving to up-right");
  x_pos = x_pos +1;
  y_pos = y_pos -1;
  SerialUSB.print(" x pos = ");
  SerialUSB.println(x_pos);
  SerialUSB.print(" y pos = ");
  SerialUSB.println(y_pos);
}
//8:up-Left
else if (Xval < 480 && Yval < 480 && x_pos > 0 && y_pos>0) {
  SerialUSB.println(" \n Joystick is moving to down-left");
  x_pos = x_pos -1;
  y_pos = y_pos -1;
  SerialUSB.print(" x pos = ");
  SerialUSB.println(x_pos);
  SerialUSB.print(" y pos = ");
  SerialUSB.println(y_pos);
}
//9:up-Right
else if (Xval > 540 && Yval < 480 && x_pos<5 && y_pos>0) {
  SerialUSB.println(" \n Joystick is moving to down-right");
  x_pos = x_pos +1;
  y_pos = y_pos -1;
  SerialUSB.print(" x pos = ");
  SerialUSB.println(x_pos);
  SerialUSB.print(" y pos = ");
  SerialUSB.println(y_pos);
}
   
}
}
