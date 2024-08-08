#include "Game.h"

void Game::PlayGame()
{
	while (true)
	{
		Piece piece(currnetPlayer);
	//	player[currnetPlayer].MakeMove();

	}
}

Game::Game()
{
	currnetPlayer = 0;
	m_DrawMap.GridDraw(0, 0, WIDTH, HEIGHT);
	Board* board = new Board;
	PlayGame();
}

Game::~Game()
{
}

void Game::SwitchPlayer()
{
}
