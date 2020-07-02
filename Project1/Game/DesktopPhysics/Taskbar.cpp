#include "Taskbar.h"

Taskbar::Taskbar() {
	taskbarImage = Sprite("Assets/Images/taskbar.png", 0, 0);
	menuOpen = false;
}

void Taskbar::Update() {
	CheckClick();
	taskbarImage.Update();
}

void Taskbar::Render() {
	taskbarImage.Render();
}

void Taskbar::CheckClick() {

}

void Taskbar::OpenMenu() {

}

void Taskbar::CloseMenu() {

}

int Taskbar::GetHeight() {
	return taskbarImage.GetHeight();
}

