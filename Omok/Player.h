#pragma once

#include "Piece.h"
#include "Board.h"

class Player
{
private:
	int id;
	string name;
	Piece piece;

public:
	Player(const int& id, const string& name, const Piece& piece);
	~Player();
	Position MakeMove(Board &board, Position pos);
	void PlacePiece();
	string GetName() const;
	Piece GetPiece() const;
};

