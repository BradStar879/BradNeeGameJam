#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"

#include <iostream>
using namespace std;

int main() {

	cout << "Yay! :) " << endl;
	Engine engine;
	engine.Initialize("Brad and Nee Game Jam");

	Sprite background = Sprite("Assets/Images/menubg.png", 0, 0);
	Sprite testSprite = Sprite("Assets/Images/Pink_Button.png", 100, 100);
	
	while(true) {
		
		engine.Update();
		background.Update();
		testSprite.Update();

		background.SetScale(.667f);
		testSprite.SetScale(.667f);
		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
			testSprite.RotateBy(10);
		}
		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_RIGHT)) {
			testSprite.RotateBy(-10);
		}

		if (Keyboard::Key(GLFW_KEY_W)) {
			testSprite.MoveUp();
		}
		if (Keyboard::Key(GLFW_KEY_S)) {
			testSprite.MoveDown();
		}
		if (Keyboard::Key(GLFW_KEY_D)) {
			testSprite.MoveRight();
		}
		if (Keyboard::Key(GLFW_KEY_A)) {
			testSprite.MoveLeft();
		}
		if (Keyboard::Key(GLFW_KEY_Q)) {
			engine.HideMouse();
		}
		if (Keyboard::Key(GLFW_KEY_E)) {
			engine.ShowMouse();
		}

		//testSprite.MoveTo((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());

		engine.BeginRender();
		background.Render();
		testSprite.Render();
		engine.EndRender();
	}

	return 0;

}