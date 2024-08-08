#pragma once

// �ش� ��� ������, ��� Ŭ���� ���Ͽ��� �������� ���Ǵ� ���̺귯���� �������ִ� ������ �Ѵ�.
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

#define WIDTH 20
#define HEIGHT 20

using namespace std;

struct Rect
{
	int left;
	int right;
	int top;
	int bottom;
};

struct Position
{
	int x;
	int y;
};

// �ܼ�â�� Ŀ���� ���ϴ� ��ġ�� �Ű��ִ� �Լ�.
inline void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

/*
int dx[4] = { 1, 0, 1, 1 };
int dy[4] = { 0, 1, 1, -1 };
*/