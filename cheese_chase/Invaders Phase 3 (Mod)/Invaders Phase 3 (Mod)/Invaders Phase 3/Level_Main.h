#pragma once
#include "Level_Game.h"

class Level_Main : public Level_Game {
private:

	//Object_Text* txtLevelText;
	Object_Text* txtScoreText;

	bool gameOver;
	bool playerWins;

	int score;

	//SpriteSheet* imgShip = NULL;
	//SpriteSheet* imgPlayerBullet = NULL; from invader phase 1

	SpriteSheet* imgRat = NULL;
	SpriteSheet* imgFire = NULL;
	SpriteSheet* imgVerticalWall = NULL;
	SpriteSheet* imgHorizontalWall = NULL;
	SpriteSheet* imgCheese = NULL;

	const int Rat = 1;
	const int Fire = 4;
	const int VerticalWall = 250;
	const int HorizontalWall = 250;
	const int Cheese = 496;

	//const int eShips = 30;
	//const int pShips = 1;
	//const int blocks = 3;
	//const int ufos = 1;
	//const int eBullets = 10;
	//const int pBullets = 5;

	//int pBulletCount;
	//bool shooting;

public:
	void Load() override;
	void UnLoad() override;
	void Render() override;
	void Update() override;
};