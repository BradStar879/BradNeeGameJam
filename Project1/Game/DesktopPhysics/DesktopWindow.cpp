#include "DesktopWindow.h"

DesktopWindow::DesktopWindow() {

}

DesktopWindow::DesktopWindow(string pathname, float _x, float _y) {
	window = Sprite(pathname, _x, _y);
	xPos = window.GetX();
	yPos = window.GetY();
	width = window.GetWidth();
	height = window.GetHeight();
	barHeight = 34;
	taskbarHeight = 65;
	mouseDown = false;
	mouseUp = false;
	selected = false;
	fullscreen = false;
	dragging = false;
	exiting = false;
	exit = false;
}

void DesktopWindow::Update() {
	mouseDown = Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT);
	mouseUp = Mouse::ButtonUp(GLFW_MOUSE_BUTTON_LEFT);
	CheckCloseWindow();
	CheckDragWindow();
	CheckReleaseWindow();
	CheckMoveWindow();
	CheckSelected();
	window.Update();
}

void DesktopWindow::Render() {
	window.Render();
}

void DesktopWindow::CheckDragWindow() {
	if (mouseDown && !dragging) {
		cout << "click down" << endl;
		int mouseX = Mouse::GetMouseX();
		int mouseY = Mouse::GetMouseY();
		int topWidth = xPos + width;
		int topY = yPos + height - barHeight;
		int topHeight = yPos + height;
		if (Engine::IsMouseOver(mouseX, mouseY, xPos, topY, topWidth, topHeight) && !exiting) {
			dragging = true;
			tempX = xPos - Mouse::GetMouseX();
			tempY = yPos - Mouse::GetMouseY();
		}
	}
}

void DesktopWindow::CheckReleaseWindow() {
	if (dragging) {
		int mouseX = Mouse::GetMouseX();
		int mouseY = Mouse::GetMouseY();
		if (mouseUp || !Engine::IsMouseOver(mouseX, mouseY, 0, taskbarHeight, Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT)) {
			dragging = false;
			if (yPos + height > Engine::SCREEN_HEIGHT) {
				MoveWindow(xPos, Engine::SCREEN_HEIGHT - height);
			}
		}
	}
}

void DesktopWindow::CheckCloseWindow() {
	int mouseX = Mouse::GetMouseX();
	int mouseY = Mouse::GetMouseY();
	int left = xPos + width - (34 * Engine::GetWidthMult());
	int right = xPos + width - (4 * Engine::GetWidthMult());
	int bottom = yPos + height - (32 * Engine::GetHeightMult());
	int top = yPos + height - (2 * Engine::GetHeightMult());
	if (Engine::IsMouseOver(mouseX, mouseY, left, bottom, right, top)) {
		if (mouseDown) {
			exiting = true;
		}
		else if (mouseUp && exiting) {
			exit = true;
		}
	}
	else if (exiting) {
		exiting = false;
	}
}

void DesktopWindow::CheckMoveWindow() {
	if (dragging) {
		MoveWindow(Mouse::GetMouseX() + tempX, Mouse::GetMouseY() + tempY);
	}
}

void DesktopWindow::CheckSelected() {
	if (mouseDown) {
		int mouseX = Mouse::GetMouseX();
		int mouseY = Mouse::GetMouseY();
		int right = xPos + width;
		int top = yPos + height;
		if (Engine::IsMouseOver(mouseX, mouseY, xPos, yPos, right, top)) {
			selected = true;
			
		}
		else {
			selected = false;
		}
	}
}

void DesktopWindow::MoveWindow(float _x, float _y) {
	window.MoveTo(_x, _y);
	xPos = window.GetX();
	yPos = window.GetY();
}

bool DesktopWindow::IsClosed() {
	return exit;
}

bool DesktopWindow::IsSelected() {
	return selected;
}