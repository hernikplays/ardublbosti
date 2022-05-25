int t;
void setup(){
	Serial.begin(9600);
}
void loop(){
	t = analogRead(A4);
	Serial.println("Hodnota fotorezistoru:");
	Serial.println(t);
	Serial.println("");
}
