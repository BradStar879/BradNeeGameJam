#ifndef GAME_TERMINALICON
#define GAME_TERMINALICON

#include "DesktopIcon.h"
#include "Terminal.h"

class TerminalIcon : public DesktopIcon {

public:
	TerminalIcon();
	TerminalIcon(float _x, float _y);
	TerminalIcon(float _x, float _y, float scale);

	void Open();

private:

};



#endif 