int pomocna;
//char pomocna;

#define sviti HIGH 
#define nesviti LOW 
void setup(){
	Serial.begin(9600);
	pinMode(13,OUTPUT);
}
void loop(){
	if (Serial.available()>0){
		pomocna=Serial.read() - 48;
		if(pomocna == 1){
			// rozsvitit
			digitalWrite(13, sviti);
		}
		else if(pomocna == 0){
			// zhasnout
			digitalWrite(13, nesviti);
		}
	}
}
