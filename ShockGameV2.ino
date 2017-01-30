int buttonA = 2;
int buttonB = 3;

int Led = 10;

int WaitLed = 0;

int stateA = -1;
int stateB = -1;

/* 1 is the A side, 0 is the right side */

void setup() {
  // put your setup code here, to run once:
  pinMode(Led, OUTPUT);
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
  randomSeed(analogRead (0));    // randomize

  for(int i = 0; i < 3; i++)
  {
    digitalWrite(Led, LOW);
    delay(500);
    digitalWrite(Led, HIGH);
  }

  RandomBlink();
}

void loop() {
  // put your main code here, to run repeatedly:
   stateA = digitalRead(buttonA);
   stateB = digitalRead(buttonB);
   
   if( stateA == HIGH && digitalRead(Led) == HIGH)
   {
      /* shock the person in the B button */
      /* triggershock(1); */
      digitalWrite(Led, LOW);
      delay(3000);
      
      RandomBlink();
   }
   else if( stateB == HIGH && digitalRead(Led) == HIGH)
   {
      /* shock the person in the A button */
    
      digitalWrite(Led, LOW);
      delay(3000);

      RandomBlink();
   }
   /**else if( stateB == HIGH && digitalRead(LedPrincipal) == LOW)
   {
      shock the person in the B button
    
   }
   else if( stateA == HIGH && digitalRead(LedPrincipal) == LOW) 
   {
      shock the person in the A button
    
   }**/
}

void RandomBlink()
{
   WaitLed = random(3000, 10000);
   delay(WaitLed);
   digitalWrite(Led, HIGH);
}

void triggershock(int side)
{
  if(side == 1)
  {
    /*shock A side*/
  }
  else if(side == 0)
  {
    /*shock B side*/
  }
}

