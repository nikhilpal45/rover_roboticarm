#include<Servo.h>
#include <SoftwareSerial.h>
char state;
int motorPin1 = 2;//right side wheels
int motorPin2 = 3;//right side wheels
int motorPin3 = 4;//left side wheels
int motorPin4 = 5;//left side wheels
Servo myservo1;//base servo motor
Servo myservo2;//arm servo motor
int pos1 = 90; //default position
int pos2 = 90; //default position
//connect Rx to 10 of bluetooth module
//connect Tx to 11 of bluetooth module
int bluetoothTx = 10;//act as transmitter for ardiono
int bluetoothRx = 11;//act as reciever for arduino
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
void setup()
{
  myservo1.attach(6);//connect base servo motor to pin 6
  myservo2.attach(7);//connect arm servo motor to pin 7
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
  myservo1.write(pos1);
  myservo2.write(pos2);
}

void forward()//forward
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(100);
  reset();
}
void backward()//backward
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(100);
  reset();
}
void right()//right
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(100);
  reset();
}
void left()//left
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(100);
  reset();
}
void reset()//to stop the rover
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}

void arm1down()
{
  if (pos1 < 0)
  {
    pos1 = 0;
  }
  else if (pos1 > 180)
  {
    pos1 = 180;
  }
  myservo1.write(pos3--);
  delay(10);
}
void arm1up()
{
  if (pos1 < 0)
  {
    pos1 = 0;
  }
  else if (pos1 > 180)
  {
    pos1 = 180;
  }
  myservo1.write(pos1++);
  delay(10);
}
void arm2up()
{
  if (pos2 < 0)
  {
    pos2 = 0;
  }
  else if (pos2 > 180)
  {
    pos2 = 180;
  }
  myservo2.write(pos2++);
  delay(10);
}
void arm2down()
{
  if (pos2 < 0)
  {
    pos2 = 0;
  }
  else if (pos2 > 180)
  {
    pos2 = 180;
  }
  myservo2.write(pos2--);
  delay(10);
}

void loop()
{
  if (bluetooth.available() > 0)
  {
    state = bluetooth.read();
  }
  switch (state)
  {
    case '1' :
      do
      {
        arm1up();
      } while (bluetooth.read() == '1');
      break;
    case '9' :
      do
      {
        arm1down();
      } while (bluetooth.read() == '9');
      break;
    case '3' :
      do
      {
        arm2up();
      } while (bluetooth.read() == '3');
      break;
    case '7' :
      do
      {
        arm2down();
      } while (bluetooth.read() == '7');
      break;
   
    case '8':
      do
      {
        backward();
      } while (bluetooth.read() == '8');
      reset();
      break;
    case '2':
      do
      {
        forward();
      } while (bluetooth.read() == '2');
      reset();
      break;
    case '6':
      do
      {
        right();
      } while (bluetooth.read() == '6');
      delay(10);
      break;
    case '4':
      do
      {
        left();
      } while (bluetooth.read() == '4');
      delay(10);
      break;
  }
}

