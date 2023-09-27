#include "Object_Fire.h"
#include "Object_Player.h"
#include "GameController.h"
#include "Level_GameOver.h"

Object_Fire::Object_Fire(int objectIndex, int ghostI, int startI, int endI, float velocityx, float velocityy, int x, int y, SpriteSheet* ss, Object_Game** objectArray, int frames, int speed, float scaleFactor) : Object_Mobile(objectIndex, velocityx, velocityy, x, y, ss, objectArray, scaleFactor)
{
	this->speed = speed;
	this->frames = frames;
	Start = startI;
	End = endI;
	index = 0;
	this->fireindex = ghostI;
}

void Object_Fire::Setvelocity(int xMod1, int yMod1)
{
	velocityX = xMod1;
	velocityY = yMod1;
}

void Object_Fire::UpdateObjectPosition()
{
	oldx1 = x;
	oldy1 = y;
	x += velocityX;
	y += velocityY;

	if (x < (0 - GetWidth()))
	{
		x = SCREENWIDTH;
	}
}

void Object_Fire::AnimateSprite()
{
	ss->Draw(fireindex, x, y, scaleFactor);
}

void Object_Fire::CollisionCheck()
{
	RECT dest; //not used
	//use the intersect to return a bool

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


	for (int idx = Start; idx < End; idx++)
	{
		if (objectArray[idx])
		{
			//only create the second rectangle when another object exists
			RECT r2;
			r2.left = (long)objectArray[idx]->GetX();
			r2.top = (long)objectArray[idx]->GetY();
			r2.right = (long)objectArray[idx]->GetX() + objectArray[idx]->GetWidth();
			r2.bottom = (long)objectArray[idx]->GetY() + objectArray[idx]->GetHeight();


			if (IntersectRect(&dest, &r1, &r2))
			{
				x = oldx1;
				y = oldy1;

				ranintowall = true;
			}
		}
	}

	if (objectArray[1000] != NULL)
	{
		RECT r3; //pacman rectangle

		r3.left = (long)objectArray[1000]->GetX();
		r3.top = (long)objectArray[1000]->GetY();
		r3.right = (long)objectArray[1000]->GetX() + objectArray[1000]->GetWidth();
		r3.bottom = (long)objectArray[1000]->GetY() + objectArray[1000]->GetHeight();

		if (IntersectRect(&dest, &r1, &r3))
		{
			Object_Player* temp1 = dynamic_cast <Object_Player*>(objectArray[1000]);
			if (temp1)
			{
				scores = temp1->getpoints();
			}

			Object_Player* temp2 = (Object_Player*)objectArray[1000];
			objectArray[1000] = NULL;
			delete temp2;

			GameController::SwitchLevel(new Level_GameOver(scores, L"YOU LOSE"));
		}
	}
}