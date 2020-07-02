#ifndef GAME_TERMINAL
#define GAME_TERMINAL

#include "DesktopWindow.h"
#include <vector>

class Terminal : public DesktopWindow {

public:
	Terminal();
	Terminal(float _x, float _y);

	void Update();

	void CheckShift();
	void AcceptInput();
	void Parse();
	void Help();


private:
	string curString;
	string oldStrings;
	bool shift;
};




#endif