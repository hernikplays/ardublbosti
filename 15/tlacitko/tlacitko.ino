/* Tlacitko a led*/
#define led1 10
#define led2 12
#define led3 13 
#define led4 11
#define sviti HIGH 
#define nesviti LOW 
#define tlac1 A1
#define tlac2 A2
#define tlac3 A3

int h1;
int h2;
int h3;
int j;
void setup() 
{
	pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
	pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
	pinMode(tlac1,INPUT_PULLUP); 
	pinMode(tlac2,INPUT_PULLUP); 
	pinMode(tlac3,INPUT_PULLUP); 
}
void loop()
{
	h1 = !digitalRead(tlac1);
	h2 = !digitalRead(tlac2);
	h3 = !digitalRead(tlac3);
	
  // prvni tlacitko
	j = !digitalRead(tlac1);
	if (j == 0) {	
		digitalWrite(led4, sviti);
	} else {
		digitalWrite(led4, nesviti);
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

	if(h1 == 1 && h2 == 1 && h3 == 1){
		digitalWrite(led1, nesviti);
	}
	else{
	digitalWrite(led1, sviti);
	}
}
