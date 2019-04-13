/* Συνάρτηση αισθητήρα κίνησης */

void motion_check()
{                         
  Serial.println("  MOTION  ");                           //  Διάβασε την τιμή το αισθητήρα κίνησης 1
  if (digitalRead(in_motionPin) == HIGH) dm_counter++;    // αν έχουμε κίνηση τότε αύξησε τον μετρητή γεγονότων   
}
