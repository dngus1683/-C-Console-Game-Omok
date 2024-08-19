#pragma once
#include "DrawMap.h"
#include "Game.h"

class GameManager
{
private:
	Setting m_Setting;

	DrawMap m_DrawManager;
	Rect m_MapSize;
	Position m_CenterPosition;
	// 콘솔창 크기 조절
	void SetConsoleSize();
	int MainMenu();
	int WinningScreen(Player* p);
	void SettingScreen();
public:
	GameManager();
	~GameManager();

	void RunGame();

};

