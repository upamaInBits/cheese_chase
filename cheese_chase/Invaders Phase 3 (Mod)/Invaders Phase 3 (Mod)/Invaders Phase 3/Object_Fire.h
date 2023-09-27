#pragma once
#include "Object_Mobile.h"

class Object_Fire : public Object_Mobile
{
protected:
	int speed;					//Speed divisor to slow animation
	int frames;					//Frames in the animation
	int index;					//Index of our sprite animation
	int fireindex;
	//Will be used to detect collisions
	int Start;
	int End;
	int oldx1;
	int oldy1;


public:
	Object_Fire(int objectIndex, int ghost, int startIn, int endIn, float velocityx, float velocityy, int x, int y, SpriteSheet* ss, Object_Game** objectArray, int frames, int speed = 1, float scaleFactor = 1.0f);
	void Setvelocity(int xMod, int yMod);		//Call to change the x,y value of the Player's Ship by the values xMod,yMod
	void AnimateSprite() override;
	void UpdateObjectPosition() override;
	void CollisionCheck() override;
	bool ranintowall = true;
	int scores;
};