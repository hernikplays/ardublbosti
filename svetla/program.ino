#include <AsyncTimer.h> // VYŽADUJE KNIHOVNU https://github.com/Aasim-A/AsyncTimer
#define tlacitkoZap A1
#define tlacitkoPrep A2
#define tlacitkoBlink A3
#define ledDalk 13
#define ledPotkal 12
#define blinkr 11

bool dalkove = false;
bool blikat = false;
bool sviti = false;
// asynchronní interval
AsyncTimer t;
unsigned short id;
// tlačítka s pamětí
bool tlacitko1Zmack = false;
bool tlacitko2Zmack = false;
bool tlacitko3Zmack = false;

void setup()
{
	pinMode(ledDalk,OUTPUT);
	pinMode(ledPotkal,OUTPUT);
	pinMode(blinkr,OUTPUT);
	pinMode(tlacitkoZap,INPUT_PULLUP);
	pinMode(tlacitkoPrep,INPUT_PULLUP);
	pinMode(tlacitkoBlink,INPUT_PULLUP);
	digitalWrite(ledDalk,HIGH);
	digitalWrite(ledPotkal,HIGH);
	digitalWrite(blinkr,HIGH);
}

void loop()
{
	t.handle();
	if(!digitalRead(tlacitkoZap) == 1){
		tlacitko1Zmack = true;
	}
	else if(!digitalRead(tlacitkoZap) == 0 && tlacitko1Zmack){
		tlacitko1Zmack = false;
		// Vypnout / zapnout
		tone(3,261,50);
		sviti = !sviti;
		if(!sviti){
			digitalWrite(ledDalk,HIGH);
			digitalWrite(ledPotkal,HIGH);
		}
		else{
			if(dalkove){
				digitalWrite(ledDalk,LOW);
				digitalWrite(ledPotkal,LOW);
			}
			else{
				digitalWrite(ledDalk,HIGH);
				digitalWrite(ledPotkal,LOW);
			}
		}
	}

	if(!digitalRead(tlacitkoBlink) == 1){
		tlacitko2Zmack = true;
	}
	else if(!digitalRead(tlacitkoBlink) == 0 && tlacitko2Zmack){
		tlacitko2Zmack = false;
		// přepnout blikání
		if(blikat){
			t.cancel(id);
			blikat = false;
      digitalWrite(blinkr, HIGH);
		}
		else{
			// blikat
			blikat = true;
			id = t.setInterval([](){
				digitalWrite(blinkr, !digitalRead(blinkr));
			},1000);
		}
	}

	if(!digitalRead(tlacitkoPrep) == 1 && sviti){
		tlacitko3Zmack = true;
	}
	else if(!digitalRead(tlacitkoPrep) == 0 && tlacitko3Zmack){
		// přepnout dálkové / potkávací
		tlacitko3Zmack = false;
		dalkove = !dalkove;
		if(dalkove){
			digitalWrite(ledPotkal,LOW);
			digitalWrite(ledDalk,LOW);
		}
		else{
			digitalWrite(ledDalk,HIGH);
			digitalWrite(ledPotkal,LOW);
		}
	}

	if(analogRead(A4) > 600){
		// FOTOREZISTOR
    if(!sviti){
      tone(3,261,50);
      sviti = true;
      if(dalkove){
        digitalWrite(ledDalk,LOW);
        digitalWrite(ledPotkal,LOW);
      }
      else{
        digitalWrite(ledPotkal,LOW);
      }
    }
	}
}
