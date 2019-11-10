#include <Encoder.h>
#include <EEPROM.h>

#define SRPAY_MAX_VOLTAGE 255
#define MOTOR_VOLTAGE 200
#define ROTATION_DISTANCE 0.809f
#define WIDTH 93f
#define HEIGHT 66.7f

// Joystic pin number
const int VRx = A1; // Joystick x axis
const int VRy = A0; // Joystick y axis
const int SW = 13; //
//bool swState = false;
//int readX = 500;
//int readY = 500;

// Right encoder pin number
const int encoderRightA = 20; // Green - pin 4 - Digital
const int encoderRightB = 21; // White - pin 5 - Digital

// Left encoder pin number
const int encoderLeftA = 18; // Green - pin 18 - Digital
const int encoderLeftB = 19; // White - pin 19 - Digital

const int RPWMOutputRight = 10; // Arduino PWM output pin 9; connect to IBT-2 pin 1 (RPWM)
const int LPWMOutputRight = 11; // Arduino PWM output pin 10; connect to IBT-2 pin 2 (LPWM)

const int RPWMOutputLeft = 8; // Arduino PWM output pin 5; connect to IBT-2 pin 1 (RPWM)
const int LPWMOutputLeft = 9; // Arduino PWM output pin 6; connect to IBT-2 pin 2 (LPWM)

const int ZMOTOR_A_Output = 6; // Arduino PWM output pin 7; connect to IBT-2 pin 1 (RPWM)
const int ZMOTOR_B_Output = 7; // Arduino PWM output pin 8; connect to IBT-2 pin 2 (LPWM)
const int encoderMidA = 2; // White - pin 2 - Digital
const int encoderMidB = 3; // Tan - pin 3 - Digital
// CW gives positive encoder values
// CCW gives negative encoder values

const int spray_address = 42;
int spray_status = EEPROM.read(spray_address);
long MidEnc_prev = 0;

int spraySwitchDistance = 600;

long encoderLeft = 0;
long encoderRight = 0;
long encoderMiddle = 0;
bool done = false;
long encL = 8000L * 6;
long encR = 6000L * 8;
long encLprev = 0L;
long encRprev = 0L;


// test loop number
int loopNum = 1;

enum turnDirections {
  CW,         // Clockwise
  CCW,         // CounterClockwise
  Stop
};

enum joystickClickStatuses {
  CLICKED, //This value is 0 when switched is clicked
  NOT_CLICKED // This value is 1 when switched is not clicked
};

enum mode_of_machine {
  MOVING,               // For moving centerpiece only
  SQUARE,              // For moving centerpiece and running do_square
  CALLIBRATE_ZMOTOR          // For callibrating zmotor
};

//float rightMotorDistanceTraveled = (fabs(encoderRight / 2400.0)) * ROTATION_DISTANCE;
//float leftMotorDistanceTraveled = (fabs(encoderLeft / 2400.0)) * ROTATION_DISTANCE;

float distL = 0;
float distR = 0;

long prevL = 0;
long prevR = 0;

Encoder leftMotorEnc(encoderLeftA, encoderLeftB);
Encoder rightMotorEnc(encoderRightA, encoderRightB);
Encoder MiddleMotorEnc(encoderMidA, encoderMidB);

///////////////////////////////////////////////////////////////// SETUP ///////////////////////////////////////////////////////
void setup() {
  
  Serial.begin(9600);

  //MOVEMENT MOTORS//
  pinMode(RPWMOutputLeft, OUTPUT);
  pinMode(LPWMOutputLeft, OUTPUT);
  pinMode(RPWMOutputRight, OUTPUT);
  pinMode(LPWMOutputRight, OUTPUT);

  //JOYSTICK//
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT);
  digitalWrite(SW, HIGH);

  //SPRAY//
//  pinMode(encoderZA, INPUT_PULLUP);
//  pinMode(encoderZB, INPUT_PULLUP);
  //Check if Spray nozzle is engaged and set it off
//  spraying = EEPROM.read(sprayStatusCacheAddr);
//  if (spraying) {
//    stopSpraying();
//  }
}
void loop() {
  int turn = digitalRead(SW);
  int mode = SQUARE;

// Make lines of code here:
// If spray_status is on,
//...activate stop_spraying
//...EEPROM.write spray_status = off

  switch (mode) {
    case SQUARE:
    {
//      check_spray_status();
      if (turn)
        joystick(VRx, VRy, encoderLeft, encoderRight);
      else
      {
        while (!done)
        {
          leftMotorEnc.write(0);
          rightMotorEnc.write(0);
          delay(100);
          leftMotorEnc.write(0);
          rightMotorEnc.write(0);
          for (int i = 0; i < loopNum; i++) {
            square(encL *  2.5, encL * 0.5);

            //Test for diagonal movement
//            moveUpRight(200, encL * 5);
//            moveDownLeft(200, encL * 5);
          }
          break ;
        }
      }
      break;
    }
    case CALLIBRATE_ZMOTOR:
//      check_spray_status();
//      Serial.println(abs(MiddleMotorEnc.read()));
      main_ZMotor(digitalRead(SW), CW, SRPAY_MAX_VOLTAGE/2);
      break;
    case MOVING:
//      check_spray_status();
      Serial.println(EEPROM.read(spray_address));
      main_Moving_with_trigger(digitalRead(SW));
      break;
    case 42:
//      check_spray_status();
      if (turn == 0) {
        for (int i = 0; i < loopNum; i++) {
          spray();
          stopSpraying();
        }
      }
//      while (turn == 0) {
//        spray();
//        Serial.print("Are we spraying? = ");
//        Serial.println(EEPROM.read(spray_address));
//        if (digitalRead(SW) == 1)
//          break;
//      }
      break;
  }
}
