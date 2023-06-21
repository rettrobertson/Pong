#include "GameLoop.hpp"
#include <format>

GameLoop::GameLoop(float w, float h)
	: width(w), height(h)
{
	player1score = 0;
	player2score = 0;
	ball = Ball(1, width/2, height/2 - 45, 5, WHITE, goRight);
	goRight = !goRight;
	player1 = Paddle(50, height / 2 - 50, 5, 100, WHITE);
	player1.addBall(ptr);
	player2 = Paddle(width - 55, height / 2 - 50, 5, 100, WHITE);
	player2.addBall(ptr);
	clock = Clock(4, width, height, WHITE, 128);

	m_inputKeyboard = KeyboardInput();
	m_inputKeyboard.registerCommand(KEY_W, false, [&](float time) -> void {
		player1.up(time);
		});
	m_inputKeyboard.registerCommand(KEY_S, false, [&](float time) -> void {
		player1.down(time);
		});
	m_inputKeyboard.registerCommand(KEY_UP, false, [&](float time) -> void {
		player2.up(time);
		});
	m_inputKeyboard.registerCommand(KEY_DOWN, false, [&](float time) -> void {
		player2.down(time);
		});
	m_inputKeyboard.registerCommand(KEY_R, true, [&](float time) -> void {
		player1score = 0;
		player2score = 0;
		ball = Ball(1, width / 2, height / 2 - 45, 5, WHITE, goRight);
		goRight = !goRight;
		clock.start();
		gameOver = false;
		});
}

void GameLoop::update(float time){
	ball.update(time);
	player1.update(time);
	player2.update(time);
	m_inputKeyboard.update(time);

	if (!gameOver) {
		if (clock.update(time)) {
			ball.start();
		}
		else {
			ball.stop();
		}
	}

	if (ball.x < ball.getRadius()) {
		player2score++;
		ball = Ball(1, width / 2, height / 2 - 45, 5, WHITE, true);
		clock.start();
	}
	else if (ball.x > width - ball.getRadius()) {
		player1score++;
		ball = Ball(1, width / 2, height / 2 - 45, 5, WHITE, false);
		clock.start();
	}
	if (ball.y < ball.getRadius()) {
		ball.reverseY();
		ball.y = ball.getRadius();
	}
	else if (ball.y > height - ball.getRadius()) {
		ball.reverseY();
		ball.y = height - ball.getRadius();
	}

	if (player1.y > height - player1.getHeight()) {
		player1.y = height - player1.getHeight();
	}
	else if (player1.y < 0) {
		player1.y = 0;
	}
	if (player2.y > height - player2.getHeight()) {
		player2.y = height - player2.getHeight();
	}
	else if (player2.y < 0) {
		player2.y = 0;
	}

	if (player1score >= 11 || player2score >= 11) {
		gameOver = true;
	}
}

void GameLoop::render() const{
	BeginDrawing();

	ClearBackground(BLACK);

	DrawFPS(10, 10);

	std::string temp = std::format("{}:{}", player1score, player2score);
	const char* display = temp.c_str();
	int fontsize = 32;
	
	if (!gameOver) {
		ball.render();
		player1.render();
		player2.render();
		clock.render();
	}
	else {
		const char* display = (player1score > player2score) ? "Player 1 Wins!" : "Player 2 Wins!";
		DrawText(display, width / 2 - (MeasureText(display, 64) / 2), height / 2 - 32, 64, WHITE);
	}
	
	DrawText(display, width/2 - (MeasureText(display, fontsize)/2), fontsize/2, fontsize, WHITE);
	EndDrawing();
}


