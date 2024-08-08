#pragma once

#include "Mecro.h"

class Piece
{
private:
	char symbol[4] = "";
public:
	Piece(int num = 0);
	~Piece();
	char* GetSymbol();
	void SetSymbol(const char c[4]);
};

