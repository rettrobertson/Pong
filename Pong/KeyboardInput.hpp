#pragma once

#include "raylib.h"
#include <map>
#include <functional>

class KeyboardInput {
public:
	void registerCommand(KeyboardKey key, bool keyPressOnly, std::function<void(float)> const callback);
	void update(float time);

private:
	struct CommandEntry {
	public:
		KeyboardKey key;
		bool keyPressOnly;
		std::function< void(float) > callback;

		CommandEntry(KeyboardKey key, bool keyPressOnly, std::function<void(float)> const callback)
			: key(key), keyPressOnly(keyPressOnly), callback(callback)
		{
		}
	};
	bool keyPressed(KeyboardKey key);
	std::map<KeyboardKey, bool> m_statePrevious;
	std::map<KeyboardKey, CommandEntry> m_commandEntries;
	
};

