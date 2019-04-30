/* Συνάρτηση αρχικοποιήσεων */

void setup() 
{
  Serial.begin(9600);
  pinMode(trigerPin, OUTPUT);   
  pinMode(echoPin, INPUT);
  pinMode(in_motionPin, INPUT);   
  pinMode(ledStrip11, OUTPUT); 
  pinMode(ledStrip10, OUTPUT);    
  pinMode(ledStrip09, OUTPUT);    
  pinMode(ledStrip06, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(ldrPin11, INPUT); 
  pinMode(ldrPin10, INPUT); 
  pinMode(ldrPin09, INPUT); 
  pinMode(ldrPin06, INPUT);  
  
  pinMode(button, INPUT_PULLUP);  // Eσωτερική pullup αντίστσση για το button
  
  digitalWrite(ledStrip11, LOW);  // Aρχικά τα φώτα σβησμένα
  digitalWrite(ledStrip10, LOW);
  digitalWrite(ledStrip09, LOW);
  digitalWrite(ledStrip06, LOW);

  digitalWrite(led, LOW);         // Aρχικά τα led σβηστό

  attachInterrupt(digitalPinToInterrupt(button), button_pressed, FALLING);  // Δεν έχει υλοποιηθεί ακόμη χειροκίνητη 
                                                                            // ενεργοποίηση / απενεργοποίηση φώτων
}
