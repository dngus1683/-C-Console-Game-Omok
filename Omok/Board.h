#pragma once

#include "Piece.h"

class Board
{
private:
	Piece board[19][19];
public:
	Board();
	~Board();

	void DrawBoard();
	void PlacePiece();
	void IsFull();
	void IsWinningMove(int x, int y);
};

