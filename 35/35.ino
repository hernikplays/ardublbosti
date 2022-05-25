byte led = 10; //pin s LED diodou
byte pot = A4; //pin s fotorezistorem
int val; //promìnná pøipravená k uchování hodnot
void setup() {
//sem nic nepíšeme
}
void loop() {
val = analogRead(pot)/4; //ètení hodnoty na A4 a úprava rozsahu
analogWrite(led, val); //generování PWM
}
