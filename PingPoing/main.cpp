#include "raylib.h"
#include <iostream>
#include "string"
#include "Paddle.cpp"
#include "Ball.cpp"
#include "Game.cpp"

int main() {
	InitWindow(800, 600, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);

	// Game
	Game game;
	game.gameOver = false;
	game.resetButton.button = { GetScreenWidth() / 2.0f - 50, GetScreenHeight() / 2.0f - 50, 100, 40 };
	game.resetButton.color = GREEN;
	game.resetButton.hovered = false;

	// Ball
	Ball ball;
	ball.ballX = GetScreenWidth() / 2.0f;
	ball.ballY = GetScreenHeight() / 2.0f;
	ball.ballRadius = 5;
	ball.ballSpeedX = 300;
	ball.ballSpeedY = 300;
	ball.timer = 0.0f;
	ball.interval = 1.0f;

	// Paddle
	Paddle p1;
	p1.x = 50;
	p1.y = GetScreenHeight() / 2 - 50;
	p1.width = 10;
	p1.height = 100;
	p1.color = WHITE;
	p1.score = 0;
	p1.paddleSpeedY = 500;

	Paddle p2;
	p2.x = GetScreenWidth() - 50 - 10;
	p2.y = GetScreenHeight() / 2 - 50;
	p2.width = 10;
	p2.height = 100;
	p2.color = WHITE; 
	p2.score = 0;
	p2.paddleSpeedY = 500;

	while (!WindowShouldClose()) {

		float dT = GetFrameTime();

		// Collision With Paddle
		ball.ballCenter = ball.ballY - (ball.ballRadius / 2);
		p1.Bottom = p1.y + p1.height;
		p2.Bottom = p2.y + p2.height;

		ball.updatePosition(dT);
		ball.increaseBallVelocity();
		ball.collisionWithWindowBorders(GetScreenWidth(), GetScreenHeight(), p1, p2);
		ball.collisionCheckWithFirstPaddle(p1.Bottom, p1.x, p1.y);
		ball.collisionCheckWithSecondPaddle(p2.Bottom, p2.x, p2.y);

		// input paddle 1
		p1.PaddleInputWS(dT, GetScreenHeight());
		p2.PaddleInputUpDown(dT, GetScreenHeight());

		// Game End
		game.checkPlayerWon(GetScreenWidth(), GetScreenHeight(), p1, p2, RED, ball);

		BeginDrawing();
			ClearBackground(BLACK);


			DrawCircle((int)ball.ballX, (int)ball.ballY, ball.ballRadius, WHITE);
			DrawRectangle(p1.x, p1.y, p1.width, p1.height, p1.color);
			DrawRectangle(p2.x, p2.y, p2.width, p2.height, p2.color);
			DrawText(std::to_string(p1.score).c_str(), 150, 50, 20, WHITE);
			DrawText(std::to_string(p2.score).c_str(), GetScreenWidth() - 150, 50, 20, WHITE);

			DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}