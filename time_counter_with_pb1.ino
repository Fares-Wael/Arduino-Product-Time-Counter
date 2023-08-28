const int button=3;
bool Timer=false;
unsigned long T1=0;
unsigned long T2=0;
void setup()
{
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop()
{
  byte Button = digitalRead(button);
  if (Button == HIGH && !Timer) {
    T1= millis();
    Timer = true;
  } else if (Button == LOW && Timer) {
    T2 = millis();
    Timer = false;

    unsigned long Time = T2 - T1;
    float TimeInSecs = Time / 1000.0;
    
    Serial.print("Time= ");
    Serial.print(TimeInSecs);
    Serial.println(" S");
  }
}