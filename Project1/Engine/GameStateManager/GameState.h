#ifndef GAME_GAMESTATE
#define GAME_GAMESTATE

#include "../../Engine/Graphics/Sprite.h"
#include "../../Game/MenuButtons/MenuButton.h"
#include "GameStateManager.h"
#include "../IO/Mouse.h"
#include "../IO/Keyboard.h"
#include <string>
using namespace std;

class GameStateManager;

class GameState {

public:
	GameState();
	GameState(GameStateManager * _gsm);

	virtual void Init(GameStateManager * _gsm);
	virtual void Update();
	virtual void Render();

	const int width = 1920;
	const int height = 1080;
	GameStateManager * gsm;

	string GetCommand();
	void SetCommand(string newCommand);

private:
	string command;
};


#endif