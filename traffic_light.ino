void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5, HIGH); //red on
  delay(100);

  digitalWrite(5, LOW); //red off
  delay(900);

  digitalWrite(1, HIGH); //yellow on
  delay(100);
  
  digitalWrite(1, LOW); //yellow off
  delay(900);

  digitalWrite(5, HIGH); //red on
  delay(100);

  digitalWrite(5, LOW); //red off
  delay(900);

  digitalWrite(1, HIGH); //yellow on
  delay(100);
  
  digitalWrite(1, LOW); //yellow off
  delay(900);

  digitalWrite(5, HIGH); //red on
  digitalWrite(0, HIGH); //green on
  delay(100);

  digitalWrite(5, LOW); //red off
  digitalWrite(0, LOW); //green off
  delay(900);
}
