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
	if (board[pos.y][pos.x / 2] != 0) return true;
	else return false;
}


int cnt = 0;
int deltaX[4] = { 1, 0, 1, 1 };
int deltaY[4] = { 0, 1, 1, -1 };

static bool IsMoreThanFive(bool visited[19][19], short board[19][19], short id, int x, int y, int direction)
{
	visited[y][x] = true;
	cnt++;

	if (cnt > 5)
	{
		return true;
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
				if (IsMoreThanFive(visited, board, id, NextX, NextY, direction))
				{
					return true;
				}
			}
		}
		sign = !sign;
	}

	return false;
}

bool Board::IsWinningMove(const int& id, Position& pos, const bool PermitOver6)
{
	for (int i = 0; i < 4; i++)
	{
		bool visited[19][19] = { 0, };
		cnt = 0;
		IsMoreThanFive(visited, board, id, pos.x / 2, pos.y, i);

		if (PermitOver6 && cnt >= 5) return true;
		else if (!PermitOver6 && cnt == 5) return true;
	}
	return false;
}

bool Board::IsMoreThanSixMove(const int& id, Position& pos)
{
	for (int i = 0; i < 4; i++)
	{
		bool visited[19][19] = { 0, };
		cnt = 0;
		if (IsMoreThanFive(visited, board, id, pos.x / 2, pos.y, i))
		{
			return true;
		}
	}
	return false;
}

bool bBlankVisit = false;

static Position FindStartPoint(const short board[19][19], const short& id, Position p, const int& direction, const bool& sign)
{
	Position StartPoint;

	int x = p.x / 2;
	int y = p.y;
	int PrePiece = 0;

	for (int i = 0; i < 5; i++)
	{
		if (board[y][x] == id || i == 0)
		{
			StartPoint = { x,y };
		}
		else if (board[y][x] == 0 && i != 0)
		{
			bBlankVisit = true;
		}

		PrePiece = board[y][x];
		x = x + (sign ? deltaX[direction] : -deltaX[direction]);
		y = y + (sign ? deltaY[direction] : -deltaY[direction]);

		if ((board[y][x] != id && board[y][x] != 0))
		{
			break;
		}
		else if ((board[y][x] == 0 && bBlankVisit))
		{
			if (PrePiece == 0)
			{
				bBlankVisit = false;
			}
			break;
		}
	}
	return StartPoint;
}
static bool CanMakeFive(const short board[19][19], const short& id, Position p, const int& direction, const bool& sign)
{
	int x = p.x;
	int y = p.y;

	for (int i = 0; i < 5; i++)
	{
		if (board[y][x] == id)
		{
			cnt++;
		}
		else if (board[y][x] != 0)
		{
			return false;
		}

		x = x + (sign ? deltaX[direction] : -deltaX[direction]);
		y = y + (sign ? deltaY[direction] : -deltaY[direction]);
	}
	return true;
}

bool Board::IsDoubleMove(const int& id, Position& pos, const int MaximunNumber)
{
	int DoubleCount = 0;
	for (int direction = 0; direction < 4; direction++)
	{
		cnt = 0;
		bBlankVisit = false;
		Position PFirst = FindStartPoint(board, id, pos, direction, true);
		bool bFirst = CanMakeFive(board, id, PFirst, direction, false);

		cnt = 0;
		Position PSecond = FindStartPoint(board, id, pos, direction, false);
		bool bSecond = CanMakeFive(board, id, PSecond, direction, true);

		int check = cnt;
		if (bFirst && bSecond && cnt == MaximunNumber-1)
		{
			DoubleCount++;
		}
	}
	if (DoubleCount >= 2) return true;
	else return false;
}

