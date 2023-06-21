#include "Ball.hpp"

Ball::Ball()
	: id(0), x(0), y(0), radius(0), color(WHITE), isMoving(false), speed(0.4)
{
	direction[0] = 0;
	direction[1] = 0;
}


Ball::Ball(int id, float x, float y, float radius, Color color, bool right) 
	: id(id), x(x), y(y), radius(radius), color(color), isMoving(false), speed(0.4)
{
	std::random_device rd;
	std::default_random_engine engine(rd());
	std::uniform_real_distribution<float> dist(0.0, 1.0);

	int rand = engine();
	float angle = dist(engine) * PI/4;

	if (right) {
		if ((rand ^ 1) == (rand + 1)) {
			angle += PI / 8;
		}
		else {
			angle *= -1;
			angle -= PI / 8;
		}
	}
	else {
		if ((rand ^ 1) == (rand + 1)) {
			angle += 5 * PI / 8;
		}
		else {
			angle *= -1;
			angle -= 5 * PI / 8;
		}
	}

	direction[0] = cos(angle);
	direction[1] = sin(angle);
}

float Ball::getRadius() const {
	return radius;
}

void Ball::reverseX() {
	direction[0] *= -1;
}

void Ball::reverseY() {
	direction[1] *= -1;
}

void Ball::render() const {
	DrawCircle(static_cast<int>(x), static_cast<int>(y), radius, color);
}

void Ball::update(float time) {
	if (isMoving) {
		x += (direction[0] * time * speed);
		y += (direction[1] * time * speed);
	}
}

int Ball::getId() const{
	return id;
}

void Ball::start() {
	isMoving = true;
}

void Ball::stop() {
	isMoving = false;
}

void Ball::increaseSpeed() {
	speed *= 1.025;
}