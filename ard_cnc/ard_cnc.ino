#include <Servo.h>
//#include<SoftwareSerial.h>
//
//char readStringEsp();
//char espData;
char command;
Servo myservo;
# define EN 8 // stepper motor enable , active low
# define X_DIR 5 // X -axis stepper motor direction control
# define Y_DIR 6 // y -axis stepper motor direction control
# define X_STP 2 // x -axis stepper control
# define Y_STP 3 // y -axis stepper control

# define pin1 9
# define pin2 10
int pos = 0;
int pin_1;
int pin_2;
void setup () {   // The stepper motor used in the IO pin is set to output
  Serial.begin(9600);
  pinMode (X_DIR, OUTPUT); pinMode (X_STP, OUTPUT);
  pinMode (Y_DIR, OUTPUT); pinMode (Y_STP, OUTPUT);
  pinMode (EN, OUTPUT);
  pinMode (pin1, INPUT);
  pinMode (pin2, INPUT);
  digitalWrite (EN, LOW);
  myservo.attach(11);
  //  pin_1.attach(9);
  //  pin_2.attach(10);
}
// holding the pen up from the paper
void penup() {
  myservo.write(0);
}
// putting the pen down to write
void pendown() {
  for (pos = 0; pos <= 28; pos += 2) {

    myservo.write(pos);
    delay(15);
  }
  delay(500);
}

//void xone(){
//        digitalWrite (X_STP, HIGH);
//        delayMicroseconds (300);
//        digitalWrite (X_STP, LOW);
//        delayMicroseconds (300);
//}
//void yone(){
//        digitalWrite (Y_STP, HIGH);
//        delayMicroseconds (300);
//        digitalWrite (Y_STP, LOW);
//        delayMicroseconds (300);
//}

void stepx(boolean dirx, int StepX) {
  digitalWrite(X_DIR, dirx);
  for (int x = 0; x < StepX; x++)
  {
    // loop for 500 steps
    digitalWrite(X_STP, HIGH);
    delayMicroseconds(200);
    digitalWrite(X_STP, LOW);
    delayMicroseconds(200);
  }
}

void stepy(boolean diry, int StepY) {
  digitalWrite(Y_DIR, diry);
  for (int x = 0; x < StepY; x++)
  {
    // loop for 500 steps
    digitalWrite(Y_STP, HIGH);
    delayMicroseconds(200);
    digitalWrite(Y_STP, LOW);
    delayMicroseconds(200);
  }
}
void stopcnc() {
  digitalWrite(Y_STP, LOW) ;
  digitalWrite(X_STP, LOW);
}
void square() {
  for (int i = 0; i < 5 ; i++) {
    stepy(true, 500);
  }
  for (int i = 0; i < 5 ; i++) {
    stepx(true, 500);
  }
  for (int i = 0; i < 5 ; i++) {
    stepy(false, 500);
  }
  for (int i = 0; i < 5 ; i++) {
    stepx(false, 500);
  }

//  stopcnc();

}
void rec() {
  for (int i = 0; i < 5 ; i++) {
    stepy(true, 500);
  }
  for (int i = 0; i < 5 ; i++) {
    stepx(true, 250);
  }
  for (int i = 0; i < 5 ; i++) {
    stepy(false, 500);
  }
  for (int i = 0; i < 5 ; i++) {
    stepx(false, 250);
  }


}
void triangle() {
  for (int i = 0; i < 80 ; i++) {
    stepy(true, 30);
    stepx(true, 30);
  }
  for (int i = 0; i < 5; i++) {
    stepy(false, 500);
  }
  for (int i = 0; i < 5 ; i++) {
    stepx(false, 500);
  }

//  stopcnc();
}

void cube() {
  rec();
//  for (int i = 0; i < 5 ; i++) {
//    stepy(true, 500);
//  }
 for (int i = 0; i <30 ; i++) {
    stepy(true, 30);
    stepx(true, 30);
  }
//  for (int i = 0; i < 30 ; i++) {
//    stepy(false, 30);
//    stepx(true, 30);
//  }
  rec();

  for (int i = 0; i < 5 ; i++) {
    stepy(true, 500);
  }

  for (int i = 0; i < 30 ; i++) {
    stepy(false, 30);
    stepx(false, 30);
  }

  for (int i = 0; i < 5 ; i++) {
    stepy(false, 500);
  }

  for (int i = 0; i < 5 ; i++) {
    stepx(true, 230);
    
  }

  for (int i = 0; i <30 ; i++) {
    stepy(true, 30);
    stepx(true, 30);
  }

//  stopcnc();
// 

  
//  for (int i = 0; i < 5 ; i++) {
//    stepy(true, 500);
//  }
//  for (int i = 0; i < 30 ; i++) {
//    stepy(true, 30);
//    stepx(false, 30);
//  }
//  for (int i = 0; i < 5 ; i++) {
//    stepx(false, 250);
//  }
//  for (int i = 0; i < 30 ; i++) {
//    stepy(false, 30);
//    stepx(true, 30);
//  }
//  for (int i = 0; i < 5; i++) {
//    stepy(false, 500);
//  }
//  for (int i = 0; i < 40 ; i++) {
//    stepy(true, 30);
//    stepx(false, 30);
//  }


}
void loop () {
  //  cube();
//  Serial.println("void");
  while (!Serial.available()) {}
  command = Serial.read();
  Serial.println("command");
  Serial.println(command);
  switch (command)
  {

    case '0':
      rec();
      //            moveX(true,100,200);

      break;

    case '1':
      //            draw_cube();
      cube();
      delay(500);
      break;

    case '2':
      triangle();
      //            moveY(true,100,200);
      break;

      //  espData = readStringEsp();
//      espData = getshape();
  }
}

//char readStringEsp() {
//  char dataRecieved ;
//  char chBuffer;
//  //  Serial.println("Serial.read()");
//  Serial.println(Serial.read());
//  while (Serial.available() > 0) {
//    Serial.println("Serial is available)");
//    Serial.println(Serial.read());
//    chBuffer =  (char) Serial.read();
//    dataRecieved = chBuffer;
//    Serial.println(dataRecieved);
//    //    return dataRecieved;
//  }
//  return dataRecieved;
//}
//
//char getshape() {
//  pin_1 = digitalRead(pin1);
//  pin_2 = digitalRead(pin2);
//  char dataRecieved ;
//
//  if (pin_1 == 0 and pin_2 == 0)
//  {
//    dataRecieved = 0;
//  }
//  else if (pin_1 == 0 and pin_2 == 1)
//  {
//    dataRecieved = 1;
//  }
//  else if (pin_1 == 1 and pin_2 == 0)
//  {
//    dataRecieved = 2;
//  }
//  else if (pin_1 == 1 and pin_2 == 1)
//  {
//    dataRecieved = 3;
//  }
//
//}
