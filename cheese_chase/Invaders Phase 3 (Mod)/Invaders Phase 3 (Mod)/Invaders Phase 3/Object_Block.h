#pragma once
#include "Object_Game.h"

class Object_Block : public Object_Game
{
public:
	Object_Block(int objectIndex, int x, int y, SpriteSheet* ss, Object_Game** objectArray, float scaleFactor = 1.0f);
	void AnimateSprite() override;
};