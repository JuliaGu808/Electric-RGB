void labb4_read_input(){
  charIndex=0;
  //Serial.println("00000");
  while (Serial.available()) {
   // Serial.println("9999");
    if(charIndex < 29)
    {
      delay(2);  //delay to allow byte to arrive in input buffer
      inChar = Serial.read();
      inData[charIndex] = inChar;
      charIndex++;
      inData[charIndex] = '\0';
    }    
  }
  if(inData[0] != '\0') has_input = true;
  else has_input = false;
}
