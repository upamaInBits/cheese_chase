#pragma once

#include <time.h>
#include <stdio.h>
#include <stdlib.h> 

#include "Graphics.h"

#include "Object_Text.h"
#include "Object_Game.h"
#include "Object_Player.h"
#include "Object_Fire.h" //adding fire.h
#include "Object_Block.h"
#include "Object_Bullets_Player.h"

#include <ctime>

class Level_Game {
protected:
	static Graphics* gfx;

	Object_Game** objectArray;
	int objectCount;
public:
	static void Init(Graphics* graphics) {
		gfx = graphics;
	}

	virtual void Load() = 0;
	virtual void UnLoad() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;

};