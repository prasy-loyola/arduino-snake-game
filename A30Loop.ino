

int time_elapsed = 0;
void loop() {
  readController();
  if (time_elapsed >= delay_ms ) {
    moveSnake(snake_direction);
    drawSnake();
    time_elapsed = 0;
  }
  delay(10);
  time_elapsed += 10;
}
