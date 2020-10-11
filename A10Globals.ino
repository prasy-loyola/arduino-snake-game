const byte chips  = 1;
const int LOAD_PIN = 10;

bitBangedSPI * bSpi = new bitBangedSPI (11, bitBangedSPI::NO_PIN, 13);

// registers
enum {
  MAX7219_REG_NOOP        = 0x0,
  // codes 1 to 8 are digit positions 1 to 8
  MAX7219_REG_DECODEMODE  = 0x9,
  MAX7219_REG_INTENSITY   = 0xA,
  MAX7219_REG_SCANLIMIT   = 0xB,
  MAX7219_REG_SHUTDOWN    = 0xC,
  MAX7219_REG_DISPLAYTEST = 0xF,

}; // end of enum
enum{
  SNAKE_DIRECTION_LEFT = -0x10,
  SNAKE_DIRECTION_UP = -0x01,
  SNAKE_DIRECTION_RIGHT = 0x10,
  SNAKE_DIRECTION_DOWN = +0x01,

};

int delay_ms = 400;
unsigned char snake_body[64] = {0x01};
unsigned char food_position =0x00;
unsigned char snake_direction = SNAKE_DIRECTION_RIGHT;
