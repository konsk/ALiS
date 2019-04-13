/* Συνάρτηση απενεργοποίησης φώτων  */


// turn_off_lights (smoothly)

void turn_off_lights(int brightness_11, int brightness_10, int brightness_09, int brightness_06)
{
  // Εδώ δεν έχουμε μετρήσεις φωτεινότητας, αλλά επιβάλλονται υψηλές τιμές φωτεινότητας ώστε να ανακαστεί η A.Li.S. Να σβήσει τα φώτα
  
  int  level_11 = 0, level_10 = 0, level_09 = 0, level_06 = 0;   // Επίπεδο φωτεινότητας για τις ldr 11,10,09,06 επιβάλλεται σε 0
  bool condition_1 = false, condition_2 = false;

  do
  {
    // Σύκρινε φωτεινοτητα ldr: αν εινα μεγαλύτερη από 25 ανέβασε κατά 2,  αν είνα μικρότερη από 23 κατέβασε κατά 2
    brightness_11 = compare_adjust(ledStrip11, level_11, brightness_11);
      if(brightness_11 == 0 || brightness_11 == 255) level_11 = (lowlevel_1 + lowlevel_2)/2;
    brightness_10 = compare_adjust(ledStrip10, level_10, brightness_10);
      if(brightness_10 == 0 || brightness_10 == 255) level_10 = (lowlevel_1 + lowlevel_2)/2;
    brightness_09 = compare_adjust(ledStrip09, level_09, brightness_09);
      if(brightness_09 == 0 || brightness_09 == 255) level_09 = (lowlevel_1 + lowlevel_2)/2;
    brightness_06 = compare_adjust(ledStrip06, level_06, brightness_06);
      if(brightness_06 == 0 || brightness_06 == 255) level_06 = (lowlevel_1 + lowlevel_2)/2;
    delay(25);
    
    // Η φωτεινότητα πρέπει να είναι κάτω του 130 και άνω του 132
    condition_1 = level_11 < lowlevel_1 || level_10 < lowlevel_1 || level_09 < lowlevel_1 || level_06 < lowlevel_1; 
    condition_2 = level_11 > lowlevel_2 || level_10 > lowlevel_2 || level_09 > lowlevel_2 || level_06 > lowlevel_2;
   
  }while(condition_1 || condition_2);  // όσο  130 < level < 132
  
  brightness11 = brightness_11;
  brightness10 = brightness_10;
  brightness09 = brightness_09;
  brightness06 = brightness_06;

  view(level_11,level_10,level_09,level_06,brightness_11,brightness_10,brightness_09,brightness_06);
  delay(1000);
  
}

  

