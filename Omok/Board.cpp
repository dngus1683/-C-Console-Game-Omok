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

static bool dfs(bool visited[19][19], short board[19][19], short id, int x, int y, int direction)
{
	bool answer = false;
	visited[y][x] = true;
	cnt++;

	if (cnt == 5)
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
				if (dfs(visited, board, id, NextX, NextY, direction))
				{
					return true;
				}
			}
		}
		sign = !sign;
	}
	return false;
}

bool Board::IsWinningMove(const int& id, Position& pos)
{
	for (int i = 0; i < 4; i++)
	{
		bool visited[19][19] = { 0, };
		cnt = 0;
		if (dfs(visited, board, id, pos.x / 2, pos.y, i))
		{
			return true;
		}
	}
	return false;
}
