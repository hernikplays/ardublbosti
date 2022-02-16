#include <EEPROM.h>

#define ledON 13
#define tlacON A1
#define ledZaclon 12
#define ledTri 11
#define tlacPlus A2
#define tlacMinus A3

// 7segm
#define pinLatch 4
#define pinClk 7
#define pinData 8

#define sviti LOW 
#define nesviti HIGH

#define limit 1200 // limit abychom si nenastavovali vysoke teploty :^)
int i;

int foto; // hodnota fotorezistoru
bool isOn = false; // bezime?

int rozhodovaci = 500; // rozhodovaci hodnota kdy neco eco
byte b1;
byte b2;

// tlacitka s pameti
int stav1 = 0;
int pred1;
int stL1;
int stav2 = 0;
int pred2;
int stav3 = 0;
int pred3;

const byte mapaSegment[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90}; // čísla ale hex, pro zobrazení na 7segm
int rozhodovaciDisplay[4]; // cislo si rozdelime na jednotlive cifry
const int cisilka [4] = {0xF1,0xF2,0xF4,0xF8}; // cisla mist na 7segm

unsigned long previous = 0; // poslední čas stisknutí
const long interval = 2000; // jak dlouho držíme aby přetáčel rychle

void setup()
{
	pinMode(ledON,OUTPUT);
	pinMode(ledZaclon,OUTPUT);
	pinMode(ledTri,OUTPUT);
	pinMode(tlacON,INPUT_PULLUP); 
	pinMode(tlacPlus,INPUT_PULLUP); 
	pinMode(tlacMinus,INPUT_PULLUP); 
	pinMode(pinLatch, OUTPUT);
	pinMode(pinClk, OUTPUT);
	pinMode(pinData, OUTPUT);

	digitalWrite(ledON,nesviti);
	digitalWrite(ledZaclon,nesviti);
	digitalWrite(ledTri,nesviti);

	Serial.begin(9600);
	nactiZprom();
	previous = millis();
}

void nactiZprom(){
	b1=EEPROM.read(100);
	b2=EEPROM.read(101);
	rozhodovaci = (b1*256)+b2;
	if(rozhodovaci > limit){	// aby nebyla hranice moc nahore nahodou
		rozhodovaci = limit;
	}
}

void ukazCisilka(){
	// cisilka do array
	rozhodovaciDisplay[0] = rozhodovaci/1000;
	rozhodovaciDisplay[1] = (rozhodovaci/100)%10;
	rozhodovaciDisplay[2] = (rozhodovaci/10)%10;
	rozhodovaciDisplay[3] = rozhodovaci%10;
	for (i = 0; i <4; i++) {
		int n = rozhodovaciDisplay[i];
		digitalWrite(pinLatch,LOW);
		shiftOut(pinData, pinClk, MSBFIRST, mapaSegment[n]);
		shiftOut(pinData, pinClk, MSBFIRST, cisilka[i] );
		digitalWrite(pinLatch,HIGH);
	}
}

void ulozDoProm(){
	b1=rozhodovaci/256;
	b2=rozhodovaci%256;
	EEPROM.write(100, b1);
	EEPROM.write(101, b2);
}

void loop()
{
	
	// tlacitko s pameti - on/off
	pred1 = stav1;
	stav1 = !digitalRead(tlacON);
	stL1 = digitalRead(ledON);

	if(stav1 == 0 && pred1 == 1){
		if(isOn){
			// vypínáme
			tone(3,1109,300);
			delay(200);
			tone(3,988,300);
			digitalWrite(ledZaclon,nesviti);
			digitalWrite(ledTri,nesviti);
		}
		else{
			// zapínáme
			tone(3,988,300);
			delay(200);
			tone(3,1109,300);
		}
		digitalWrite(ledON, !stL1);
		isOn = !isOn;
	}
	// konec tlacitko on/off

	if(isOn){
    ukazCisilka();
		// pajka zapnuta
		foto = analogRead(A4);
    Serial.println("Fotorezistor: ");
		Serial.print(foto);
    Serial.print("---");
		if(foto > 600){	//hard hodnota, mozna zmenit
			digitalWrite(ledZaclon,nesviti); // pri zacloneni nesviti (je nahrata)
			if(digitalRead(ledTri) == 1){
				digitalWrite(ledTri,sviti); // rozsvitime treti az do vypnuti
			}
		}
		else{
			digitalWrite(ledZaclon,sviti); // jinak sviti (zahriva)
		}

		// PLUS/MINUS s pameti
		pred2 = stav2;
		stav2 = !digitalRead(tlacPlus);
		pred3 = stav3;
		stav3 = !digitalRead(tlacMinus);
		if(pred2 == 1 && stav2 == 0){
			if(rozhodovaci + 10 <= limit){
				rozhodovaci += 10;
				tone(3,880,150);
				ulozDoProm();}
			previous = millis();
		}
		else if(pred3 == 1 && stav3 == 0){
			// plus ma prednost pred minus
			if(rozhodovaci - 10 >= 10){
				rozhodovaci -= 10;
				tone(3,740,150);
				ulozDoProm();}
			previous = millis();
		}
		else if(pred2 == 1 && stav2 == 1){
			unsigned long currentMillis = millis();
			if(currentMillis - previous >= interval){	// cekame 2s ale bez blokovani programu
				if(rozhodovaci + 1 <= limit){
					rozhodovaci += 1;
					tone(3,1976,50);
          }
			}
		}
		else if(pred3 == 1 && stav3 == 1){
			unsigned long currentMillis = millis();
			if(currentMillis - previous >= interval){
				if(rozhodovaci - 1 >= 0){
					rozhodovaci -= 1;
					tone(3,1976,50);
          }
			}
		}
		// konec PLUS/MINUS s pameti
	}
}
