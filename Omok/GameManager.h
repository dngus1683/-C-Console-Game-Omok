#pragma once
#include "DrawMap.h"
#include "Game.h"

class GameManager
{
private:
	DrawMap m_DrawManager;
	Rect m_MapSize;
	Position m_CenterPosition;
	// �ܼ�â ũ�� ����
	void SetConsoleSize();
	int MainMenu();
	int WinningWindow(Player* p);
public:
	GameManager();
	~GameManager();

	void RunGame();

};

