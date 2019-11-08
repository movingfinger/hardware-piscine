///////////////////////////////////////////////////////////////// SQUARE ///////////////////////////////////////////////////////
/*
 *  Move left until both encoder values meet more than pos value.
 *  @param  volL : Voltage to control the left motor speed 
 *  @param  volR : Voltage to control the right motor speed 
 *  @param  pos  : Encoder value we want to move.
 */
 
void moveLeft(int volL, int volR, long pos)
{
  while (1)
  {
    goLeft_v2(volL, volR);   //155, 100
//    Serial.print(leftMotorEnc.read());
//    Serial.print(" - ");
//    Serial.println(RightMotorEnc);
    encoderLeft = leftMotorEnc.read();
    encoderRight = rightMotorEnc.read();
    if ((encoderLeft < -pos) && (encoderRight < -pos))
    {
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}
​
/*
 *  Move down until both encoder values meet more than pos value.
 *  @param  volL : Voltage to control the left motor speed 
 *  @param  volR : Voltage to control the right motor speed 
 *  @param  pos  : Encoder value we want to move.
 */
​
void moveDown(int volL, int volR, long posH)
{
  while (1)
  {
    goDown_v2(volL, volR);
//    Serial.print(leftMotorEnc.read());
//    Serial.print(" - ");
//    Serial.println(encoderRight);
    encoderLeft = leftMotorEnc.read();
    encoderRight = rightMotorEnc.read();
    if ((encoderLeft > posH) && (encoderRight < -posH))
    {
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}
​
/*
 *  Move right until both encoder values meet more than pos value.
 *  @param  volL : Voltage to control the left motor speed 
 *  @param  volR : Voltage to control the right motor speed 
 *  @param  pos  : Encoder value we want to move.
 */
 
void moveRight(int volL, int volR, long pos)
{
  while (1)
  {
    goRight_v2(volL, volR); //100 : 150
//    Serial.print(leftMotorEnc.read());
//    Serial.print(" - ");
//    Serial.println(encoderRight);
    encoderLeft = leftMotorEnc.read();
    encoderRight = rightMotorEnc.read();
    if ((encoderLeft > pos) && (encoderRight > pos))
    {
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}
​
////////////////////////////////////////////////////////////// SQUARE v4 /////////////////////////////////////////////////////////
​
/*
 *  Make path for painting 3ft by 2ft square. The square root for this function is written as below,
  1. Left
  2. Down
  3. Right
  4. Down
  5. Left
  6. Down
  7. Right
  8. Down
  9. Left
 *  @param posW : Encoder values for moving side way.
 *  @param posH : Encoder values for moving down way.
*/
void square_v4(long pos, long posH)
{
  spray();
  moveLeft(230, 130, pos * 1.3);
  moveLeft(210, 130, pos * 1);
​
  while (1) {
    if (stopSpraying()) {
      break ;
    }
  }
      
  moveDown(200, 140, posH * 0.35);
    
  spray();
  moveRight(140, 200, pos * 1);
  moveRight(150, 180, pos * 1);
​
  while (1) {
    if (stopSpraying()) {
      break ;
    }
  }
​
  moveDown(140, 230, posH * 0.85);
​
  spray();
  moveLeft(180, 170, pos * 1);
  moveLeft(160, 170, pos * 1);
​
  while (1) {
    if (stopSpraying()) {
      break ;
    }
  }
    
  moveDown(200, 140, posH * 0.7);
  spray();
  moveRight(140, 180, pos * 1);
  moveRight(150, 140, pos * 0.6);
​
  while (1) {
    if (stopSpraying()) {
      break ;
    }
  }
​
  moveDown(140, 230, posH * 0.85);
  
  spray();
  moveLeft(160, 170, pos * 1);
  moveLeft(150, 190, pos * 0.6);
​
  while (1) {
    if (stopSpraying()) {
      break ;
    }
  }
  doStop();
}
