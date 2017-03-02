/* Correspondence of the ports of arduino */
int buttonA = 7;
int buttonB = 6;
int relayA = 9;
int relayB = 8;
int Led = 5;

/* waitLed is a randomly generated number of seconds between Led blinking */  
int waitLed = 0;

/* state of the pushed buttons */
int stateA = -1;
int stateB = -1;

int relayTime = 200;
int ledelay = 3000;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;

/* 1 is the A side, 0 is the B side */

void setup() {
  // put your setup code here, to run once:
  pinMode(Led, OUTPUT);
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
  pinMode(relayA, OUTPUT);
  pinMode(relayB, OUTPUT);
  randomSeed(analogRead (0));    // randomize

  /* setting up the relays as off */
  digitalWrite(relayA, LOW);
  digitalWrite(relayB, LOW);

  for(int i = 0; i < 3; i++)
  {
    digitalWrite(Led, HIGH);
    delay(500);
    digitalWrite(Led, LOW);
  }

  RandomGenerator();
}

void loop() {
   // put your main code here, to run repeatedly:

   currentMillis = millis();
   
   stateA = digitalRead(buttonA);
   stateB = digitalRead(buttonB);

   if ( currentMillis - previousMillis >= waitLed ){

        digitalWrite(Led, HIGH);
        
        if ( stateA == HIGH ){
            /* shock the person in the B button */
            triggershock('B');

            RandomGenerator();
        }
        else if( stateB == HIGH ) {
            /* shock the person in the A button */
            triggershock('A');

            RandomGenerator();
        }
   }
   else if ( currentMillis - previousMillis < waitLed )
   {
        
       if( stateB == HIGH )
       {
          /**shock the person in the B button**/
          triggershock('B');   

          RandomGenerator();
       }
       else if( stateA == HIGH ) 
       {
          /*shock the person in the A button*/
          triggershock('A');

          RandomGenerator();
       }
   }
     
}

void RandomGenerator()
{
   digitalWrite(Led, LOW);
   delay(ledelay);
   previousMillis = currentMillis;
   /* the waiting time is between 3sec and 10sec */
   waitLed = random(3000, 10000);
}

void triggershock(char side)
{
  if(side == 'A')
  {
    /*shock A side*/
    digitalWrite(relayA, HIGH);
    delay(relayTime);
    digitalWrite(relayA, LOW);
  }
  else if(side == 'B')
  {
    /*shock B side*/
    digitalWrite(relayB, HIGH);
    delay(relayTime);
    digitalWrite(relayB, LOW);
  }
}

