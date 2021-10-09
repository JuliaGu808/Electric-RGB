void labb4_read_input() {
  charIndex = 0;
  readTime = millis();
  while (Serial.available()) {
    if (charIndex < 29)
    {
      while ((millis() - readTime) < 2) {
        inChar = Serial.read();
        inData[charIndex] = inChar;
        charIndex++;
        inData[charIndex] = '\0';
        has_input = true;
      }
      readTime = millis();
    }
  }
}
