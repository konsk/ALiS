/* 06-04-2019  Κώδικας A.Li.S.  */   
// Digital_Pins: 4,1,0   (PWM) 5,3    Analog_Pins: A4,A5 

const int trigerPin = 8;        // ακροδέκτης 8 για ενεργοποίηση του ηχητικού παλμού στον αισθητήρα υπερήχων
const int echoPin = 7;          // ακροδέκτης 7 για ανίχνευση του επιστρεφόμενου ηχητικού παλμού 
const int in_motionPin = 2;     // ακροδέκτης 2 για ανάγνωση κατάστασης του αισθητήρα κίνησης
const int ldrPin11 = A0;        // ακροδέκτης A0 για ανάγνωση αναλογικής τάσης από τον αισθητήρα φωτός (ldr) 11
const int ldrPin10 = A1;        // ακροδέκτης A1 για ανάγνωση αναλογικής τάσης από τον αισθητήρα φωτός (ldr) 10
const int ldrPin09 = A2;        // ακροδέκτης A2 για ανάγνωση αναλογικής τάσης από τον αισθητήρα φωτός (ldr) 09
const int ldrPin06 = A3;        // ακροδέκτης A3 για ανάγνωση αναλογικής τάσης από τον αισθητήρα φωτός (ldr) 06

const int ledStrip11 = 11;      // ακροδέκτες για ρύθμιση αναλογικής τάσης στα Led Strip 11,10,09,06        
const int ledStrip10 = 10;      // 
const int ledStrip09 = 9;       //  
const int ledStrip06 = 6;       //  

const int led = 12;              // led που αναβοσβήνει κατά την διάρκεια επεναλληπτικών ελέγχων
const int button = 3;            // button για interrupt όταν πρέπει να σβήσουν τα φώτα χειροκίνητα (πχ για χρήση βιντεοπροβολέα)

const int lowlevel_1 = 130;       // Κάτω όριο φωτεινότητας 130 (υψηλή φωτεινότητα)
const int lowlevel_2 = 132;       // Κάτω όριο φωτεινότητας 132 (υψηλή φωτεινότητα)
const int brightness_change = 1;  // Τιμή ρύθμισης φωτεινότητας (αύξησης-μείωσης)

volatile bool button_state = false;    // Κατάσταση button. Αρχικά false:

int  brightness11 = 0;          // Αρχικές τιμές φωτεινότητας (20) για τις led Strip 11,10,09,06
int  brightness10 = 0;
int  brightness09 = 0;
int  brightness06 = 0;

int counter = 0;                  // Μετράει επαναλήψεις των ελέγχων στους αισθητήρες και στη ρύθμιση φωτεινόητας (for loop)
const int limit_counter = 10;
int dm_counter = 0;               // Μετράει ανιχνευσεις απόστασης και κίνησης
const int limit_dm_counter = 5;   // Ελάχιστο όριο γεγονότων

bool human = false;

void setup();                   // Συνάρτηση βασικών αρχικοποιήσεων

void loop()                     // Κυρίως πρόγραμμα
{ 
  // ΠΙΘΑΝΗ ΠΡΟΣΘΗΚΗ : ΧΕΙΡΟΚΊΝΗΤΗ ΕΝΕΡΓΟΠΟΙΗΣΗ / ΑΠΕΝΕΡΓΟΠΟΙΗΣΗ ΦΩΤΩΝ ΠΧ ΠΡΟΒΟΛΗ ΣΕ ΣΚΟΤΑΔΙ  
  
  counter = 0;                 //μηδενισμός μετρητή 
  dm_counter = 0;              //μηδενισμός μετρητή γεγονότων
  do
  {
    digitalWrite(led, LOW);
    Serial.println(" ΠΡΩΤΟΣ ΕΛΕΓΧΟΣ ΑΙΣΘΗΤΗΡΩΝ -- ΦΩΤΑ:ΣΒΗΣΤΑ ");
    motion_check();               // Πρώτος έλεγχος για κίνηση
    distance_check();             // Πρώτος έλεγχος για απόσταση
    Serial.print("  dm_counter = "); Serial.println(dm_counter);  Serial.println(" ---------------------------------------- ");
    digitalWrite(led, HIGH);
    delay(1000);
  }while(dm_counter < 3); 
    
  Serial.println(" ΤΕΛΟΣ ΠΡΩΤΟΥ ΕΛΕΓΧΟΥ ");   Serial.println();
  delay(2000);
    
  Serial.println(" TA ΦΩΤΑ ΘΑ ΑΝΑΨΟΥΝ ΣΕ ΛΙΓΑ ΔΕΥΤΕΡΟΛΕΠΤΑ ");   
  Serial.println(" --------------------------------------- ");
  delay(2000);
    
  do
  {
    dm_counter = 0;                                          // μηδενισμός μετρητή γεγονότων
    for(counter = 0; counter < limit_counter; counter++)     // μηδενισμός μετρητή επαναλήψεων
    {
      digitalWrite(led, HIGH);
      adjust_led_strip(brightness11, brightness10, brightness09, brightness06);    // κλήση συνάρτησης για προσαρμογή φωτεινότητας
      view(999,999,999,999,brightness11,brightness10,brightness09,brightness06);
      digitalWrite(led, LOW);
      motion_check();        
      distance_check();
      Serial.print("counter = "); Serial.print(counter); Serial.print("  dm_counter = "); Serial.println(dm_counter);  
      // interupt function
    }
  }while(dm_counter >= limit_dm_counter);
  digitalWrite(led, HIGH);
  Serial.print(" ΤΕΛΟΣ "); Serial.print(limit_counter);  Serial.println(" ΚΥΚΛΩΝ ΕΛΕΓΧΟΥ ");  Serial.println();
  delay(2000);
    
  Serial.println(" TA ΦΩΤΑ ΘΑ ΣΒΗΣΟΥΝ ΣΕ ΛΙΓΑ ΔΕΥΤΕΡΟΛΕΠΤΑ ");   
  Serial.println(" --------------------------------------- ");
  delay(5000);
    
  turn_off_lights(brightness11, brightness10, brightness09, brightness06);      //  Σβήσε τα φώτα ομαλά εφόσον δεν υπάρχει άνθρωπος                         
}
