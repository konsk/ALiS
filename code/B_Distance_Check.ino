/* Συνάρτηση αισθητήρα απόστασης */

void distance_check()
{
  long s;                  // Απόσταση αισθητήρα
  long tof = 0;            //  Ο χρόνος που ταξιδεύει ο ηχητικός παλμός (tof = time of flight
  const int limit = 28;   // Άνω όριο απόστασης σε cm
  
  // Ενεργοποίση αισθητήρα υπερήχων 
  digitalWrite(trigerPin, LOW);     // Παλμός LOW για 2us
  delayMicroseconds(2);
  digitalWrite(trigerPin, HIGH);   // Παλμός HIGH για 10us
  delayMicroseconds(10);
  digitalWrite(trigerPin, LOW);    // Παλμός LOW για 2us
  delayMicroseconds(10);

  tof = pulseIn(echoPin, HIGH);   // Χρόνος του ηχητικού παλμού από τον αισθητήρα έως το πιο κοντινό αντικείμενο και επιστροφή
  s = (17 * tof) / 1000;         // Απόσταση σε εκατοστά

  if(0 <= s && s <= limit) dm_counter++;   // αν το εμπόδιο είναι εντός ορίων τότε αύξησε μετρητή παρουσίας καθηγητή

  Serial.print("  s = ");Serial.println(s);
}
