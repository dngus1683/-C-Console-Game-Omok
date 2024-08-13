#pragma once

#include "Piece.h"

class Board
{
private:
	short board[19][19] = { 0, };
public:
	Board();
	~Board();

	void PlacePiece(int& id, Position& pos);
	bool IsFull(Position& pos);
	void IsWinningMove(int x, int y);
};

