void setup()
{
	pinMode(13,OUTPUT);
	pinMode(12,OUTPUT);
	pinMode(11,OUTPUT);
	pinMode(10,OUTPUT);	
	Serial.begin(9600);
}
void loop()
{
	digitalWrite(13, HIGH); 
	digitalWrite(12, LOW);
	digitalWrite(11, HIGH);
	digitalWrite(10, LOW);
	Serial.println("LED 13 a 11 sv�t�");
	Serial.println("LED 12 a 10 nesv�t�");
	delay(1000); 
	digitalWrite(12, HIGH); 
	digitalWrite(13, LOW);
	digitalWrite(10, HIGH);
	digitalWrite(11, LOW);	
	Serial.println("LED 13 a 11 nesv�t�");
	Serial.println("LED 12 a 10 sv�t�");
	delay(1000);
}