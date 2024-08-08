#include "Player.h"

Player::Player(const int& id, const string& name, const Piece& piece) : id(id), name(name), piece(piece)
{
}

Player::~Player()
{
}

void Player::MakeMove(Board& board)
{
	int x, y;

	while (true)
	{
		char input;

		input = _getch();

		switch (input)
		{
		case 'w':
			break;
		case 's':
			break;
		case 'a':
			break;
		case 'd':
			break;
		case ' ':
			break;
		default:
			break;
		}
	}
}

string Player::GetName() const 
{
	return name;
}

Piece Player::GetPiece() const 
{
	return piece;
}
