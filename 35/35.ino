byte led = 10; //pin s LED diodou
byte pot = A4; //pin s fotorezistorem
int val; //prom�nn� p�ipraven� k uchov�n� hodnot
void setup() {
//sem nic nep�eme
}
void loop() {
val = analogRead(pot)/4; //�ten� hodnoty na A4 a �prava rozsahu
analogWrite(led, val); //generov�n� PWM
}
