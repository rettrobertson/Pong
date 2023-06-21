#pragma once

#include "Ball.hpp"
#include "Paddle.hpp"
#include "KeyboardInput.hpp"
#include "Clock.hpp"
class GameLoop {
public:
	GameLoop(float width, float height);
	void update(float time);
	void render() const;

private:
	KeyboardInput m_inputKeyboard;
	Ball ball;
	Ball* ptr = &ball;
	Clock clock;
	Paddle player1;
	Paddle player2;

	int player1score;
	int player2score;
	float width;
	float height;
	bool goRight = true;
	bool gameOver = false;
};