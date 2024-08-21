#include "Game.h"

Player* Game::PlayGame()
{
	while (true)
	{
		NowPosition = player[currentPlayer]->MakeMove(NowPosition);
		if ((!m_Setting.Permit6) && board->IsMoreThanSixMove(player[currentPlayer]->GetId(), NowPosition)) continue;
		if ((!m_Setting.Permit3x3) && board->IsDoubleMove(player[currentPlayer]->GetId(), NowPosition, 3)) continue;
		if ((!m_Setting.Permit4x4) && board->IsDoubleMove(player[currentPlayer]->GetId(), NowPosition, 4)) continue;
		if (!player[currentPlayer]->PlacePiece(board)) continue;
		if (board->IsWinningMove(player[currentPlayer]->GetId(), NowPosition, m_Setting.PermitWinOverFive)) break;
		SwitchPlayer();
	}
	return player[currentPlayer];
}

Game::Game(Setting& setting)
{
	this->m_Setting = setting;
	currentPlayer = 0;
	m_DrawMap.GridDraw(0, 0, WIDTH, HEIGHT);
	board = new Board;
	Piece piece1(0);
	Piece piece2(1);
	Player* player1 = new Player(1, piece1);
	Player* player2 = new Player(2, piece2);
	player[0] = player1;
	player[1] = player2;
}

Game::~Game()
{
	delete player[0];
	delete player[1];
	delete board;
}

void Game::SwitchPlayer()
{
	currentPlayer = (currentPlayer == 1 ? 0 : 1);
}
