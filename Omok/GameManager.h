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
	void WinningWindow(int id);
public:
	GameManager();
	~GameManager();

	void RunGame();

};

