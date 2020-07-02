#include "MainMenu.h"
#include "Desk.h"

MainMenu::MainMenu(GameStateManager * _gsm) {
	Init(_gsm);
}

void MainMenu::Init(GameStateManager * _gsm) {
	background = Sprite("Assets/Images/Menu_BG.png", 0, 0);
	newGameButton = MenuButton("Assets/Images/New_Game.png", width / 2 - 300, 650, "New Game", "", "Assets/Images/New_Game_Pressed.png");
	loadGameButton = MenuButton("Assets/Images/Load_Game.png", width / 2 - 300, 500, "Load Game", "", "Assets/Images/Load_Game_Pressed.png");
	settingsButton = MenuButton("Assets/Images/Settings.png", width / 2 - 300, 350, "Settings", "", "Assets/Images/Settings_Pressed.png");
	quitButton = MenuButton("Assets/Images/Quit.png", width / 2 - 300, 200, "Quit", "", "Assets/Images/Quit_Pressed.png");
}

void MainMenu::Update() {
	if (Keyboard::KeyDown(GLFW_KEY_Q)) {
		newGameButton = MenuButton("Assets/Images/New_Game.png", width / 2 - 100, 650, "New Game", "", "Assets/Images/New_Game_Pressed.png");
	}
	background.Update();
	newGameButton.Update();
	loadGameButton.Update();
	settingsButton.Update();
	quitButton.Update();
	if (newGameButton.IsClick()) {
		SetCommand("Desk");
		cout << "Desk" << endl;
	}
	else if (loadGameButton.IsClick()) {
		SetCommand("Desktop");
		cout << "Desktop" << endl;
	}
	else if (settingsButton.IsClick()) {
		cout << "Settings" << endl;
	}
	else if(quitButton.IsClick()) {
		SetCommand("Quit");
		cout << "Quit" << endl;
	}

}

void MainMenu::Render() {
	background.Render();
	newGameButton.Render();
	loadGameButton.Render();
	settingsButton.Render();
	quitButton.Render();
}