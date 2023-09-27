#pragma once

#include "Level_Game.h"

class Level_GameOver : public Level_Game {
private:
	Object_Text* txtGameOverMsg;
	Object_Text* txtScoreMsg;
	Object_Text* txtNewGameMsg;


	int score;
	wchar_t message[50];


public:
	Level_GameOver(int score, const wchar_t msg[]);
	void Load() override;
	void UnLoad() override;
	void Render() override;
	void Update() override;
};
