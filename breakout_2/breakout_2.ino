#include <Gamebuino-Meta.h>

const uint8_t livesMax = 5;
uint8_t lives = 5;
// paddle
const uint16_t paddleHeight = 3;
uint16_t paddleWidth = 10;
uint8_t paddleEffect = 3;
int8_t paddleVX = 0;
int8_t paddleVXmax = 6;
int16_t paddleX = 36;
const uint16_t paddleY = 58;

// bricks
uint8_t bricks[8][7];
const uint16_t brickWidth = 9;
const uint16_t brickHeight = 3;
uint8_t bricksLeft = 0;

// ball
uint16_t ballSize = 2;
uint8_t ballState = 0;
int16_t ballX = 40;
int16_t ballY = 40;
int8_t ballVX = -1;
int8_t ballVY = -1;
uint8_t timeout = 0;
uint8_t timeoutMax = 25;

// levels
uint8_t maxLevel = 5;

void setup()
{
  gb.begin();
  levelLoader(2);
}

void loop()
{
  while (!gb.update())
    ;
  gb.lights.clear();
  // update things
  updatePaddle();
  updateBall();
  checkCollision();

  // show

  gb.display.clear();
  showPaddle();
  showLevel();

  showBall();
}
