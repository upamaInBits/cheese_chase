#include <time.h>
#include <stdlib.h> 
#include "GameController.h"
#include "Level_Main.h"
#include "Level_GameOver.h"
#include "Object_Fire.h"

void Level_Main::Load() {

	//getting all the images
	imgVerticalWall = new SpriteSheet(L"verticalwall.png", gfx);
	imgHorizontalWall = new SpriteSheet(L"horizontalwall.png", gfx);
	imgRat = new SpriteSheet(L"rat.png", gfx, 20, 20);
	imgCheese = new SpriteSheet(L"cheese.png", gfx);
	imgFire = new SpriteSheet(L"fire.png", gfx, 20, 20);

	objectCount = VerticalWall + HorizontalWall + Cheese + Fire + Rat; //eShips + pShips + blocks + ufos + pBullets + eBullets;
	//new memory
	objectArray = new Object_Game * [objectCount];
	for (int Val = 0; Val < objectCount; Val++) {
		objectArray[Val] = NULL;
	}



	//creating  the Walls
	int xposition1 = 135, xposition2 = 135, xposition3 = 150, xposition4 = 150, xposition5 = 150, xposition6 = 150, xposition7 = 150, xposition8 = 150;
	int yposition1 = 20, yposition2 = 20, yposition3 = 20, yposition4 = 20, yposition5 = 20, yposition6 = 10;

	for (int y = 0; y < 30; y++)      //for the left walls 
	{
		if (y != 14 && y != 15 && y != 16)
		{
			Object_Block* next = new Object_Block(y, 150, yposition1, imgVerticalWall, objectArray);
			objectArray[y] = next;
		}

		yposition1 += 20;
	}

	for (int y = 30; y < 60; y++)     //for the right walls
	{
		if (y != 44 && y != 45 && y != 46)
		{
			Object_Block* next = new Object_Block(y, 850, yposition2, imgVerticalWall, objectArray);
			objectArray[y] = next;
		}

		yposition2 += 20;
	}

	for (int x = 60; x < 95; x++)      // for the top walls
	{
		Object_Block* next = new Object_Block(x, xposition1 += 20, 20, imgHorizontalWall, objectArray);
		objectArray[x] = next;
	}


	for (int x = 95; x < 130; x++)     //for the bottom walls
	{
		Object_Block* next = new Object_Block(x, xposition2 += 20, 610, imgHorizontalWall, objectArray);
		objectArray[x] = next;
	}


	for (int x = 130; x < 165; x++)    //the horizontal wall
	{
		if (!((x >= 130 && x <= 133)) && (!(x >= 139 && x <= 140)) && (!(x >= 145 && x <= 149)) && (!(x >= 155 && x <= 157)) && (!(x >= 163 && x <= 165)))
		{
			Object_Block* next = new Object_Block(x, xposition3, 100, imgHorizontalWall, objectArray);
			objectArray[x] = next;
		}

		xposition3 += 20;
	}

	for (int x = 165; x < 200; x++)    
	{
		if (!((x >= 165 && x <= 168)) && (!(x >= 174 && x <= 177))) //&& (!(x >= 145 && x <= 149)) && (!(x >= 155 && x <= 157)) && (!(x >= 163 && x <= 165)))
		{
			Object_Block* next = new Object_Block(x, xposition4, 180, imgHorizontalWall, objectArray);
			objectArray[x] = next;
		}

		xposition4 += 20;
	}


	for (int x = 200; x < 235; x++)   
	{
		if (!((x >= 205 && x <= 208)) && (!(x >= 215 && x <= 219)) && (!(x >= 232 && x <= 235)))// && (!(x >= 155 && x <= 157)) && (!(x >= 163 && x <= 165)))
		{
			Object_Block* next = new Object_Block(x, xposition5, 260, imgHorizontalWall, objectArray);
			objectArray[x] = next;
		}

		xposition5 += 20;
	}

	for (int x = 235; x < 270; x++)   
	{
		if (!((x >= 235 && x <= 239)) && (!(x >= 244 && x <= 247)) && (!(x >= 253 && x <= 255)) && (!(x >= 264 && x <= 267)))
		{
			Object_Block* next = new Object_Block(x, xposition6, 390, imgHorizontalWall, objectArray);
			objectArray[x] = next;
		}

		xposition6 += 20;
	}

	for (int x = 270; x < 305; x++)    
	{
		if (!((x >= 270 && x <= 273)) && (!(x >= 284 && x <= 286)) && (!(x >= 292 && x <= 295)) && (!(x >= 300 && x <= 302)))
		{
			Object_Block* next = new Object_Block(x, xposition7, 470, imgHorizontalWall, objectArray);
			objectArray[x] = next;
		}

		xposition7 += 20;
	}

	for (int x = 305; x < 340; x++)    
	{
		if (!((x >= 316 && x <= 318)) && (!(x >= 328 && x <= 333)))
		{
			Object_Block* next = new Object_Block(x, xposition8, 550, imgHorizontalWall, objectArray);
			objectArray[x] = next;
		}

		xposition8 += 20;
	}


	for (int y = 340; y < 370; y++)   //the vertical walls
	{
		if (!((y >= 340 && y <= 347)) && (!(y >= 352 && y <= 355)) && (!(y >= 363 && y <= 366)) && (!(y >= 368 && y <= 370)))
		{
			Object_Block* next = new Object_Block(y, 325, yposition3, imgVerticalWall, objectArray);
			objectArray[y] = next;
		}

		yposition3 += 20;
	}

	for (int y = 370; y < 400; y++)   
	{
		if (!((y >= 375 && y <= 377)) && (!(y >= 381 && y <= 384)) && (!(y >= 389 && y <= 392)) && (!(y >= 398 && y <= 400)))
		{
			Object_Block* next = new Object_Block(y, 495, yposition4, imgVerticalWall, objectArray);
			objectArray[y] = next;
		}

		yposition4 += 20;
	}




	for (int y = 400; y < 430; y++)   
	{
		if (!((y >= 400 && y <= 405)) && (!(y >= 408 && y <= 411)) && (!(y >= 423 && y <= 426)) && (!(y >= 428 && y <= 430)))
		{
			Object_Block* next = new Object_Block(y, 665, yposition5, imgVerticalWall, objectArray);
			objectArray[y] = next;
		}

		yposition5 += 20;
	}



	int dis1 = 190, dis2 = 190, dis3 = 190, dis4 = 190, dis5 = 190, dis6 = 190, dis7 = 190, dis8 = 190;
	int disforyposition1 = 40;

	for (int z = 430; z < 449; z++) 
	{
		if (z != 439)
		{
			Object_Block* next = new Object_Block(z, dis1, 60, imgCheese, objectArray);
			objectArray[z] = next;
		}

		dis1 += 35;
	}

	for (int z = 449; z < 468; z++) 
	{
		if (z != 462 && z != 463)
		{
			Object_Block* next = new Object_Block(z, dis2, 140, imgCheese, objectArray);
			objectArray[z] = next;
		}

		dis2 += 35;
	}


	for (int z = 468; z < 487; z++) 
	{
		if (z != 472 && z != 477)
		{
			Object_Block* next = new Object_Block(z, dis3, 220, imgCheese, objectArray);
			objectArray[z] = next;
		}

		dis3 += 35;
	}


	for (int z = 487; z < 506; z++) 
	{
		if (z != 491 && z != 496)
		{
			Object_Block* next = new Object_Block(z, dis4, 360, imgCheese, objectArray);
			objectArray[z] = next;
		}

		dis4 += 35;
	}


	for (int z = 506; z < 525; z++) 
	{
		if (z != 510)
		{
			Object_Block* next = new Object_Block(z, dis5, 430, imgCheese, objectArray);
			objectArray[z] = next;
		}

		dis5 += 35;
	}


	for (int z = 525; z < 544; z++) 
	{
		if (z != 534)
		{
			Object_Block* next = new Object_Block(z, dis6, 510, imgCheese, objectArray);
			objectArray[z] = next;
		}

		dis6 += 35;
	}


	for (int z = 544; z < 563; z++) 
	{
		if (z != 544 && z != 562)
		{
			Object_Block* next = new Object_Block(z, dis7, 590, imgCheese, objectArray);
			objectArray[z] = next;
		}

		dis7 += 35;
	}




	//top left corner position of the fire-

	int firexposition = 160, fireyposition = 35;

	Object_Fire* p2 = new Object_Fire(950, 0, 0, (VerticalWall + HorizontalWall), 0.0f, 0.0f, 160, 30, imgFire, objectArray, 40); //up left
	objectArray[VerticalWall + HorizontalWall + Cheese] = p2;

	Object_Fire* p3 = new Object_Fire(951, 8, 0, (VerticalWall + HorizontalWall), 0.0f, 0.0f, 830, 30, imgFire, objectArray, 40);
	objectArray[VerticalWall + HorizontalWall + Cheese + 1] = p3;

	Object_Fire* p4 = new Object_Fire(952, 16, 0, (VerticalWall + HorizontalWall), 0.0f, 0.0f, 160, 590, imgFire, objectArray, 40); //down left
	objectArray[VerticalWall + HorizontalWall + Cheese + 2] = p4;

	Object_Fire* p5 = new Object_Fire(953, 24, 0, (VerticalWall + HorizontalWall), 0.0f, 0.0f, 830, 590, imgFire, objectArray, 40);
	objectArray[VerticalWall + HorizontalWall + Cheese + 3] = p5;


	Object_Player* p1 = new Object_Player(1000, 0, (VerticalWall + HorizontalWall + Cheese + Fire), 0.0f, 0.0f, 490, 260, imgRat, objectArray, 16);
	objectArray[VerticalWall + HorizontalWall + Cheese + Fire] = p1;


	//objectArray[eShips + ufos + blocks] = p1;

	//pBulletCount = 0;
	//shooting = false;
	//just like from Pship example
}

