/* Συνάρτηση button Interrupt (ISR) */

void button_pressed()
{
  if(brightness11 > 0 || brightness10 > 0 || brightness09 > 0 || brightness06 > 0) 
  {
    analogWrite(ledStrip11, 0);
    analogWrite(ledStrip10, 0);
    analogWrite(ledStrip09, 0);
    analogWrite(ledStrip06, 0);
  }
  else
  {
    analogWrite(ledStrip11, 255);
    analogWrite(ledStrip10, 255);
    analogWrite(ledStrip09, 255);
    analogWrite(ledStrip06, 255);
  }
}

