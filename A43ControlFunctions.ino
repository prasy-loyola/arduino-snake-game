const String RIGHT_CODE = "7602FD", UP_CODE = "7622DD", DOWN_CODE = "7612ED", LEFT_CODE = "7632CD";
String HEXcode;
void readController() {
  if (irrecv.decode(&results)) {
    HEXcode = String(results.value, HEX);
    HEXcode.toUpperCase();
    if ((HEXcode == DOWN_CODE) && ( snake_direction != SNAKE_DIRECTION_UP )) {
      snake_direction = SNAKE_DIRECTION_DOWN;
    } else if ((HEXcode == UP_CODE) && (snake_direction != SNAKE_DIRECTION_DOWN)) {
      snake_direction = SNAKE_DIRECTION_UP;
    } else if ((HEXcode == RIGHT_CODE) && (snake_direction != SNAKE_DIRECTION_LEFT)) {
      snake_direction = SNAKE_DIRECTION_RIGHT;
    } else if ((HEXcode == LEFT_CODE) && (snake_direction != SNAKE_DIRECTION_RIGHT)) {
      snake_direction = SNAKE_DIRECTION_LEFT;
    }
    irrecv.resume();
  }

}
