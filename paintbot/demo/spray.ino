///////////////////////////////////////////////////////////////// SPRAY ///////////////////////////////////////////////////////
void spray() {

//    Serial.println(MiddleMotorEnc.read());
  int encZ = MiddleMotorEnc.read();
  
  EEPROM.write(spray_address, 1);
  while(encZ > -1450)
  {
//    Serial.println(MiddleMotorEnc.read());
    analogWrite(ZMOTOR_A_Output, SRPAY_MAX_VOLTAGE);
    analogWrite(ZMOTOR_B_Output, 0);
    encZ = MiddleMotorEnc.read();  
   // delay(spraySwitchDistance);
  }
    
    analogWrite(ZMOTOR_A_Output, 0);
    analogWrite(ZMOTOR_B_Output, 0);
    Serial.print(MiddleMotorEnc.read());
    Serial.print(","); 
//    Serial.println("");
}

int stopSpraying() {
  int encZ = MiddleMotorEnc.read();
      
  EEPROM.write(spray_address, 0);
  while (encZ < 0)
  {
//    Serial.println(MiddleMotorEnc.read());
    analogWrite(ZMOTOR_A_Output, 0);
    analogWrite(ZMOTOR_B_Output, SRPAY_MAX_VOLTAGE);
    encZ = MiddleMotorEnc.read();
  }
    
    analogWrite(ZMOTOR_A_Output, 0);
    analogWrite(ZMOTOR_B_Output, 0);
    Serial.println(MiddleMotorEnc.read());
//    MiddleMotorEnc.write(0);
    return (1);
}

void main_ZMotor(int click_status, int spin_direction, int power)
{
    while (click_status == CLICKED) {
      spinZMotor(spin_direction, power);
      int released = digitalRead(SW);
      if (released) {
        spinZMotor(Stop, power);
        break;
      }
//    Serial.println(MiddleMotorEnc.read());      
    }
}

void spinZMotor(int turnDirection, int power) {
   //turns in endless circle
   if (turnDirection == CW) {
       analogWrite(ZMOTOR_A_Output, 0);
       analogWrite(ZMOTOR_B_Output, power);
   } else if (turnDirection == CCW) {
       analogWrite(ZMOTOR_A_Output, power);
       analogWrite(ZMOTOR_B_Output, 0);
   } else if (turnDirection == Stop) {
       analogWrite(ZMOTOR_A_Output, 0);
       analogWrite(ZMOTOR_B_Output, 0);
   }
}

void  check_spray_status()
{
//    Serial.print("spray_status=");
//    Serial.println(spray_status);
    if (spray_status == 1) {
      stopSpraying();
      Serial.print("new spray_status=");
      Serial.println(spray_status);
      spray_status = EEPROM.read(spray_address);
    }
}
