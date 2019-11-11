/*
 *  Based on joystick input value, move the centerpiece up, right, left, down.
 *  @param  VRx           : Joystick x position
 *  @param  VRy           : Joystick y position
 *  @param  encoderLeft   : Left encoder value.
 *  @param  encoderRight  : Right encoder value.
 */

bool joystick(const int VRx, const int VRy, int encoderLeft, int encoderRight)
{
    readX = analogRead(VRx);
    readY = analogRead(VRy);
    while (readX < 300)
    {
      goRight(200);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
    while (readX > 700)
    {
      goLeft(200);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
    while (readY < 300)
    {
      goUp(200);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
    while (readY > 700)
    {
      goDown(200);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
}
© 2019 GitHub, Inc.
