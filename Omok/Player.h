#pragma once

#include "Piece.h"
#include "Board.h"

class Player
{
private:
	int id;
	string name;
	Piece piece;
	Position pos = { 0, };

public:
	Player(const int& id, const string& name, const Piece& piece);
	~Player();
	Position MakeMove(Position pos);
	bool PlacePiece(Board* board);
	string GetName() const;
	Piece GetPiece() const;
};

