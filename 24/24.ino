int pomocna;

#define sviti HIGH 
#define nesviti LOW 

int t;
int pred = 0;
int stav;
void setup(){
	Serial.begin(9600);
	pinMode(13,OUTPUT);
	pinMode(A1,INPUT_PULLUP);
}
void loop(){
	t = !digitalRead(A1);
	stav = digitalRead(13);
	if(t == 0 && pred == 1){
		// stisknuti dokonceno
		digitalWrite(13,!stav);
		Serial.println("Tla��tko stisknuto, p�ep�n�m sv�tlo");
	}
	pred = t;

	if (Serial.available()>0){
		pomocna=Serial.read() - 48;
		if(pomocna == 1){
			Serial.println("S�riov� linka: p�ijato 1");
			digitalWrite(13,sviti);
		}
		else if(pomocna == 0){
			Serial.println("S�riov� linka: p�ijato 0");
			digitalWrite(13,nesviti);
		}
	}

}
