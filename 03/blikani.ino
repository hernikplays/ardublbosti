// 05.01.2022 Caras Maty� IT2A
// �kol �.2 � Blik�n� led D13

#define led1 13 

void setup()
{
	pinMode(led1,OUTPUT);
}
void loop()
{
	digitalWrite(led1, HIGH);// zapi� logickou �rove� 1 (HIGH) na pin 13
	delay(1000); // �ekej 1000ms
	digitalWrite(led1, LOW); // zapi� logickou �rove� 0 (LOW) na pin 13
	delay(1000); // �ekej 1000ms
}
