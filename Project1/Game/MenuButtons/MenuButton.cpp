#include "MenuButton.h"
#include "../../Engine/Engine.h"
#include "../../Engine/IO/Mouse.h"

MenuButton::MenuButton() {

}

MenuButton::MenuButton(string normalpath, int _x, int _y, string buttonname, string hoverpath, string clickpath) {
	normal = Sprite(normalpath, _x, _y);
	if (hoverpath.compare("") != 0) {
		hover = Sprite(hoverpath, _x, _y);
		hasHover = true;
	}
	else {
		hasHover = false;
	}
	if (clickpath.compare("") != 0) {
		clicked = Sprite(clickpath, _x, _y);
		hasClicked = true;
	}
	else {
		hasClicked = false;
	}
	curSprite = new Sprite;
	*curSprite = normal;
	name = buttonname;
	beingClicked = false;
	isClicked = false;
}

void MenuButton::Update() {
	isClicked = false;
	if (beingClicked) {
		if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_LEFT)) {
			*curSprite = normal;
			beingClicked = false;
			isClicked = true;
		}
		else if (!IsMouseOver()) {
			beingClicked = false;
		}
	}
	else {
		*curSprite = normal;
		if (IsMouseOver()) {
			if (hasClicked && Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
				beingClicked = true;
				*curSprite = clicked;
			}
			else if (hasHover) {
				*curSprite = hover;
			}
		}
		curSprite->Update();
	}
}

void MenuButton::Render() {
	curSprite->Render();
}

string MenuButton::GetName() {
	return name;
}

bool MenuButton::IsMouseOver() {
	int mouseX = Mouse::GetMouseX();
	int mouseY = Mouse::GetMouseY();
	int spriteLeft = curSprite->GetX();
	int spriteBottom = curSprite->GetY();
	int spriteRight = spriteLeft + curSprite->GetWidth();
	int spriteTop = spriteBottom + curSprite->GetHeight();
	if (mouseX >= spriteLeft && mouseX <= spriteRight && mouseY >= spriteBottom && mouseY <= spriteTop) {
		return true;
	}
	return false;
}

bool MenuButton::IsClick() {
	return isClicked;
}
