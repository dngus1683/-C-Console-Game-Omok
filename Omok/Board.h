#pragma once

#include "Piece.h"

class Board
{
private:
	short board[19][19] = { 0, };
public:
	Board();
	~Board();

	void PlacePiece(const int& id, Position& pos);
	bool IsFull(Position& pos);
	bool IsWinningMove(const int& id, Position& pos, const bool PermitSix);
	bool IsMoreThanSixMove(const int& id, Position& pos, const int MaximunNumber = 6);
	bool IsDoubleMove(const int& id, Position& pos,  const int MaximunNumber);
};