#include "Object_Block.h"

Object_Block::Object_Block(int objectIndex, int x, int y, SpriteSheet* ss, Object_Game** objectArray, float scaleFactor) : Object_Game(objectIndex, x, y, ss, objectArray, scaleFactor)
{
}

void Object_Block::AnimateSprite()
{
	ss->Draw(x, y, scaleFactor);
}
