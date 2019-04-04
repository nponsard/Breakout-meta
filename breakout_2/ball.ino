void showBall()
{
  switch (ballState)
  {
  case 1:
    gb.display.setColor(RED);
    break;
  default:
    gb.display.setColor(WHITE);
    break;
  }
  gb.display.fillRect(ballX, ballY, ballSize, ballSize);
}
void updateBall()
{
  ballX += ballVX;
  ballY += ballVY;
}
