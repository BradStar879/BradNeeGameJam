#include "Desk.h"

Desk::Desk(GameStateManager * _gsm) {
	Init(_gsm);
}

void Desk::Init(GameStateManager * _gsm) {
	background = Sprite("Assets/Images/Menu_BG.png", 0, 0);
}

void Desk::Update() {
	background.Update();

}

void Desk::Render() {
	background.Render();
}