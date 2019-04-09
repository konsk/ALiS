/* Συνάρτηηση μετρήσεων με μέσο όρο τιμών  */ 

int measure_ldr(int ldrPin)     // ldrPin, ο ακροδέκτης σύνδεσης του μικροελεγκτή με την φωτοαντίσταση
{
  const int num_measure = 10;   // Αριθμός τιμών για υπολογισμό μέσου όρου      
  int lev = 0;                  // Τρέχουσα μέτρηση
  int avg = 0;                  // Μέσος όρος (ακέρια μορφή)
  float average = 0.0;          // Μέσος όρος (δεκαδική μορφή)
         
  for(int i=1; i<=num_measure; i++)   
  {
    lev = analogRead(ldrPin);                                     // Ανάγνωση τιμής αισθητήρα  
    average = float(lev)/float(i) + average*float(i-1)/float(i);  // Υπολογισμός μέσου όρου από προηγούμενη τιμή του και από τρέχουσα μέτρηση
  }
  avg = int(average);            // Μετατροπή μέσου όρου σε ακέραιο(γιατί στην analogwrite(ledStrip, brightness) η brightness είναι ακέραια 
  avg = map(avg, 0, 1023, 0, 255);    // Προσαρμογή εύρους τιμών από 0-1023 σε 0-255                          
  return avg;                                  
}
