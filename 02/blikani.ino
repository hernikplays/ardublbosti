// 05.01.2022 Caras Maty� IT2A
// �kol �.1 � Blik�n� led D13
void setup()
{
	pinMode(13,OUTPUT); //pin 13 ve stavu digit�ln�ho v�stupu
}
void loop()
{
	digitalWrite(13, HIGH);// zapi� logickou �rove� 1 (HIGH) na pin 13
	delay(1000); // �ekej 1000ms
	digitalWrite(13, LOW); // zapi� logickou �rove� 0 (LOW) na pin 13
	delay(1000); // �ekej 1000ms
}
