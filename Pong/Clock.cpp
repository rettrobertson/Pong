#include "Clock.hpp"
#include <format>

void Clock::start() {
	current_count = static_cast<float>(start_count * 1000);
}

bool Clock::update(float time) {
	current_count -= time;
	if (current_count < 0) {
		current_count = 0;
		return true;
	}
	return false;
}

void Clock::render() const{
	
	if (current_count > 0) {
		std::string count = std::format("{}", static_cast<int>(current_count/1000));
		const char* display = count.c_str();
		if (current_count < 1000) {
			display = "GO!";
		}
		DrawText(display, x / 2 - (MeasureText(display, fontsize) / 2), y/2 - fontsize/2, fontsize, color);
	}
}