// 05.01.2022 Caras Matyáš IT2A
// Úkol è.5 – Blikání led D13

void setup()
{
	pinMode(13,OUTPUT);
	pinMode(12,OUTPUT);
	pinMode(11,OUTPUT);
	pinMode(10,OUTPUT);	
}
void loop()
{
	digitalWrite(13, HIGH); 
	digitalWrite(12, LOW);
	digitalWrite(11, HIGH);
	digitalWrite(10, LOW);
	delay(1000); 
	digitalWrite(12, HIGH); 
	digitalWrite(13, LOW);
	digitalWrite(10, HIGH);
	digitalWrite(11, LOW);	
	delay(1000);
}