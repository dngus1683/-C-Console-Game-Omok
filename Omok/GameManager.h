#pragma once
#include "DrawMap.h"
#include "Game.h"

class GameManager
{
private:
	DrawMap m_DrawManager;
	Rect m_MapSize;
	Position m_CenterPosition;
	// 콘솔창 크기 조절
	void SetConsoleSize();
	int MainMenu();
	int WinningWindow(Player* p);
public:
	GameManager();
	~GameManager();

	void RunGame();

};

