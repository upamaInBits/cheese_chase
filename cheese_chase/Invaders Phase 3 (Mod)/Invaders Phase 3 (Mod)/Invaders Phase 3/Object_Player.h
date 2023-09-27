#pragma once
#include "Object_Mobile.h"

class Object_Player : public Object_Mobile
{
protected:
	int speed;					//Speed divisor to slow animation
	int frames;					//Frames in the animation
	int index;					//Index of our sprite animation

	//Will be used to detect collisions
	int startIndex;
	int endIndex;
	int oldx;
	int oldy;

	// sprite directions
	int fstframe;
	int sndframe;

	int points;

public:
	Object_Player(int objectIndex, int startI, int endI, float velocityx, float velocityy, int x, int y, SpriteSheet* ss, Object_Game** objectArray, int frames, int speed = 1, float scaleFactor = 1.0f);
	void Setvelocity(int xMod, int yMod);		//Call to change the x,y value of the Player's Ship by the values xMod,yMod
	void AnimateSprite() override;
	void UpdateObjectPosition() override;
	void CollisionCheck() override;
	void changedirection(int first, int second);
	int getpoints();
};