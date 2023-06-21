#pragma once
#include "raylib.h"

class Clock {
public:
	Clock() 
		:start_count(3), current_count(3000.0), x(0), y(0), color(WHITE), fontsize(32)
	{
	}
	Clock(int countdown, int x, int y, Color color, int fontsize)
		: start_count(countdown), current_count(static_cast<float>(countdown * 1000)), x(x), y(y), color(color), fontsize(fontsize)
	{
	}
	bool update(float time);
	void render() const;
	void start();
private:
	int start_count;
	float current_count;
	int x;
	int y;
	Color color;
	int fontsize;
};