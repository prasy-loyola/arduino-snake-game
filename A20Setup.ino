void setup() {
  Serial.begin(9600);
  pinMode(LOAD_PIN, OUTPUT);
  // put your setup code here, to run once:
  bSpi->begin();
  sendControl(MAX7219_REG_SCANLIMIT, 7);
  sendControl(MAX7219_REG_DECODEMODE, 0);
  sendControl(MAX7219_REG_INTENSITY, 0);
  sendControl(MAX7219_REG_DISPLAYTEST, 15);
  delay(500);
  sendControl(MAX7219_REG_DISPLAYTEST, 0x0);

  sendControl(MAX7219_REG_SHUTDOWN, 0x1);
  delay(500);
  clear();
  delay(500);
 randomSeed(analogRead(0));
 irrecv.enableIRIn(); 
 food_position = generateFood();
}
