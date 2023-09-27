#include "Object_Player.h"

Object_Player::Object_Player(int objectIndex, int startI, int endI, float velocityx, float velocityy, int x, int y, SpriteSheet* ss, Object_Game** objectArray, int frames, int speed, float scaleFactor) : Object_Mobile(objectIndex, velocityx, velocityy, x, y, ss, objectArray, scaleFactor)
{
	this->speed = speed;
	//this->frames = frames;
	startIndex = startI;
	endIndex = endI;

	this->fstframe = 0;
	this->sndframe = 1;
	this->frames = fstframe;
	index = 0;
}

void Object_Player::Setvelocity(int xMod, int yMod)
{
	velocityX = xMod;
	velocityY = yMod;
}

void Object_Player::AnimateSprite()
{
	//int aniframe = index++ / speed % frames;

	if (frames == fstframe)
	{
		frames = sndframe;
	}
	else
	{
		frames = fstframe;
	}
	ss->Draw(frames, x, y, scaleFactor);
}

void  Object_Player::changedirection(int first, int second)
{
	this->fstframe = first;
	this->sndframe = second;

	this->frames = fstframe;
}

void Object_Player::UpdateObjectPosition()
{
	oldx = x;
	oldy = y;
	x += velocityX;
	y += velocityY;
	velocityX = velocityY = 0;  // Move once per click
	if (x < 0) x = 0;
	else if (x > SCREENWIDTH - GetWidth()) x = SCREENWIDTH - GetWidth();

	if (y < 0) y = 0;
	else if (y > SCREENHEIGHT - GetHeight()) y = SCREENHEIGHT - GetHeight();
}




void Object_Player::CollisionCheck()
{
	if (y < 0) {
		objectArray[objectIndex] = NULL;
		delete this;
		return;
	}

	//create the local rectangle
	RECT r1;
	r1.left = (long)x;
	r1.top = (long)y;
	r1.right = (long)x + GetWidth();
	r1.bottom = (long)y + GetHeight();

	for (int idx = startIndex; idx < endIndex; idx++)
	{
		if (objectArray[idx])
		{
			//only create the second rectangle when another object exists
			RECT r2;
			r2.left = (long)objectArray[idx]->GetX();
			r2.top = (long)objectArray[idx]->GetY();
			r2.right = (long)objectArray[idx]->GetX() + objectArray[idx]->GetWidth();
			r2.bottom = (long)objectArray[idx]->GetY() + objectArray[idx]->GetHeight();

			RECT dest; //not used
			//use the intersect to return a bool


			if (IntersectRect(&dest, &r1, &r2))
			{
				if (idx >= 430 && idx <= 565) //dot spot in array
				{
					delete objectArray[idx];  // This will delete
					objectArray[idx] = NULL;
					points += 1;
				}
				else
				{
					x = oldx;
					y = oldy;
				}
			}
		}
	}
}

int Object_Player::getpoints()
{
	return points;
}