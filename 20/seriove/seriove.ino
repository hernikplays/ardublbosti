int p;
int d;
int t;
int c;

void setup() {
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  digitalWrite(10, LOW);
}
void loop() {
  p = !digitalRead(13);
  d = !digitalRead(12);
  t = !digitalRead(11);
  c = !digitalRead(10);

  if (p == 1) {
    Serial.println("Dioda 1 svítí");
	}
	else{
		Serial.println("Dioda 1 nesvítí");
	}
	if(d == 1){
		Serial.println("Dioda 2 svítí");
	}
	else{
		Serial.println("Dioda 2 nesvítí");
	}
	if(t == 1){
		Serial.println("Dioda 3 svítí");
	}
	else{
		Serial.println("Dioda 3 nesvítí");
	}
	if(c == 1){
		Serial.println("Dioda 4 svítí");
	}
	else{
		Serial.println("Dioda 4 nesvítí");
	}
	delay(1000); //�ek� 1000ms
}
