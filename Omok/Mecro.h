#pragma once

// 해당 헤더 파일은, 모든 클래스 파일에서 공용으로 사용되는 라이브러리를 선언해주는 역할을 한다.
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

// 콘솔창의 커서를 원하는 위치로 옮겨주는 함수.
inline void gotoxy(Position& p)
{
	COORD Pos = { p.x, p.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}
inline void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
