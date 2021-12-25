#define SensorPin 2
#define RedLedPin 9
#define GreenLedPin 12
#define SignalPin 6
#define timeDelay 50
int buttomValue, buttomState;

void setup()
{
  /*
  Активируем и настроим монитор порта 
  для контроля получаемого значения
  */
  Serial.begin(9600);
  Serial.println("START");
  
  //Настройка работы пинов платы
  pinMode(SensorPin, INPUT);		//Получаемый сигнал с датчика
  pinMode(SignalPin, OUTPUT);		//Отправляемый сигнал роботу
  pinMode(RedLedPin, OUTPUT);		//Пим для индикации
  pinMode(GreenLedPin, OUTPUT);		//Пим для индикации
  
  
}

void loop()
{
  buttomState = digitalRead(SensorPin);
  if (buttomState != buttomValue)
  {
    Serial.println("Matherial: Metal");
    digitalWrite(RedLedPin, LOW);
    digitalWrite(GreenLedPin, HIGH);
    digitalWrite(SignalPin, HIGH);
    delay(timeDelay);						//Необходимая задержка для микроконтроллера
  }
  else
  {
    Serial.println("Matherial: NO Metal");
    digitalWrite(RedLedPin, HIGH);
    digitalWrite(GreenLedPin, LOW);
    digitalWrite(SignalPin, LOW);
    delay(timeDelay);
  }
}