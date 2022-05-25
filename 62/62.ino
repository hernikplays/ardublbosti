int count;
void setup()
{
	pinMode(9, OUTPUT);
}
void loop()
{
	count=10;
	do {
		analogWrite(9, count++);
	} while (count<100);
}
