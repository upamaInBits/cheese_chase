#pragma once
#include "Level_Game.h"
#include <string>

enum winner { Red, Yellow, Tie };

class GameController {
private:
	GameController() {}; //Can't create one
	static Level_Game* currentLevel;
public:
	static wchar_t address[64];
	static bool Loading;
	static winner GameWinner;

	static bool contactRed;
	static bool contactYellow;

	static void Init();
	static void LoadInitialLevel(Level_Game* lev);
	static void SwitchLevel(Level_Game* lev);
	static void Render();
	static void Update();
	static void QuitGame();
};
