int count;
void setup()
{
	pinMode(9, OUTPUT);
}
void loop()
{
	count=10;
	while (count<100) {
		analogWrite(9, count++);
	}
}