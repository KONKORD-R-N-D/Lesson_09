#define SensorPin 10

void setup()
{
  /*
  Активируем и настроим монитор порта 
  для контроля получаемого значения
  */
  Serial.begin(9600);
  Serial.println("START");
  pinMode(SensorPin, INPUT);
  pinMode(3, INPUT);
}

void loop()
{
  Serial.println(digitalRead(SensorPin));
  delay(50);
  
  if (digitalRead(SensorPin) == 1)
  {
    digitalWrite(3, HIGH);
  }
  else
  {
    digitalWrite(3, LOW);
  }
}