void Level_Main::Render() {
	gfx->ClearScreen(0.0f, 0.0f, 0.0f);
	for (int goCurrent = 0; goCurrent < objectCount; goCurrent++) {
		if (objectArray[goCurrent]) objectArray[goCurrent]->Render();
	}
}

void Level_Main::UnLoad() {
	
	for (int curObj = 0; curObj < objectCount; curObj++) {
		if (objectArray[curObj]) delete objectArray[curObj];
	}
	delete[] objectArray;


	if (imgRat) delete imgRat;
	if (imgFire) delete imgFire;
	if (imgVerticalWall) delete imgVerticalWall;
	if (imgHorizontalWall) delete imgHorizontalWall;
}

void Level_Main::Update() {

	Object_Fire* p2 = (Object_Fire*)objectArray[VerticalWall + HorizontalWall + Cheese];
	Object_Fire* p3 = (Object_Fire*)objectArray[VerticalWall + HorizontalWall + Cheese + 1];
	Object_Fire* p4 = (Object_Fire*)objectArray[VerticalWall + HorizontalWall + Cheese + 2];
	Object_Fire* p5 = (Object_Fire*)objectArray[VerticalWall + HorizontalWall + Cheese + 3];

	Object_Player* p1 = (Object_Player*)objectArray[VerticalWall + HorizontalWall + Cheese + Fire];

	
	int ratvelocity = 2;
	int firevelocity = 2;


	if (p1 != NULL)
	{
		//WASD to move the pacman
		if (GetKeyState('A') & 0x8000) {
			p1->Setvelocity(-ratvelocity, 0);
			p1->changedirection(0, 1);
		}
		if (GetKeyState('D') & 0x8000) {
			p1->Setvelocity(ratvelocity, 0);
			p1->changedirection(2, 3);
		}

		if (GetKeyState('W') & 0x8000) {
			p1->Setvelocity(0, -ratvelocity);
			p1->changedirection(4, 5);
		}

		if (GetKeyState('S') & 0x8000) {
			p1->Setvelocity(0, ratvelocity);
			p1->changedirection(6, 7);
		}
	}

	int dir1 = rand() % 4;

	if (p2->ranintowall)
	{
		p2->ranintowall = false;

		if (dir1 == 0)
			p2->Setvelocity(firevelocity, 0);

		if (dir1 == 1)
			p2->Setvelocity(0, firevelocity);

		if (dir1 == 2)
			p2->Setvelocity(-firevelocity, 0);

		if (dir1 == 3)
			p2->Setvelocity(0, -firevelocity);
	}

	if (p3->ranintowall)
	{
		p3->ranintowall = false;

		if (dir1 == 0)
			p3->Setvelocity(firevelocity, 0);

		if (dir1 == 1)
			p3->Setvelocity(0, firevelocity);

		if (dir1 == 2)
			p3->Setvelocity(-firevelocity, 0);

		if (dir1 == 3)
			p3->Setvelocity(0, -firevelocity);
	}

	if (p4->ranintowall)
	{
		p4->ranintowall = false;

		if (dir1 == 0)
			p4->Setvelocity(firevelocity, 0);

		if (dir1 == 1)
			p4->Setvelocity(0, firevelocity);

		if (dir1 == 2)
			p4->Setvelocity(-firevelocity, 0);

		if (dir1 == 3)
			p4->Setvelocity(0, -firevelocity);
	}

	if (p5->ranintowall)
	{
		p5->ranintowall = false;

		if (dir1 == 0)
			p5->Setvelocity(firevelocity, 0);

		if (dir1 == 1)
			p5->Setvelocity(0, firevelocity);

		if (dir1 == 2)
			p5->Setvelocity(-firevelocity, 0);

		if (dir1 == 3)
			p5->Setvelocity(0, -firevelocity);
	}


	int count = 0;

	for (int x = 430; x < 565; x++)
	{
		if (objectArray[x] == NULL)
		{
			count += 1;
		}

		if (count == 135)
		{
			Object_Player* temp1 = dynamic_cast <Object_Player*>(objectArray[1000]);
			if (temp1)
			{
				score = temp1->getpoints();
			}
			GameController::SwitchLevel(new Level_GameOver(score, L"YOU WIN"));
		}
	}



	if (GetKeyState(VK_ESCAPE) & 0x8000)
		GameController::QuitGame();
}

