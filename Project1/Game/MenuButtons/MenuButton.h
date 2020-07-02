#ifndef GAME_MENUBUTTON
#define GAME_MENUBUTTON

#include "GLFW/glfw3.h"
#include "../../Engine/Graphics/Sprite.h"

class MenuButton{

public:
	MenuButton();
	MenuButton(string normalpath, int _x, int _y, string buttonname, string hoverpath, string clickpath);

	void Update();
	void Render();

	string GetName();

	bool IsMouseOver();
	bool IsClick();

private:
	string name;

	Sprite* curSprite;
	Sprite normal;
	Sprite hover;
	bool hasHover;
	Sprite clicked;
	bool hasClicked;

	bool beingClicked;
	bool isClicked;
};


#endif