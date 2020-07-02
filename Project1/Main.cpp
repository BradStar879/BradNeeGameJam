#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
#include "Game/MenuButtons/MenuButton.h"
#include "Engine/GameStateManager/GameStateManager.h"
#include "Game/GameStates/MainMenu.h"
#include "Game/GameStates/Desk.h"
#include "Game/GameStates/Desktop.h"

#include <iostream>
using namespace std;

int main() {

	cout << "Yay! :) " << endl;
	Engine engine;
	engine.Initialize("Brad and Nee Game Jam");
	GameStateManager * gsm = new GameStateManager();
	GameState * mainMenu = new MainMenu(gsm);
	GameState * desk = new Desk(gsm);
	GameState * desktop = new Desktop(gsm);
	gsm->Push(mainMenu);

	while(true) {
		engine.Update();
		gsm->Update();
		string currentCommand = gsm->GetCommand();
		if (currentCommand.compare("Desk") == 0) {
			gsm->Push(desk);
			cout << "Push Desk" << endl;
		}
		else if (currentCommand.compare("Desktop") == 0) {
			gsm->Push(desktop);
			cout << "Push Desktop" << endl;
		}
		else if (Keyboard::KeyDown(GLFW_KEY_ESCAPE)) {
			gsm->Pop();
		}
		else if (currentCommand.compare("Quit") == 0) {
			glfwTerminate();
		}
		engine.BeginRender();
		gsm->Render();
		engine.EndRender();
	}

	return 0;

}