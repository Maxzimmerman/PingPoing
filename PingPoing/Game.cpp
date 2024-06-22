#ifndef GAME_H
#define GAME_H

#include "Paddle.cpp"
#include "raylib.h"
#include "Ball.cpp"
#include "ResetButton.cpp"
#include <iostream>

struct Game {
	bool gameOver;
	ResetButton resetButton;

	void restartGame(Paddle& p1, Paddle& p2, Ball& ball) {
		gameOver = false;
		p1.paddleSpeedY = 500;
		p2.paddleSpeedY = 500;
		ball.ballSpeedX = 300;
		ball.ballSpeedY = 300;
		p1.score = 0;
		p2.score = 0;
	}

	void endGame(Paddle& p1, Paddle& p2, Ball& ball) {
		gameOver = true;
		ball.ballSpeedX = 0;
		ball.ballSpeedY = 0;
		p1.paddleSpeedY = 0;
		p2.paddleSpeedY = 0;
	}

	void checkIfButtonClicked(Paddle& p1, Paddle& p2, Ball& ball) {
		Vector2 mousePoint = GetMousePosition();
		resetButton.hovered = CheckCollisionPointRec(mousePoint, resetButton.button);

		if (resetButton.hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			std::cout << "clicked" << std::endl;
			restartGame(p1, p2, ball);
		}
	}

	void DisplayButton() {
		if (gameOver) {
			DrawRectangleRec(resetButton.button, resetButton.color);
		}
	}

	void checkPlayerWon(int screenWidth, int screenHeight, Paddle& p1, Paddle& p2, Color color, Ball& ball) {
		if (p1.score >= 3) {
			DrawText("Player 1 Has Won", screenWidth / 2 - 230, screenHeight / 2, 50, color);
			this->endGame(p1, p2, ball);
			this->DisplayButton();
			this->checkIfButtonClicked(p1, p2, ball);
		}
		else if (p2.score >= 3) {
			DrawText("Player 2 Has Won", screenWidth / 2 - 230, screenHeight / 2, 50, color);
			this->endGame(p1, p2, ball);
			this->DisplayButton();
			this->checkIfButtonClicked(p1, p2, ball);
		}
	}
};

#endif