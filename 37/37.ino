byte led = 10; //pin s LED diodou
byte led2 = 11;
byte pot = A4; //pin s fotorezistorem
int val; //promìnná pøipravená k uchování hodnot
int druhy;
void setup() {
	Serial.begin(9600);
}
void loop() {
	val = analogRead(pot)/4; //ètení hodnoty na A4 a úprava rozsahu
	if(val < 128){
		druhy = val + 128;
	}
	else{
		druhy = val - 128;
	}
	analogWrite(led, val); //generování PWM
	analogWrite(led,druhy);
	Serial.println("Hodnota na první led:");
	Serial.println(val);
	Serial.println("Hodnota na druhé led:");
	Serial.println(druhy);
}
