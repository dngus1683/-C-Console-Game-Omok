#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::DrawBoard()
{
}

void Board::PlacePiece()
{
}

void Board::IsFull()
{
}

void Board::IsWinningMove(int x, int y)
{
	// bool visited[19][19] = { 0, };

}

/*
static bool dfs(bool visited[19][19], Piece board[19][19], int x, int y, int direction, int cnt)
{
	visited[y][x] = true;
	cnt++;

	if (cnt == 5)
	{
		return true;
	}

	bool sign = true;

	for (int i = 0; i < 2; i++)
	{
		int NextX = x + (sign ? dx[direction] : -dx[direction]);
		int NextY = y + (sign ? dy[direction] : -dy[direction]);
		if (NextX >= 0 && NextY >= 0 && NextX < 19 && NextY < 19)
		{
			if (!visited[NextY][NextX] && (*board[NextY][NextX].GetSymbol() == *board[NextY][NextX].GetSymbol()))
			{
				dfs(visited, board, NextX, NextY, direction, cnt);
			}
		}


		sign = !sign;
	}

}
*/
