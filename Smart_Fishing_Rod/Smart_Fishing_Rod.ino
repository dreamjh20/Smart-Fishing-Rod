#define VIBE A0
#define COUNT 11
#define LED 12
#define BUZZER 10
#define LED2 8

char noteNames[] = {'C','D','E','F','G','a','b','c'};
int frequency[] = {1047,1175,1319,1397,1568,1760,1976,2093}; 
byte noteCount = sizeof(noteNames);
char score[] = "CCGGaaGFFEEDDC  GGFFEEDGGFFEED  CCGGaaGFFEEDDC";
byte scoreLen = sizeof(score);
 
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

void playNote(char note, int duration){
  for (int i=0 ; i<noteCount ; i++)
  {
    if (noteNames[i] == note)
    {
      tone(BUZZER, frequency[i], duration);
    }
  }
  delay(duration);
}

void loop() {
  // put your main code here, to run repeatedly:
  int up = digitalRead(COUNT);
  Serial.print("--");
  Serial.println(up);
  if(up == LOW){
    digitalWrite(LED2, HIGH);
    for (int i=0 ; i<scoreLen ; i++)
    {
         int duration = 333;
         playNote(score[i], duration);
     }
     delay(300);
     digitalWrite(LED2, LOW);
     delay(100);
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
