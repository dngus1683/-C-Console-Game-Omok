#include "Player.h"

Player::Player(const int& id, const string& name, const Piece& piece) : id(id), name(name), piece(piece)
{
}

Player::~Player()
{
}

Position Player::MakeMove(Board& board, Position pos)
{
	char input = 'a';
	while (input != ' ')
	{
		input = _getch();

		switch (input)
		{
		case 'w':
			if (pos.y > 0) pos.y -= 1;
			break;
		case 's':
			if (pos.y < 39) pos.y += 1;
			break;
		case 'a':
			if (pos.x > 0) pos.x -= 2;
			break;
		case 'd':
			if (pos.x < 39) pos.x += 2;
			break;
		default:
			break;
		}
		gotoxy(pos);
	}
	return pos;
}

void Player::PlacePiece()
{
	cout << piece.GetSymbol();
}

string Player::GetName() const 
{
	return name;
}

Piece Player::GetPiece() const 
{
	return piece;
}
