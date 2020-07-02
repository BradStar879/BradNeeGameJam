#ifndef	GAME_MAINMENU
#define	GAME_MAINMENU

#include "../../Engine/GameStateManager/GameState.h"

class MainMenu: public GameState {

public:
	MainMenu(GameStateManager * _gsm);
	void Init(GameStateManager * _gsm) override;
	void Update() override;
	void Render() override;
	
private:
	Sprite background;
	MenuButton newGameButton;
	MenuButton loadGameButton;
	MenuButton settingsButton;
	MenuButton quitButton;
};



#endif 