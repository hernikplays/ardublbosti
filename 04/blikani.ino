// 05.01.2022 Caras Maty� IT2A
// �kol �.2 � Blik�n� led D13

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
	digitalWrite(vybrana, HIGH);// zapi� logickou �rove� 1 (HIGH) na pin 13
	delay(1000); // �ekej 1000ms
	digitalWrite(vybrana, LOW); // zapi� logickou �rove� 0 (LOW) na pin 13
	delay(1000); // �ekej 1000ms
	
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
