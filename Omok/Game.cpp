#include "Game.h"

void Game::PlayGame()
{
	while (true)
	{
		NowPosition = player[currnetPlayer]->MakeMove(NowPosition);
		if (!player[currnetPlayer]->PlacePiece(board)) continue;
		if (board->IsWinningMove(player[currnetPlayer]->GetId(), NowPosition)) break;
		SwitchPlayer();
	}
	gotoxy(0, 1000);
	cout << player[currnetPlayer]->GetId() << "´ÔÀÌ ½Â¸®ÇÏ¼Ì½À´Ï´Ù!\n";
}

Game::Game()
{
	currnetPlayer = 0;
	m_DrawMap.GridDraw(0, 0, WIDTH, HEIGHT);
	board = new Board;
	Piece piece1(0);
	Piece piece2(1);
	Player* player1 = new Player(1, "a", piece1);
	Player* player2 = new Player(2, "b", piece2);
	player[0] = player1;
	player[1] = player2;
}

Game::~Game()
{
}

void Game::SwitchPlayer()
{
	currnetPlayer = (currnetPlayer == 1 ? 0 : 1);
}
