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
	if(t>600){
		digitalWrite(10,sviti);
		digitalWrite(9,nesviti);
	}
	else if(t<600){
		digitalWrite(10,nesviti);
		digitalWrite(9,sviti);
	}
	else if(t == 600){
digitalWrite(10,sviti);
		digitalWrite(9,sviti);
	}	

}
