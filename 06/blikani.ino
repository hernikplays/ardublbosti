// 05.01.2022 Caras Maty� IT2A
// �kol �.5 � Blik�n� led D13

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