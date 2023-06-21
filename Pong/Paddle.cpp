#include "Paddle.hpp"


Paddle::Paddle() {
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	speed = 0;
	color = WHITE;
}
Paddle::Paddle(float x, float y, float width, float height, Color color)
	: x(x), y(y), width(width), height(height), speed(0.5), color(color)

{
}

float Paddle::getHeight() const {
	return height;
}

void Paddle::render() const{
	DrawRectangle(x, y, width, height, color);
}

void Paddle::update(float time) {
	for (Ball* ball : balls)
	{
		if (ball->y > y - ball->getRadius() && ball->y < y + static_cast<float>(height) + ball->getRadius() && ball->x > x - ball->getRadius() && ball->x < x + static_cast<float>(width) + ball->getRadius()) {
			float paddleCenter = y + height / 2;
			float temp = (ball->y - paddleCenter) / (height / 2);
			float multiply = 1;
			if (ball->direction[0] > 0) {
				multiply = -1;
				ball->x = x - ball->getRadius() - 1;
			}
			else {
				ball->x = x + width + ball->getRadius() + 1;
			}
			ball->direction[1] = temp;
			ball->direction[0] = multiply * sqrt(1 - (temp * temp));
			
			ball->increaseSpeed();
		}
	}
}

void Paddle::up(float pixels) {
	y -= pixels * speed;
}

void Paddle::down(float pixels) {
	y += pixels * speed;
}

void Paddle::addBall(Ball* ball) {
	balls.push_back(ball);
}

void Paddle::removeBall(Ball* ball) {
	remove(balls.begin(), balls.end(), ball);
}

float Paddle::getX() const{
	return x;
}

float Paddle::getWidth() const {
	return width;
}