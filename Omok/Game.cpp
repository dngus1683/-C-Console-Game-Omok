#include "Game.h"

void Game::PlayGame()
{
	while (true)
	{
		NowPosition = player[currnetPlayer]->MakeMove(board, NowPosition);
		player[currnetPlayer]->PlacePiece();
		SwitchPlayer();
	}
}

Game::Game()
{
	currnetPlayer = 0;
	m_DrawMap.GridDraw(0, 0, WIDTH, HEIGHT);
	Board* board = new Board;
	Piece piece1(0);
	Piece piece2(1);
	Player* player1 = new Player(0, "a", piece1);
	Player* player2 = new Player(1, "b", piece2);
	player[0] = player1;
	player[1] = player2;

	PlayGame();
}

Game::~Game()
{
}

void Game::SwitchPlayer()
{
	currnetPlayer = (currnetPlayer == 1 ? 0 : 1);
}
