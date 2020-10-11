


void loop() {

  readController();
  drawSnake();
  readController();
  moveSnake(snake_direction);
  readController();
  delay(delay_ms);
  readController();
}
