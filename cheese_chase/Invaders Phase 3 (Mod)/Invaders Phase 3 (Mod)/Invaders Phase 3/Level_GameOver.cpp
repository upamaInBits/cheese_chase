#include <cstring>
#include <wchar.h>
#include <iostream>
#include "GameController.h"
#include "Level_GameOver.h"
#include "Level_Loading.h"


Level_GameOver::Level_GameOver(int score, const wchar_t msg[]) {
	this->score = score;
	wcscpy_s(message, msg);
}

void Level_GameOver::Load() {
	txtGameOverMsg = new Object_Text(gfx, D2D1::RectF(SCREENWIDTH / 2 - 250, SCREENHEIGHT / 2 - 25, SCREENWIDTH / 2 + 250, SCREENHEIGHT / 2 + 25), message, L"Veranda", 50.0f, D2D1::ColorF::White, 1.0f);
	txtScoreMsg = new Object_Text(gfx, D2D1::RectF(SCREENWIDTH / 2 - 250, SCREENHEIGHT / 2 + 25, SCREENWIDTH / 2 + 250, SCREENHEIGHT / 2 + 75), L"", L"Veranda", 50.0f, D2D1::ColorF::Red, 1.0f);
	txtNewGameMsg = new Object_Text(gfx, D2D1::RectF(SCREENWIDTH / 2 - 250, SCREENHEIGHT / 2 + 65, SCREENWIDTH / 2 + 250, SCREENHEIGHT / 2 + 115), L"New Game? Y/N", L"Veranda", 20.0f, D2D1::ColorF::Yellow, 1.0f);

}

void Level_GameOver::Render() {
	gfx->ClearScreen(0.0f, 0.0f, 0.0f);

	wchar_t gameMsg[50];
	swprintf_s(gameMsg, L"Score: %d", score);


	txtGameOverMsg->RenderText();
	txtScoreMsg->RenderText(gameMsg);
	txtNewGameMsg->RenderText();
}

void Level_GameOver::UnLoad() {

	if (txtGameOverMsg) delete txtGameOverMsg;
	//if (txtScoreMsg) delete txtScoreMsg;
	if (txtNewGameMsg) delete txtNewGameMsg;
}

void Level_GameOver::Update() {

	if (GetKeyState('Y') & 0x8000)
		GameController::SwitchLevel(new Level_Loading(0));
	else if (GetKeyState('N') & 0x8000)
		GameController::QuitGame();
}