#pragma once

#include "DrawMap.h"
#include "Player.h"
#include "Board.h"

class Game
{
private:
	DrawMap m_DrawMap;
	//Player player[2];
	Board board;
	void PlayGame();
public:
	Game();
	~Game();

	int currnetPlayer;
	void SwitchPlayer();

};

