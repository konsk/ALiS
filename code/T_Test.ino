/* Συνάρτηηση δοκιμών για επίπεδο φωτεινότητας */

void test()
{
  // σε ικανοποιητικές συνθήκες έλλειψης φωτισμού (σκοτάδι) μετρήθηκς μέγιστο τιμή (level) = 100
  // level_11 = 89,   level_10 = 100, level_09 = 96, level_06 = 90
  // Η τιμή καλής φωτεινότητας μπορεί να τεθεί σε 100, άρα τα όρια lowlevel_1 = 100  και lowlevel_2 = 102
  analogWrite(ledStrip11, 255);  
  analogWrite(ledStrip10, 255);
  analogWrite(ledStrip09, 255);
  analogWrite(ledStrip06, 255);
  Serial.print("level_11 = ");    Serial.print(measure_ldr(ldrPin11));
  Serial.print("   level_10 = "); Serial.print(measure_ldr(ldrPin10));
  Serial.print("   level_09 = "); Serial.print(measure_ldr(ldrPin09));
  Serial.print("   level_06 = "); Serial.println(measure_ldr(ldrPin06));
  delay(1000);
}

