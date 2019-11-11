/*
 *  Based on joystick input value, move the centerpiece up, right, left, down.
 *  @param  VRx           : Joystick x pin number
 *  @param  VRy           : Joystick y pin number
 *  @param  encoderLeft   : Left encoder value.
 *  @param  encoderRight  : Right encoder value.
 */

void joystick(const int VRx, const int VRy, int encoderLeft, int encoderRight)
{
  int readX = 500;
  int readY = 500;
  
  readX = analogRead(VRx);
  readY = analogRead(VRy);
  while (readX < 300)
  {
    goRight(200, 200);
    readX = analogRead(VRx);
    readY = analogRead(VRy);
  }
  doStop();
  while (readX > 700)
  {
    goLeft(200, 200);
    readX = analogRead(VRx);
    readY = analogRead(VRy);
  }
  doStop();
  while (readY < 300)
  {
    goUp(200, 200);
    readX = analogRead(VRx);
    readY = analogRead(VRy);
  }
  doStop();
  while (readY > 700)
  {
    goDown(200, 200);
    readX = analogRead(VRx);
    readY = analogRead(VRy);
  }
  doStop();
}
