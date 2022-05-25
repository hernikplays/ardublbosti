/* Tlacitko a led*/
#define led1 13
//#define led2 12
//#define led3 13 
#define sviti LOW 
#define nesviti HIGH 
#define tlac1 A1
//#define tlac2 A2
//#define tlac3 A3

int stav1 = 0;
int pred1;
int stL1;
void setup() 
{
	pinMode(led1,OUTPUT);
	pinMode(tlac1,INPUT_PULLUP); 
}
void loop()
{
	pred1 = stav1;
	stav1 = !digitalRead(tlac1);
	stL1 = digitalRead(led1);
	
	if(stav1 == 0 && pred1 == 1){
		digitalWrite(led1, !stL1);
	}
}
