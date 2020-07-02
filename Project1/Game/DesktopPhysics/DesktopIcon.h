#ifndef GAME_DESKTOPICON
#define GAME_DESKTOPICON

#include "../../Engine/IO/Mouse.h"
#include "../../Engine/IO/Keyboard.h"
#include "../../Engine/Graphics/Sprite.h"
#include "../../Engine/Engine.h"
#include "DesktopWindow.h"

class DesktopIcon {

public:
	DesktopIcon();
	DesktopIcon(string pathname, float _x, float _y);
	DesktopIcon(string pathname, float _x, float _y, float scale);

	void Update();
	void Render();

	void CheckClick();
	void Click();
	virtual void Open();
	void CheckClosed();

	DesktopWindow * window;

private:
	float xPos;
	float yPos;
	float width;
	float height;

	bool open;
	bool clicked;
	double clickTimer;

	Sprite icon;
};



#endif