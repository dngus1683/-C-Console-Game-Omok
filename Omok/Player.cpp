#include "Player.h"

Player::Player(const int& id, const Piece& piece) : id(id), piece(piece)
{
}

Player::~Player()
{
}

Position Player::MakeMove(Position pos)
{
	char buf[256];
	char input = 'a';

	sprintf_s(buf, "=========== % d¹ø % s Â÷·Ê ===========", id, piece.GetSymbol());
	m_DrawMap.BoxDraw(0, HEIGHT, WIDTH, HEIGHT*0.25f);
	m_DrawMap.DrawMidText(buf, WIDTH, HEIGHT*1.1f);
	
	gotoxy(pos);
	while (input != ' ')
	{
		input = _getch();

		switch (input)
		{
		case 'w':
			if (pos.y > 1) pos.y -= 1;
			break;
		case 's':
			if (pos.y < (HEIGHT - 2)) pos.y += 1;
			break;
		case 'a':
			if (pos.x > 2) pos.x -= 2;
			break;
		case 'd':
			if (pos.x < (WIDTH*2 - 4)) pos.x += 2;
			break;
		default:
			break;
		}
		gotoxy(pos);
	}
	this->pos = pos;
	return pos;
}

bool Player::PlacePiece(Board* board)
{
	if (board->IsFull(pos)) return false;
	else
	{
		board->PlacePiece(id, pos);
		cout << piece.GetSymbol();
	}
	return true;
}

Piece Player::GetPiece() const 
{
	return piece;
}

int Player::GetId() const
{
	return id;
}
