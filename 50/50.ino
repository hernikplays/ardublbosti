#include <EEPROM.h>
int count=0;
byte b1;
byte b2;
void setup(){
}
void loop(){
	count++;
	b1=count/256;
	b2=count%256;
	EEPROM.write(100, b1);
	EEPROM.write(101, b2);
	count=0;
	b1=0;
	b2=0;
	b1=EEPROM.read(100);
	b2=EEPROM.read(101);
	count=(b1*256)+b2;
}
