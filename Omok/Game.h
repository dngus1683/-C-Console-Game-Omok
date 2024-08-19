#pragma once

#include "DrawMap.h"
#include "Player.h"
#include "Board.h"

class Game
{
private:
	Setting m_Setting;
	DrawMap m_DrawMap;
	Player* player[2];
	Board* board;
	Position NowPosition = { WIDTH, HEIGHT /2};
public:
	Game(Setting& setting);
	~Game();

	int currentPlayer;
	void SwitchPlayer();
	Player* PlayGame();
};

