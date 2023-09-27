#include "GameController.h"
#include "Level_Loading.h"
#include "Level_Main.h"

Level_Loading::Level_Loading(int score) {
	this->score = score;
}

void Level_Loading::Load() {

	txtGameMsg = new Object_Text(gfx, D2D1::RectF(SCREENWIDTH / 2 - 250, SCREENHEIGHT / 2 - 25, SCREENWIDTH / 2 + 250, SCREENHEIGHT / 2 + 25), L"Game will begin in", L"Veranda", 50.0f, D2D1::ColorF::White, 1.0f);
	txtStartingMsg = new Object_Text(gfx, D2D1::RectF(SCREENWIDTH / 2 - 250, SCREENHEIGHT / 2 + 25, SCREENWIDTH / 2 + 250, SCREENHEIGHT / 2 + 75), L"", L"Veranda", 50.0f, D2D1::ColorF::Yellow, 1.0f);
	loadTime = clock();
}

void Level_Loading::Render() {
	gfx->ClearScreen(0.0f, 0.0f, 0.0f);

	txtGameMsg->RenderText();

	clock_t sinceLoadTime = (clock() - loadTime) / CLOCKS_PER_SEC;

	wchar_t startingMsg[20];
	swprintf_s(startingMsg, L"%d", 5 - sinceLoadTime);
	txtStartingMsg->RenderText(startingMsg);

	if (sinceLoadTime >= 5) {
		GameController::SwitchLevel(new Level_Main());
	}
}

void Level_Loading::UnLoad() {

	if (txtGameMsg) delete txtGameMsg;
}

void Level_Loading::Update() {

}
