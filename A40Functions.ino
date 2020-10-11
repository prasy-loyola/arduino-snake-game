
unsigned char getAddr(unsigned char point) {
  return (point >> 4);
}

unsigned char getValue(unsigned char point) {
  return point == 0x00 ?  0x00 : 0x01 << ((point & 0x0F)-1);
}

void sendControl(const byte reg, const byte data1) {
  digitalWrite(LOAD_PIN, LOW);
  bSpi->transfer(reg);
  bSpi->transfer(data1);
  digitalWrite(LOAD_PIN, HIGH);
}

void clear() {
  for (int i = 0x1; i < 0x9 ; i++) {
    sendControl(i, 0x0);
  }
}
