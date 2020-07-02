#include "Desktop.h"

Desktop::Desktop(GameStateManager * _gsm) {
	Init(_gsm);
}

void Desktop::Init(GameStateManager * _gsm) {
	background = Sprite("Assets/Images/desktopwallpaper.png", 0, 0);
	terminalIcon = TerminalIcon(30, 80, .5);
	taskbar = Taskbar();
}

void Desktop::Update() {
	background.Update();
	terminalIcon.Update();
	taskbar.Update();

}

void Desktop::Render() {
	background.Render();
	terminalIcon.Render();
	taskbar.Render();
}