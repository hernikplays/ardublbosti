// 05.01.2022 Caras Maty� IT2A
// �kol �.5 � Blik�n� led D13

#define led1 13
#define led2 12

void setup()
{
	pinMode(led1,OUTPUT);
	pinMode(led2,OUTPUT);	
}
void loop()
{
	digitalWrite(led1, HIGH);// zapi� logickou �rove� 1 (HIGH) na pin 13
	digitalWrite(led2, LOW);
	delay(1000); 
	digitalWrite(led1, LOW); // zapi� logickou �rove� 0 (LOW) na pin 13
	digitalWrite(led2, HIGH);	
	delay(1000);
}