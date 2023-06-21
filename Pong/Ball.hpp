#pragma once

#include <cstdint>
#include <array>
#include <chrono>
#include "raylib.h"
#include <random>

class Ball {
public:
	Ball();
	Ball(int id, float x, float y, float radius, Color color, bool angle);
	float x;
	float y;
	std::array<float, 2> direction;
	float getRadius() const;

	int getId() const;
	void reverseX();
	void reverseY();

	void start();
	void stop();
	void increaseSpeed();

	void render() const;
	void update(float time);

private:
	int id;
	float speed;
	float radius;
	Color color;
	bool isMoving;
};