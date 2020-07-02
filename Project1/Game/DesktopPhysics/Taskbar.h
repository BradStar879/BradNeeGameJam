#ifndef GAME_TASKBAR
#define GAME_TASKBAR

#include "../../Engine/Graphics/Sprite.h"

class Taskbar {

public:
	Taskbar();

	void Update();
	void Render();

	void CheckClick();
	void OpenMenu();
	void CloseMenu();

	int GetHeight();

private:
	Sprite taskbarImage;
	bool menuOpen;
};



#endif 
