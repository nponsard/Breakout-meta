void checkCollision()
{
    if (ballY > paddleY + paddleHeight)
    {
        lives--;
        paddleEffect = 3;
        gb.lights.drawPixel(0, 3, RED);
        gb.lights.drawPixel(1, 3, RED);
    }
    else
    {
        // borders of the screen
        if (ballY < 1)
            ballVY = -ballVY;
        if (ballX < 1)
        {
            ballX = 0;
            ballVX = -ballVX;
            gb.lights.drawPixel(0, 2, WHITE);
        }
        else if (ballX > 78)
        {
            ballX = 78;
            ballVX = -ballVX;
            gb.lights.drawPixel(1, 2, WHITE);
        }
        else if (gb.collideRectRect(ballX, ballY, ballSize, ballSize,
                                    paddleX, paddleY, paddleWidth, paddleHeight)) //paddle
        {
            ballVY = -ballVY;
            ballVX += paddleVX / 2;
            ballY = paddleY - ballSize;
        }
        else
        {
            // bricks
            bool bounced[2] = {false, false};
            bricksLeft = 0;
            for (uint8_t x = 0; x < 8; x++)
            {
                for (uint8_t y = 0; y < 7; y++)
                {
                    if (bricks[x][y] != 0)
                    {
                        bricksLeft += 1;
                        uint16_t bx = (brickWidth + 1) * x + 1;
                        uint16_t by = (brickHeight + 1) * y + 5;
                        if (gb.collideRectRect(ballX, ballY, ballSize, ballSize,
                                               bx, by, brickWidth + 1, brickHeight + 1))
                        {
                            if (ballY + ballSize / 2 > by && ballY < by + brickHeight)
                            {
                                bounced[1] = true;
                            }
                            else
                            {
                                bounced[0] = true;
                            }

                            if (x < 4)
                            {
                                gb.lights.drawPixel(0, 0, WHITE);
                            }
                            else
                            {
                                gb.lights.drawPixel(1, 0, WHITE);
                            }

                            switch (bricks[x][y]) // launch powerup
                            {

                            default:
                                break;
                            }
                            bricks[x][y] = 0;
                        }
                    }
                }
            }

            if (bounced[0])
            {
                ballVY = -ballVY;
            }
            else if (bounced[1])
            {
                ballVX = -ballVX;
            }
        }
    }
}
