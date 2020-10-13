
void drawSnake() {
  uint8_t columnValues[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  for (int i = 0; (i < 64) && (snake_body[i] > 0x00); i++) {
    uint8_t addr = getAddr(snake_body[i]) ;
    columnValues[addr] = columnValues[addr] | getValue(snake_body[i]);
  }
  uint8_t current_food_addr = getAddr(food_position);
  columnValues[current_food_addr] = columnValues[current_food_addr] | getValue(food_position);

  for ( int i = 0; i < 8; i++) {
    sendControl(i + 1, columnValues[i]);
  }
}


void moveSnake(int direction) {

  uint8_t new_head = snake_body[0]  + direction;
  if ((getAddr(new_head) > 0x07 ) || (getAddr(new_head) < 0x00 ) || (new_head & 0x0F) > 0x08 || (new_head & 0x0F) < 0x01 || isInSnakeBody(new_head) ) {
        restartGame();
    return;
  }

  bool grow = (new_head == food_position);

  if (grow) {
    uint8_t temp = snake_body[0];
    for (int i = 1; i < 63; i++) {
      uint8_t temp2 = snake_body[i];
      snake_body[i] = temp;
      temp = temp2;
    }
    snake_body[0] = new_head;
    food_position = generateFood();
    return;
  }
  uint8_t temp =  new_head;
  for (int i =  0 ; i < 64; i++) {
    uint8_t temp2 = snake_body[i];
    if ( temp2 == 0x00 ) {
      snake_body[i] =  0x00;
    }
    else {
      snake_body[i] = temp;
    }
    temp = temp2;
  }

}
