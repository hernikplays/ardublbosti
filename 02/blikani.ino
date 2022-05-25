// 05.01.2022 Caras Matyáš IT2A
// Úkol è.1 – Blikání led D13
void setup()
{
	pinMode(13,OUTPUT); //pin 13 ve stavu digitálního výstupu
}
void loop()
{
	digitalWrite(13, HIGH);// zapiš logickou úroveò 1 (HIGH) na pin 13
	delay(1000); // èekej 1000ms
	digitalWrite(13, LOW); // zapiš logickou úroveò 0 (LOW) na pin 13
	delay(1000); // èekej 1000ms
}
