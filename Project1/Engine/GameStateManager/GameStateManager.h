#ifndef GAME_GAMESTATEMANAGER
#define GAME_GAMESTATEMANAGER

#include "GameState.h"
#include <stack>
using namespace std;

class GameState;

class GameStateManager {

public:
	GameStateManager();
	void Update();
	void Render();
	void Push(GameState * gs);
	void Pop();
	string GetCommand();
	//void ChangeCommand(string newCommand);

private:
	stack<GameState *> stateStack;
};


#endif