#include "GameState.h"
#include <iostream>

GameState::GameState() {

}

GameState::GameState(GameStateManager * _gsm) {
	Init(_gsm);
}

void GameState::Init(GameStateManager * _gsm) {
	gsm = _gsm;
}

void GameState::Update() {

}

void GameState::Render() {

}

string GameState::GetCommand() {
	return command;
}

void GameState::SetCommand(string newCommand) {
	command = newCommand;
}