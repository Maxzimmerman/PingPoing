#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"

struct Paddle {
	float x;
	float y;
	float width;
	float height;
	Color color;
	int score;
	float Bottom;
	float paddleSpeedY;

	void updatePositionUp(float dT) {
		y -= paddleSpeedY * dT;
	}

	void updatePositionDown(float dT) {
		y += paddleSpeedY * dT;
	}

	void PaddleInputWS(float dT, float ScreenHeight) {
		if (IsKeyDown(KEY_W) && Bottom > 0) {
			this->updatePositionUp(GetFrameTime());
		}
		else if (IsKeyDown(KEY_S) && Bottom < ScreenHeight) {
			this->updatePositionDown(GetFrameTime());
		}
	}

	void PaddleInputUpDown(float dT, float ScreenHeight) {
		if (IsKeyDown(KEY_UP) && y > 0) {
			this->updatePositionUp(GetFrameTime());
		}
		else if (IsKeyDown(KEY_DOWN) && y + height < ScreenHeight) {
			this->updatePositionDown(GetFrameTime());
		}
	}
};

#endif