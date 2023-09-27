#include "Object_Game.h"

/*----Public----*/

Object_Game::Object_Game(int objectIndex, int x, int y ,SpriteSheet* ss, Object_Game** objectArray, float scaleFactor) {
	this->objectArray = objectArray;
	this->x = float(x);
	this->y = float(y);

	this->ss = ss;
	this->objectIndex = objectIndex;
	this->scaleFactor = scaleFactor;
}


void Object_Game::UpdateObjectPosition() {
}

//AnimateSprite is pure virtual

void Object_Game::CollisionCheck() {

}

void Object_Game::Render() {
	UpdateObjectPosition();		//virtual call
	AnimateSprite();			//virtual call (pure)
	CollisionCheck();			//virtual call
}

int Object_Game::GetX() {
	return x;
}

int Object_Game::GetY() {
	return y;
}

float Object_Game::GetWidth() {
	return scaleFactor * ss->Width();
}

float Object_Game::GetHeight() {
	return scaleFactor * ss->Height();
}