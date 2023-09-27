#pragma once

#include "SpriteSheet.h"
#include <stdio.h>
#include <wchar.h>

class Object_Game {
protected:
	Object_Game** objectArray;
	int objectIndex;

	SpriteSheet* ss;			//sprite sheet that will represent this object in the game
	float scaleFactor;			//scaleFactor when drawing our spritesheet
	bool isDestroyable;			//Can this object be destroyed by collisions (bullets, ships)

	float x;					//x coordinate for this game object
	float y;					//y coordinate for this game object

public:
	Object_Game(int objectIndex, int x, int y, SpriteSheet* ss, Object_Game** objectArray, float scaleFactor = 1.0f);


	virtual void UpdateObjectPosition();
	virtual void AnimateSprite() = 0;
	virtual void CollisionCheck();

	void Render();
	int GetX();
	int GetY();
	float GetWidth();
	float GetHeight();
};