void showPaddle()
{

  for (uint8_t i = 0; i < lives; i++)
  {
    gb.display.setColor(RED);
    gb.display.fillRect(1 + i * 3, 1, 2, 2);
  }

  switch (paddleEffect)
  {
  case 0:
    gb.display.setColor(WHITE);
    gb.display.fillRect(paddleX, paddleY, paddleWidth, paddleHeight);
    break;
  case 1:
    gb.display.setColor(WHITE);
    gb.display.fillRect(paddleX, paddleY, paddleWidth, paddleHeight);
    break;
  case 2:
    gb.display.setColor(WHITE);
    gb.display.fillRect(paddleX, paddleY, paddleWidth, paddleHeight);
    gb.display.setColor(RED);
    gb.display.fillRect(paddleX + paddleWidth / 2 - 1, paddleY - 3, 2, 4);
    break;
  case 3:
    gb.display.setColor(WHITE);
    gb.display.fillRect(paddleX, paddleY, paddleWidth, paddleHeight);
    ballVX = random(-1, 2);
    ballVY = -1;
    ballX = paddleX + paddleWidth / 2 - ballSize / 2;
    ballY = paddleY - ballSize;
    break;

  default:
    gb.display.setColor(WHITE);
    gb.display.fillRect(paddleX, paddleY, paddleWidth, paddleHeight);
    break;
  }
  gb.display.setColor(BLACK);
  gb.display.drawPixel(paddleX, paddleY);
  gb.display.drawPixel(paddleX + paddleWidth - 1, paddleY);
}

void updatePaddle()
{
  switch (paddleEffect)
  {
  case 2:
    break;
  case 3:
    if (gb.buttons.pressed(BUTTON_A))
    {
      paddleEffect = 1;
    }
    break;
  }

  if (gb.buttons.repeat(BUTTON_LEFT, 1))
  {
    paddleVX -= 1;
  }
  else if (gb.buttons.repeat(BUTTON_RIGHT, 1))
  {
    paddleVX += 1;
  }
  else
  {
    paddleVX = paddleVX / 2;
  }
  paddleVX = constrain(paddleVX, (-paddleVXmax), paddleVXmax);
  paddleX += paddleVX;
  paddleX = constrain(paddleX, 0, 80 - paddleWidth);
}
