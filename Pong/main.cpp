#include "GameLoop.hpp"

int main() {
	const float height = 600;
	const float width = 800;
	GameLoop game = GameLoop(width, height);
	InitWindow(static_cast<int>(width), static_cast<int>(height), "Pong");
	// uncommment this to match framerate to moniter refresh rate
	//SetWindowState(FLAG_VSYNC_HINT);

	while (!WindowShouldClose()) {
		game.update(GetFrameTime() * 1000);
		game.render();
	}

	CloseWindow();
	return 0;
}