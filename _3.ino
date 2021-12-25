#define RedLedPin 12
#define GreenLedPin 10
#define PatronSignal 3
#define SensorSignal 4

int timeDelay = 1000;

void setup()
{
  Serial.begin(9600);
  Serial.println("START WORK");
  pinMode(PatronSignal, OUTPUT);
  pinMode(SensorSignal, INPUT);
  pinMode(RedLedPin, OUTPUT);
  pinMode(GreenLedPin, OUTPUT);
}

void loop()
{
  if (digitalRead(SensorSignal) == 1)
  {
    Serial.println("CNC WORK");
    digitalWrite(PatronSignal, HIGH);
    digitalWrite(RedLedPin, HIGH);
    delay(timeDelay);
  }
  else
  {
    Serial.println("CNC STOP");
    delay(timeDelay/4);
  }
}