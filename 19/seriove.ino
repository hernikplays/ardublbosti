/* Tlacitko a led*/
#define led1 10
#define led2 12
#define led3 13 
#define sviti LOW 
#define nesviti HIGH 
#define tlac1 A1
#define tlac2 A2
#define tlac3 A3

int stav1 = 0;
int pred1;
int stL1;

int stav2 = 0;
int pred2;
int stL2;

int stav3 = 0;
int pred3;
int stL3;
void setup() 
{
	pinMode(led1,OUTPUT);
	pinMode(tlac1,INPUT_PULLUP); 
}
void loop()
{
	// prvni
	pred1 = stav1;
	stav1 = !digitalRead(tlac1);
	stL1 = digitalRead(led1);

	if(stav1 == 0 && pred1 == 1){
		if(stL1 == 1){
			stL1 = 0;
		}
		else{
			stL1 = 1;
		}
		digitalWrite(led1, stL1);
	}

	// druhe
	pred2 = stav2;
	stav2 = !digitalRead(tlac2);
	stL2 = digitalRead(led2);

	if(stav2 == 0 && pred2 == 1){
		if(stL2 == 1){
			stL2 = 0;
		}
		else{
			stL2 = 1;
		}
		digitalWrite(led2, stL2);
	}

	// treti
	pred3 = stav3;
	stav3 = !digitalRead(tlac3);
	stL3 = digitalRead(led3);

	if(stav3 == 0 && pred3 == 1){
		if(stL3 == 1){
			stL3 = 0;
		}
		else{
			stL3 = 1;
		}
		digitalWrite(led3, stL3);
	}
}
