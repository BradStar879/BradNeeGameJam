#include "Sprite.h"
#include "../Engine.h"

Sprite::Sprite() {

	xPos = 0;
	yPos = 0;
	xScale = 1;
	yScale = 1;
	rot = 0;
	speed = 100;
	texture = Texture();

}

Sprite::Sprite(string imagePath) {

	texture = Texture(imagePath);
	xPos = 0;
	yPos = 0;
	xScale = 1;
	yScale = 1;
	rot = 0;
	speed = 100;
}

Sprite::Sprite(string imagePath, float _xPos, float _yPos) {

	texture = Texture(imagePath);
	xPos = _xPos * Engine::GetWidthMult();
	yPos = _yPos * Engine::GetHeightMult();
	xScale = 1;
	yScale = 1;
	rot = 0;
	speed = 100;
}

void Sprite::Update() {

}

void Sprite::Render() {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();	//New identity matrix

	//Translate then rotate then scale for correct output
	glTranslatef(xPos, yPos, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(xScale, yScale, 1);

	//Rendering
	glColor4f(1, 1, 1, 1); //No change to color or alpha
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		//Bottom left
	glVertex2f(0, 0);
	glTexCoord2f(1, 0);		//Bottom right
	glVertex2f(texture.GetWidth(), 0);
	glTexCoord2f(1, 1);		//Top Right
	glVertex2f(texture.GetWidth(), texture.GetHeight());
	glTexCoord2f(0, 1);		//Top Left
	glVertex2f(0, texture.GetHeight());
	glEnd();

	glDisable(GL_TEXTURE_2D);

}

void Sprite::SpeedTo(float x) {
	speed = x;
}

void Sprite::SpeedBy(float x) {
	speed += x;
}

void Sprite::MoveTo(float x, float y) {
	xPos = x;
	yPos = y;
}

void Sprite::MoveBy(float x, float y) {
	xPos += x;
	yPos += y;
}

void Sprite::MoveLeft() {
	xPos -= speed * Engine::GetDT();
}

void Sprite::MoveRight() {
	xPos += speed * Engine::GetDT();
}

void Sprite::MoveUp() {
	yPos += speed * Engine::GetDT();
}

void Sprite::MoveDown() {
	yPos -= speed * Engine::GetDT();
}

void Sprite::RotateTo(float x) {
	rot = x;
}

void Sprite::RotateBy(float x) {
	rot += x;
}

void Sprite::SetScale(float x) {
	xScale = x;
	yScale = x;
}

void Sprite::SetScale(float x, float y) {
	xScale = x;
	yScale = y;
}

float Sprite::GetX() {
	return xPos;
}

float Sprite::GetY() {
	return yPos;
}

int Sprite::GetWidth() {
	return texture.GetWidth();
}

int Sprite::GetHeight() {
	return texture.GetHeight();
}
