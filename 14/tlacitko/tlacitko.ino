/* Tlacitko a led*/
#define led1 11
#define led2 12
#define led3 13 
#define sviti LOW 
#define nesviti HIGH 
#define tlac1 A1
#define tlac2 A2
#define tlac3 A3

int j;
void setup() 
{
	pinMode(led1,OUTPUT);
	pinMode(led2,OUTPUT);
	pinMode(led3,OUTPUT);
	pinMode(tlac1,INPUT_PULLUP); 
	pinMode(tlac2,INPUT_PULLUP); 
	pinMode(tlac3,INPUT_PULLUP); 
}
void loop()
{
	// prvni tlacitko
	j = !digitalRead(tlac1);
	if (j == 0) {	
		digitalWrite(led1, sviti);
	} else {
		digitalWrite(led1, nesviti);
	}
	
	// druhe tlacitko
	j = !digitalRead(tlac2);
	if (j == 0) {	
		digitalWrite(led2, sviti);
	} else {
		digitalWrite(led2, nesviti);
	}
	
	// treti tlacitko
	j = !digitalRead(tlac3);
	if (j == 0) {	
		digitalWrite(led3, sviti);
	} else {
		digitalWrite(led3, nesviti);
	}
}
