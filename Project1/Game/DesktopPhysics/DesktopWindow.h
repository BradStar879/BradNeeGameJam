#ifndef GAME_DESKTOPWINDOW
#define GAME_DESKTOPWINDOW

#include "../../Engine/IO/Mouse.h"
#include "../../Engine/IO/Keyboard.h"
#include "../../Engine/Graphics/Sprite.h"
#include "../../Engine/Engine.h"

class DesktopWindow {

public:
	DesktopWindow();
	DesktopWindow(string pathname, float _x, float _y);
	virtual void Update();
	void Render();

	void CheckDragWindow();
	void CheckReleaseWindow();
	void CheckCloseWindow();
	void CheckMoveWindow();
	void CheckSelected();

	void MoveWindow(float _x, float _y);

	bool IsClosed();
	bool IsSelected();

private:
	float xPos;
	float yPos;
	float width;
	float height;
	float barHeight;
	float taskbarHeight;

	float tempX;
	float tempY;

	bool mouseDown;
	bool mouseUp;

	bool selected;
	bool fullscreen;
	bool dragging;
	bool exiting;
	bool exit;

	Sprite window;
};

#endif
