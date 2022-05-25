// 05.01.2022 Caras Matyáš IT2A
// Úkol è.2 – Blikání led D13

#define led1 13 

void setup()
{
	pinMode(led1,OUTPUT);
}
void loop()
{
	digitalWrite(led1, HIGH);// zapiš logickou úroveò 1 (HIGH) na pin 13
	delay(1000); // èekej 1000ms
	digitalWrite(led1, LOW); // zapiš logickou úroveò 0 (LOW) na pin 13
	delay(1000); // èekej 1000ms
}
