// 05.01.2022 Caras Matyáš IT2A
// Úkol è.5 – Blikání led D13

#define led1 13
#define led2 12

void setup()
{
	pinMode(led1,OUTPUT);
	pinMode(led2,OUTPUT);	
}
void loop()
{
	digitalWrite(led1, HIGH);// zapiš logickou úroveò 1 (HIGH) na pin 13
	digitalWrite(led2, LOW);
	delay(1000); 
	digitalWrite(led1, LOW); // zapiš logickou úroveò 0 (LOW) na pin 13
	digitalWrite(led2, HIGH);	
	delay(1000);
}