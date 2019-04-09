/* Συνάρτηηση ανάγνωσης τιμών φωτεινότητας ldr και led Strip*/

void view(int lev_11, int lev_10, int lev_09, int lev_06, int bright_11, int bright_10, int bright_09, int bright_06) 
{ 
    Serial.print("level (11,10,09,06) = ( ");  
    Serial.print(lev_11); Serial.print(", "); 
    Serial.print(lev_10); Serial.print(", "); 
    Serial.print(lev_09); Serial.print(", "); 
    Serial.print(lev_06); Serial.print(" )      "); 
   
    Serial.print("  brightness (11,10,09,06) = ( ");
    Serial.print(bright_11); Serial.print(", "); 
    Serial.print(bright_10); Serial.print(", "); 
    Serial.print(bright_09); Serial.print(", "); 
    Serial.print(bright_06); Serial.println(" )");
    //delay(1);
}

