#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::PlacePiece(const int& id, Position& pos)
{
	board[pos.y][pos.x / 2] = id;
}

bool Board::IsFull(Position& pos)
{
	if (board[pos.y][pos.x/2] != 0) return true;
	else return false;
}


int cnt = 0;
int deltaX[4] = { 1, 0, 1, 1 };
int deltaY[4] = { 0, 1, 1, -1 };

static bool IsMoreThanFive(bool visited[19][19], short board[19][19], short id, int x, int y, int direction, const bool PermitSix)
{
	visited[y][x] = true;
	cnt++;

	if (cnt == 6 )
	{
		if (PermitSix)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	bool sign = true;

	for (int i = 0; i < 2; i++)
	{
		int NextX = x + (sign ? deltaX[direction] : -deltaX[direction]);
		int NextY = y + (sign ? deltaY[direction] : -deltaY[direction]);
		if (NextX >= 0 && NextY >= 0 && NextX < 19 && NextY < 19)
		{
			if (!visited[NextY][NextX] && (board[NextY][NextX] == id))
			{
				if (IsMoreThanFive(visited, board, id, NextX, NextY, direction, PermitSix))
				{
					return true;
				}
			}
		}
		sign = !sign;
	}

	if (cnt == 5)
	{
		return true;
	}
	return false;
}

bool Board::IsWinningMove(const int& id, Position& pos, const bool PermitSix)
{
	for (int i = 0; i < 4; i++)
	{
		bool visited[19][19] = { 0, };
		cnt = 0;
		if (IsMoreThanFive(visited, board, id, pos.x / 2, pos.y, i, PermitSix))
		{
			return true;
		}
	}
	return false;
}
