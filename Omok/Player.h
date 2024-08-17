#pragma once

#include "Piece.h"
#include "Board.h"
#include "DrawMap.h"

class Player
{
private:
	DrawMap m_DrawMap;
	const int id;
	Piece piece;
	Position pos = { 0, };

public:
	Player(const int& id, const Piece& piece);
	~Player();
	Position MakeMove(Position pos);
	bool PlacePiece(Board* board);
	Piece GetPiece() const;
	int GetId() const;
};