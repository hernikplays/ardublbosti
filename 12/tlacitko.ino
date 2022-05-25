/* Tlacitko a led*/
#define led 13 
#define sviti LOW 
#define nesviti HIGH 
#define tlacitko A1
int pomocna;
void setup() 
{
	pinMode(led,OUTPUT);
	pinMode(tlacitko,INPUT_PULLUP); 
	//pin A1 ve stavu digitálního vstupu + pull-up rezistor v procesoru 
}
void loop()
{
	pomocna = digitalRead(tlacitko); //pøeèti stav log. úrovnì
	if (pomocna == 0) {	// porovnej s èíslem 1
		digitalWrite(led, nesviti);
	} else {
		digitalWrite(led, sviti);
	}
}
