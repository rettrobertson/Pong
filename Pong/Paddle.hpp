#pragma once
# include "Ball.hpp"
# include <vector>

class Paddle {
public:
	Paddle();
	Paddle(float x, float y, float width, float height, Color color);
	float y;
	float getHeight() const;
	float getX() const;
	float getWidth() const;

	void render() const;
	void update(float time);

	void addBall(Ball* ball);
	void removeBall(Ball* ball);

	void up(float pixels);
	void down(float pixels);

private:
	float x, width, height, speed;
	Color color;
	std::vector<Ball*> balls;
};