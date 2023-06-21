#include "KeyboardInput.hpp"

void KeyboardInput::registerCommand(KeyboardKey key, bool keyPressOnly, std::function<void(float)> const callback) {
	auto iter = m_commandEntries.find(key);
	if (iter != m_commandEntries.end()) {
		m_commandEntries.erase(key);
	}
	m_commandEntries.insert({ key, CommandEntry(key, keyPressOnly, callback)});

	auto temp = m_statePrevious.find(key);
	if (temp != m_statePrevious.end()) {
		m_statePrevious.erase(key);
	}
	m_statePrevious.insert({ key, false });
}

void KeyboardInput::update(float time) {
	for (const auto& pair : m_commandEntries) {
		CommandEntry entry = pair.second;

		if (entry.keyPressOnly && keyPressed(entry.key)) {
			entry.callback(time);

		}
		else if (!entry.keyPressOnly && IsKeyDown(entry.key))
		{
			entry.callback(time);
		}

		auto iter = m_statePrevious.find(entry.key);
		if (iter != m_statePrevious.end()) {
			iter->second = IsKeyDown(entry.key);
		}
	}
}

bool KeyboardInput::keyPressed(KeyboardKey key) {
	auto iter = m_statePrevious.find(key);
	if (iter != m_statePrevious.end()) {
		return (IsKeyDown(key) && !iter->second);
	}
	return (IsKeyDown(key));
}