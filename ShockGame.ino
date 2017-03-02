int buttonleft = 2;
int buttonright = 3;

int LedEsquerda = 9;
int LedDireita = 11;
int LedPrincipal = 10;

int WaitLed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LedEsquerda, OUTPUT);
  pinMode(LedDireita, OUTPUT);
  pinMode(LedPrincipal, OUTPUT);
  pinMode(buttonleft, INPUT);
  pinMode(buttonright, INPUT);
  randomSeed(analogRead (0));    // randomize

  for(int i = 0; i < 3; i++)
  {
    digitalWrite(LedEsquerda, HIGH);
    digitalWrite(LedDireita, HIGH);
    delay(500);
    digitalWrite(LedEsquerda, LOW);
    digitalWrite(LedDireita, LOW);
    delay(500);
  }

  RandomBlink();
}

void loop() {
  // put your main code here, to run repeatedly:
   int stateleft = digitalRead(buttonleft);
   int stateright = digitalRead(buttonright);
   
   if( stateleft == HIGH && digitalRead(LedPrincipal) == HIGH)
   {
      digitalWrite(LedPrincipal, LOW);
      digitalWrite(LedEsquerda, HIGH);
      delay(3000);
      digitalWrite(LedEsquerda, LOW);
      
      RandomBlink();
   }
   else if( stateright == HIGH && digitalRead(LedPrincipal) == HIGH)
   {
      digitalWrite(LedPrincipal, LOW);
      digitalWrite(LedDireita, HIGH);
      delay(3000);
      digitalWrite(LedDireita, LOW);

      RandomBlink();
   }
   
}

void RandomBlink()
{
   WaitLed = random(3000, 10000);
   delay(WaitLed);
   digitalWrite(LedPrincipal, HIGH);
}

