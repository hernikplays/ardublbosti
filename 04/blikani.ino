// 05.01.2022 Caras Matyáš IT2A
// Úkol è.2 – Blikání led D13

#define led1 13
#define led2 12
#define led3 11 
#define led4 10

int vybrana = led1;
void setup()
{
	pinMode(led1,OUTPUT);
	pinMode(led2,OUTPUT);
	pinMode(led3,OUTPUT);
	pinMode(led4,OUTPUT);
}
void loop()
{
	digitalWrite(vybrana, HIGH);// zapiš logickou úroveò 1 (HIGH) na pin 13
	delay(1000); // èekej 1000ms
	digitalWrite(vybrana, LOW); // zapiš logickou úroveò 0 (LOW) na pin 13
	delay(1000); // èekej 1000ms
	
	if(vybrana == led1){
	vybrana = led2;
	}
	else if(vybrana == led2){
	vybrana = led3;
	}
	else if(vybrana == led3){
	vybrana = led4;
	}
	else if(vybrana == led4){
	vybrana = led1;
	}
}
