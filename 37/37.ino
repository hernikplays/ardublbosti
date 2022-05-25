byte led = 10; //pin s LED diodou
byte led2 = 11;
byte pot = A4; //pin s fotorezistorem
int val; //prom�nn� p�ipraven� k uchov�n� hodnot
int druhy;
void setup() {
	Serial.begin(9600);
}
void loop() {
	val = analogRead(pot)/4; //�ten� hodnoty na A4 a �prava rozsahu
	if(val < 128){
		druhy = val + 128;
	}
	else{
		druhy = val - 128;
	}
	analogWrite(led, val); //generov�n� PWM
	analogWrite(led,druhy);
	Serial.println("Hodnota na prvn� led:");
	Serial.println(val);
	Serial.println("Hodnota na druh� led:");
	Serial.println(druhy);
}
