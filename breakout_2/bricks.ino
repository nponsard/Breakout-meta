void levelLoader(uint8_t level)
{
  switch (level)
  {
  case 1:
    for (uint8_t x = 0; x < 8; x++)
    {
      for (uint8_t y = 0; y < 8; y++)
      {
        bricks[x][y] = 1;
      }
    }
    break;
  case 2:
    for (uint8_t x = 0; x < 8; x++)
    {
      for (uint8_t y = 0; y < 8; y++)
      {
        bricks[x][y] = random(1, 3);
      }
    }
    break;
  default:
    for (uint8_t x = 0; x < 8; x++)
    {
      for (uint8_t y = 0; y < 8; y++)
      {
        bricks[x][y] = 1;
      }
    }
    break;
  }
}
void customLevelLoader(uint8_t levelid)
{
}

void showLevel()
{
  for (uint8_t x = 0; x < 8; x++)
  {
    for (uint8_t y = 0; y < 7; y++)
    {
      uint16_t bx = (brickWidth + 1) * x + 1;
      uint16_t by = y * (brickHeight + 1) + 5;
      // switch for custom textures
      switch (bricks[x][y])
      {
      case 0:
        break;
      case 1:
        gb.display.setColor(RED);
        gb.display.fillRect(bx, by, brickWidth, brickHeight);
        break;
      case 2:
        gb.display.setColor(BLUE);
        gb.display.fillRect(bx, by, brickWidth, brickHeight);

        break;
      default:
        gb.display.setColor(WHITE);
        gb.display.fillRect(bx, by, brickWidth, brickHeight);
        break;
      }
    }
  }
}
