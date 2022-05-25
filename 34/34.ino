#define sviti HIGH 
#define nesviti LOW 

int t;
int e;
void setup(){
	Serial.begin(9600);
	pinMode(10,OUTPUT);
	pinMode(9,OUTPUT);
}
void loop(){
	t = analogRead(A4);
	e = analogRead(A0);
	Serial.println("Fotorezistor");
	Serial.println(t);
	Serial.println("Trimr");
	Serial.println(e);
	if(t < e){
		digitalWrite(9,sviti);
		digitalWrite(10,nesviti);
	}
	else if(t > e){
		digitalWrite(9,nesviti);
		digitalWrite(10,sviti);
	}

}
