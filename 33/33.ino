#define sviti HIGH 
#define nesviti LOW 

int t;
void setup(){
	Serial.begin(9600);
	pinMode(10,OUTPUT);
	pinMode(9,OUTPUT);
}
void loop(){
	t = analogRead(A4);
	if(t < 300){
		digitalWrite(9,nesviti);
		digitalWrite(10,nesviti);
	}	
	else if(t < 600){
		digitalWrite(9,sviti);
		digitalWrite(10,nesviti);
	}
	else if(t < 800){
		digitalWrite(9,nesviti);
		digitalWrite(10,sviti);
	}
	else if(t < 1025){
		digitalWrite(9,sviti);
		digitalWrite(10,sviti);
	}

}
