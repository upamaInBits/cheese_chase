#pragma once
#include "Object_Bullets.h"

class Object_Bullets_Player : public Object_Bullets
{
public:
	Object_Bullets_Player(int objectIndex, int startIndex, int endIndex, float velocityx, float velocityy, int x, int y, SpriteSheet *ss, Object_Game ** objectArray, float scaleFactor = 1.0f);
	void  CollisionCheck() override;
};