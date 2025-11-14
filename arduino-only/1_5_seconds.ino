/*
 red and yellow blink alternatively every second. Green blinks every 5 seconds.
 
 Pattern:
 red > yellow > red > yellow > red & green
 yellow > red > yellow > red > yellow & green
*/

void setup() {

  pinMode(5, OUTPUT);
  pinMode(1, OUTPUT); //yellow
  pinMode(0, OUTPUT); //green
}

int i, n;

void loop() {
  
  for (i=0; i<2; i++) 
  {
    digitalWrite(5, HIGH); //red on
    delay(100);

    digitalWrite(5, LOW); //red off
    delay(900);
    
    digitalWrite(1, HIGH); //yellow on
    delay(100);
  
    digitalWrite(1, LOW); //yellow off
    delay(900);
  }

    digitalWrite(5, HIGH); //red on
    digitalWrite(0, HIGH); //green on
    delay(100);

    digitalWrite(5, LOW); //red off
    digitalWrite(0, LOW); //green off
    delay(900);

  for (i=0; i<2; i++) 
  {
    digitalWrite(1, HIGH); //yellow on
    delay(100);

    digitalWrite(1, LOW); //yellow off
    delay(900);
    
    digitalWrite(5, HIGH); //red on
    delay(100);
  
    digitalWrite(5, LOW); //red off
    delay(900);
  }

    digitalWrite(1, HIGH); //yellow on
    digitalWrite(0, HIGH); //green on
    delay(100);

    digitalWrite(1, LOW); //yellow off
    digitalWrite(0, LOW); //green off
    delay(900);

  
}
