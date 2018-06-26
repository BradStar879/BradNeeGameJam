#include "Keyboard.h"

bool Keyboard::keys[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysDown[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysUp[GLFW_KEY_LAST] = { 0 };

void Keyboard::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key < 0) {
		return;
	}

	if (action != GLFW_RELEASE && keys[key] == false) {
		keysDown[key] = true;
		keysUp[key] = false;
	}

	if (action == GLFW_RELEASE && keys[key] == true) {
		keysDown[key] = false;
		keysUp[key] = true;
	}

	keys[key] = action != GLFW_RELEASE;
}

bool Keyboard::KeyDown(int key) {
	bool down = keysDown[key];
	keysDown[key] = false;
	return down;
}

bool Keyboard::KeyUp(int key) {
	bool up= keysUp[key];
	keysUp[key] = false;
	return up;
}

bool Keyboard::Key(int key) {
	return keys[key];
}

