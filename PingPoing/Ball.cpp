#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include "Paddle.cpp"

struct Ball {
	float ballX;
	float ballY;
	float ballRadius;
	float ballSpeedX;
	float ballSpeedY;
	float ballCenter;

	void updatePosition(float dT) {
		ballX += ballSpeedX * dT;
		ballY += ballSpeedY * dT;
	}

	void collisionCheckWithFirstPaddle(float paddleBottom, float paddleX, float paddleY) {
		float ballCenter = ballY - (ballRadius / 2);
		if (ballX < paddleX && ballCenter < paddleBottom && ballCenter > paddleY) {
			ballX = paddleX;
			ballSpeedX *= -1;
		}
	}

	void collisionCheckWithSecondPaddle(float paddleBottom, float paddleX, float paddleY) {
		float ballCenter = ballY - (ballRadius / 2);
		if (ballX > paddleX && ballCenter < paddleBottom && ballCenter > paddleY) {
			ballX = paddleX;
			ballSpeedX *= -1;
		}
	}

	void collisionWithWindowBorders(int screenWidth, int screenHeight, Paddle& p1, Paddle& p2) {
		if (ballY > screenHeight) {
			ballY = (float)screenHeight;
			ballSpeedY *= -1;
		}
		else if (ballY < 0) {
			ballY = 0;
			ballSpeedY *= -1;
		}
		else if (ballX > screenWidth) {
			ballX = (float)screenWidth;
			ballSpeedX *= -1;
			p1.score++;
		}
		else if (ballX < 0) {
			ballX = 0;
			ballSpeedX *= -1;
			p2.score++;
		}
	}
};

#endif