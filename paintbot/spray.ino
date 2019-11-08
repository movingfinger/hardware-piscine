///////////////////////////////////////////////////////////////// SPRAY ///////////////////////////////////////////////////////
void spray() {

//    EEPROM.write(sprayStatusCacheAddr, 1);  
    analogWrite(ZMOTOR_A_Output, SRPAY_MAX_VOLTAGE);
    analogWrite(ZMOTOR_B_Output, 0);
    
    delay(spraySwitchDistance);
    
    analogWrite(ZMOTOR_A_Output, 0);
    analogWrite(ZMOTOR_B_Output, 0);
}

int stopSpraying() {

//    EEPROM.write(sprayStatusCacheAddr, 0);  
    analogWrite(ZMOTOR_A_Output, 0);
    analogWrite(ZMOTOR_B_Output, SRPAY_MAX_VOLTAGE);

    delay(spraySwitchDistance * 1); //0.872);           // This is the voltage power needed for consistent on-off positions

    analogWrite(ZMOTOR_A_Output, 0);
    analogWrite(ZMOTOR_B_Output, 0);

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
