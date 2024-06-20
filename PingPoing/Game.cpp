#ifndef GAME_H
#define GAME_H

#include "Paddle.cpp"
#include "raylib.h"
#include "Ball.cpp"

struct Game {
	bool gameOver;

	void checkPlayerWon(int screenWidth, int screenHeight, Paddle& p1, Paddle& p2, Color color, Ball& ball) {
		if (p1.score >= 3) {
			DrawText("Player 1 Has Won", screenWidth / 2 - 230, screenHeight / 2, 50, color);
			ball.ballSpeedX = 0;
			ball.ballSpeedY = 0;
			p1.paddleSpeedY = 0;
			p2.paddleSpeedY = 0;
		}
		else if (p2.score >= 3) {
			DrawText("Player 2 Has Won", screenWidth / 2 - 230, screenHeight / 2, 50, color);
			ball.ballSpeedX = 0;
			ball.ballSpeedY = 0;
			p1.paddleSpeedY = 0;
			p2.paddleSpeedY = 0;
		}
	}

	void resetGame(int )
};

#endif