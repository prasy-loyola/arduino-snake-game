unsigned char generateFood() {
  unsigned char value = random(0x1, 0x9);
  unsigned char addr = random(0, 8) << 4;
  unsigned char foodAddr = (random(0, 8) << 4 | random(0x1, 0x9));
  return isInSnakeBody(foodAddr) ? generateFood() : foodAddr;
}

bool isInSnakeBody(unsigned char point){
  for (int i = 0; (i < 64) && (snake_body[i] > 0x00); i++) {
    if (snake_body[i] == point) {
      return true;
    }
  }
  return false;
}

void resetSnake(){
  for (int i=0;i<64;i++){
      snake_body[i] = 0x00;
  }
  snake_body[0] = 0x01;
  delay(delay_ms * 3);
  snake_direction = SNAKE_DIRECTION_RIGHT;
}

void restartGame() {
  clear();
  delay(delay_ms / 2);
  drawSnake();
  delay(delay_ms / 2);
  clear();
  delay(delay_ms / 2);
  drawSnake();
  resetSnake();
  food_position = generateFood();
  clear();
}
