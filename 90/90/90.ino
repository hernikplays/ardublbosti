#define pinLatch 4
#define pinClk 7
#define pinData 8
byte cislice = 3;
int pamet = 0;
void setup() {
  pinMode(pinLatch, OUTPUT);
  pinMode(pinClk, OUTPUT);
  pinMode(pinData, OUTPUT);
}
void loop() {
  pamet = analogRead(A4);
  zapisCisloNaSegment(pamet);
}
void zapisCisloNaSegment(int hodnota) {
  // mapa čísel pro segmentový displej - čísla 0 až 9
  const byte mapaSegment[] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0X80, 0X90 };
  switch (cislice--) {

    case 1:
      digitalWrite(pinLatch, LOW);
      shiftOut(pinData, pinClk, MSBFIRST, mapaSegment[hodnota / 1000]);
      shiftOut(pinData, pinClk, MSBFIRST, 0xF1);
      digitalWrite(pinLatch, HIGH);
      break;
    case 2:
      digitalWrite(pinLatch, LOW);
      shiftOut(pinData, pinClk, MSBFIRST, mapaSegment[((hodnota / 100) % 10)]);
      shiftOut(pinData, pinClk, MSBFIRST, 0xF2);
      digitalWrite(pinLatch, HIGH);
      break;
    case 3:
      digitalWrite(pinLatch, LOW);
      shiftOut(pinData, pinClk, MSBFIRST, mapaSegment[(hodnota / 10) % 10]);
      shiftOut(pinData, pinClk, MSBFIRST, 0xF4);
      digitalWrite(pinLatch, HIGH);
      break;
    default:
      digitalWrite(pinLatch, LOW);
      shiftOut(pinData, pinClk, MSBFIRST, mapaSegment[hodnota % 10]);
      shiftOut(pinData, pinClk, MSBFIRST, 0xF8);
      digitalWrite(pinLatch, HIGH);
      cislice = 3;
  }
}
