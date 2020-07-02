#include "GameStateManager.h"

GameStateManager::GameStateManager() {
	stateStack = stack<GameState *>();
}

void GameStateManager::Update() {
	stateStack.top()->Update();
}

void GameStateManager::Render() {
	stateStack.top()->Render();
}

void GameStateManager::Push(GameState * gs) {
	stateStack.push(gs);
}

void GameStateManager::Pop() {
	if (stateStack.size() > 1) {
		stateStack.pop();
	}
}

string GameStateManager::GetCommand() {
	string commandCopy = stateStack.top()->GetCommand();
	if (commandCopy.compare("None") != 0) {
		stateStack.top()->SetCommand("None");
	}
	return commandCopy;
}