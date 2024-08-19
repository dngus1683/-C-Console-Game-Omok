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
	// �ܼ�â ũ�� ����
	void SetConsoleSize();
	int MainMenu();
	int WinningScreen(Player* p);
	void SettingScreen();
public:
	GameManager();
	~GameManager();

	void RunGame();

};

