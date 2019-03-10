/* 28-02-2019  Κώδικας A.Li.S.  */   
// Digital_Pins: 4,1,0   (PWM) 5,3    Analog_Pins: A4,A5 

const int trigerPin = 8;        // ακροδέκτης 8 για ενεργοποίηση του ηχητικού παλμού στον αισθητήρα υπερήχων
const int echoPin = 7;          // ακροδέκτης 7 για ανίχνευση του επιστρεφόμενου ηχητικού παλμού 
const int in_motionPin = 2;     // ακροδέκτης 2 για ανάγνωση κατάστασης του αισθητήρα κίνησης 1
const int ldrPin11 = A0;        // ακροδέκτης A0 για ανάγνωση αναλογικής τάσης από τον αισθητήρα φωτός 11
const int ldrPin10 = A1;        // ακροδέκτης A1 για ανάγνωση αναλογικής τάσης από τον αισθητήρα φωτός 10
const int ldrPin09 = A2;        // ακροδέκτης A2 για ανάγνωση αναλογικής τάσης από τον αισθητήρα φωτός 09
const int ldrPin06 = A3;        // ακροδέκτης A3 για ανάγνωση αναλογικής τάσης από τον αισθητήρα φωτός 06

const int led_motion = 13;      // Red Led για ανίχνευση κίνησης στο pin 13
const int led_distance = 12;    // Green Led για ανίχνευση απόστασης στο pin 12
const int ledStrip11 = 11;      // PWM for Led Strip11        
const int ledStrip10 = 10;      // PWM for Led Strip10 
const int ledStrip09 = 9;       // PWM for Led Strip09 
const int ledStrip06 = 6;       // PWM for Led Strip06 
                           
int level_11 = 60;
int level_10 = 60;
int level_09 = 60;
int level_06 = 60;
int fade = 2;                           

bool teacher = false;          //  αποθηκεύει αποτέλεσμα ελέγχου παρουσίας καθηγητή
bool students_move = false;    //  αποθηκεύει αποτέλεσμα ελέγχου κίνησης μαθητών
 
void setup();

void loop() 
{
  //teacher = distance_check();
  //students_move = motion_check();
  //decision_A(teacher, students_move); 

  adjust_led_strip();

  delay(100);
}
