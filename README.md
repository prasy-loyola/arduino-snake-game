# arduino-snake-game

A snake game played using a LED grid and a TV remote control or any IR emitter, implemented in arduino

## Pin configurations:

### 8x8 LED Grid connected with Max7219 chip

- Data In (DIN) - PIN 11
- Enable Pin (CS) - PIN 10
- Clock Pin (SCK) - PIN 13

### IR Receiver

- Data Pin (DIN) - PIN 3

### Libraries Used

- bitBangedSPI ( https://github.com/nickgammon/bitBangedSPI)
- SPI
- IRemote

Note: You can change the code for the direction arrow keys in the A43ControlFunctions.ino file.
