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

	void checkIfButtonClicked() {
		Vector2 mousePoint = GetMousePosition();
		resetButton.hovered = CheckCollisionPointRec(mousePoint, resetButton.button);

		if (resetButton.hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			std::cout << "clicked" << std::endl;
			gameOver = false;
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
			ball.ballSpeedX = 0;
			ball.ballSpeedY = 0;
			p1.paddleSpeedY = 0;
			p2.paddleSpeedY = 0;
			gameOver = true;
			DisplayButton();
		}
		else if (p2.score >= 3) {
			DrawText("Player 2 Has Won", screenWidth / 2 - 230, screenHeight / 2, 50, color);
			ball.ballSpeedX = 0;
			ball.ballSpeedY = 0;
			p1.paddleSpeedY = 0;
			p2.paddleSpeedY = 0;
			gameOver = true;
			DisplayButton();
		}
	}
};

#endif