#ifndef GAME_DESKTOP
#define GAME_DESKTOP

#include "../../Engine/GameStateManager/GameState.h"
#include "../DesktopPhysics/DesktopWindow.h"
#include "../DesktopPhysics/TerminalIcon.h"
#include "../DesktopPhysics/Taskbar.h"

class Desktop : public GameState {

public:
	Desktop(GameStateManager * _gsm);
	void Init(GameStateManager * _gsm) override;
	void Update() override;
	void Render() override;

private:
	Sprite background;
	TerminalIcon terminalIcon;
	Taskbar taskbar;
};



#endif 
