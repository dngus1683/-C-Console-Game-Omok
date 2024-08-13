#include "DrawMap.h"

DrawMap::DrawMap()
{
}

void DrawMap::GridDraw(int Start_x, int Start_y, int Width, int Height)
{
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y+y);
		if (y == 0)
		{
			cout << "¦£";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦¨";
			cout << "¦¤";
		}
		else if (y == Height - 1)
		{
			cout << "¦¦";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦ª";
			cout << "¦¥";
		}
		else
		{
			cout << "¦§";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦«";
			cout << "¦©";
		}
	}
	gotoxy(Width, Height/2);
	return; 
}

void DrawMap::BoxDraw(int Start_x, int Start_y, int Width, int Height)
{
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		if (y == 0)
		{
			cout << "¦£";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦¡";
			cout << "¦¤";
		}
		else if (y == Height - 1)
		{
			cout << "¦¦";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦¡";
			cout << "¦¥";
		}
		else
		{
			cout << "¦¢";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "¦¢";
		}
	}
	return;
}

void DrawMap::DrawPoint(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void DrawMap::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2) x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

void DrawMap::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
	return;
}

void DrawMap::ErasePoint(int x, int y)
{
	gotoxy(x, y);
	cout << " ";
	gotoxy(-1, -1);
	return;
}

DrawMap::~DrawMap()
{
}
