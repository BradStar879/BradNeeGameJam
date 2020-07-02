#include "DesktopIcon.h"

DesktopIcon::DesktopIcon() {
	open = false;
	clicked = false;
	clickTimer = .4f;
}

DesktopIcon::DesktopIcon(string pathname, float _x, float _y) {
	icon = Sprite(pathname, _x, _y);
	open = false;
	clicked = false;
	clickTimer = .4f;
}

DesktopIcon::DesktopIcon(string pathname, float _x, float _y, float scale) {
	icon = Sprite(pathname, _x, _y);
	icon.SetScale(scale);
	xPos = icon.GetX();
	yPos = icon.GetY();
	width = icon.GetWidth() * scale;
	height = icon.GetHeight() * scale;
	open = false;
	clicked = false;
	clickTimer = .4f;
}

void DesktopIcon::Update() {
	if (open) {
		CheckClosed();
	}
	if (!open) {
		CheckClick();
	}
	else {
		window->Update();
	}
	icon.Update();
}

void DesktopIcon::Render() {
	icon.Render();
	if (open) {
		window->Render();
	}
}

void DesktopIcon::CheckClick() {
	if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
		int mouseX = Mouse::GetMouseX();
		int mouseY = Mouse::GetMouseY();
		int spriteLeft = xPos;
		int spriteBottom = yPos;
		int spriteRight = spriteLeft + width;
		int spriteTop = spriteBottom + height;
		if (Engine::IsMouseOver(mouseX, mouseY, spriteLeft, spriteBottom, spriteRight, spriteTop)) {
			Click();
		}
	}
	if (clicked) {
		clickTimer -= Engine::GetDT();
		if (clickTimer <= 0) {
			clickTimer = .4f;
			clicked = false;
		}
	}
	
}

void DesktopIcon::Click() {
	if (!clicked) {
		clicked = true;
	}
	else {
		open = true;
		clicked = false;
		Open();
	}
}

void DesktopIcon::Open() {

}

void DesktopIcon::CheckClosed() {
	if (window->IsClosed()) {
		open = false;
		delete window;
	}
}
