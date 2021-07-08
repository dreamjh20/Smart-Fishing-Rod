#define VIBE A0
#define COUNT 11
#define LED 12
#define BUZZER 10
#define LED2 8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("--------------------------");
  pinMode(VIBE, INPUT);
  pinMode(COUNT, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int up = digitalRead(COUNT);
  int led2 = 0;
  Serial.print("--");
  Serial.println(up);
  if(up == LOW)
  {
    led2 = 1 - led2;
    
  }
  if(led2 == 1)
  {
    digitalWrite(LED2, HIGH);
  }
  int bite = analogRead(VIBE);
  Serial.println(bite);
  if(bite > 900)
  {
    for(int i = 0; i < 50; i++)
    {
      digitalWrite(LED, HIGH);
      delay(30);
      digitalWrite(LED, LOW);
      delay(30);
    }
    digitalWrite(LED, HIGH);
    for(int i = 0; i < 40; i++)
    {
      digitalWrite(BUZZER, HIGH);
      delay(50);
      digitalWrite(BUZZER, LOW);
      delay(50);
    }
  
  }
  digitalWrite(LED, LOW);
  noTone(BUZZER);
}
