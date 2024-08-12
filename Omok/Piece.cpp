#include "Piece.h"


Piece::Piece(int num)
{
	if (num == 0)
	{
		SetSymbol("○");
	}
	else if (num == 1)
	{
		SetSymbol("●");
	}
}

Piece::~Piece()
{
}

char* Piece::GetSymbol()
{
	return symbol;
}

void Piece::SetSymbol(const char c[4])
{
	strcpy_s(symbol, c);
}
