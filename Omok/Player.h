#pragma once

#include "Piece.h"
#include "Board.h"

class Player
{
private:
	int id;
	string name;
	Piece piece;
	Position pos = { WIDTH, HEIGHT };

public:
	Player(const int& id, const string& name, const Piece& piece);
	~Player();
	Position MakeMove(Board &board);
	void PlacePiece();
	string GetName() const;
	Piece GetPiece() const;
};

