/* Συνάρτηση σύγκριση φωεινότητας και προσαρμογή προς τα πάνω ή κάτω  */

int compare_adjust(int ledStrip, int level, int brightness)
{
 
    if(level > lowlevel_2 && brightness <= 255 )
    {
      // αύξησε φωτεινότητα (δηλ μείωσε την level, αλλά μέχρι η brightness να γίνει το πολύ 255
      brightness = brightness + brightness_change;    // αύξησε την φωτεινότητα (μέσω της brightness) 
      if(brightness > 255) brightness = 255;          // αν γίνει η brightness > 255 επανέφερε την μέγιστη επιτρεπόμενη τιμή της δηλ την 255
      analogWrite(ledStrip, brightness);              // αύξηση τάσης-φωτεινότητας
    }
    else if(level < lowlevel_1 && 0 <= brightness)
    {
      // ελάττωσε φωτεινότητα (δηλ αύξησε την level)
      brightness = brightness - brightness_change;         // μείωσε την φωτεινότητα
      if(brightness < 0) brightness = 0;
      analogWrite(ledStrip, brightness);                   // μείωση τάσης-φωτεινότητας
    }
  return brightness;
}
