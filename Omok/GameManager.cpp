#include "GameManager.h"

void GameManager::SetConsoleSize()
{
	char buf[256];
	int Width = (m_MapSize.right * 2) + 1;
	int Height = m_MapSize.bottom + 6;
	sprintf_s(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);
}

int GameManager::MainMenu()
{
	int iSelect;
	m_DrawManager.DrawMidText("* 오목 *", m_CenterPosition.x, m_CenterPosition.y*0.5f);
	m_DrawManager.DrawMidText("1. 게임 시작", m_CenterPosition.x, m_CenterPosition.y * 0.7f);
	m_DrawManager.DrawMidText("2. 옵션 설정", m_CenterPosition.x, m_CenterPosition.y * 0.9f);
	m_DrawManager.DrawMidText("3. 게임 종료", m_CenterPosition.x, m_CenterPosition.y * 1.1f);
	m_DrawManager.BoxDraw(m_CenterPosition.x * 0.5f, m_CenterPosition.y * 1.3f, 10, 3);
	gotoxy(m_CenterPosition.x, m_CenterPosition.y * 1.4f);
	cin >> iSelect;

	return iSelect;
}

int GameManager::WinningWindow(Player* p)
{
	int iSelect;
	char buf[256];
	sprintf_s(buf, "%d번 님이 우승하셨습니다!", p->GetId());
	m_DrawManager.DrawMidText("축하합니다!", m_CenterPosition.x, m_CenterPosition.y * 0.5f);
	m_DrawManager.DrawMidText(buf, m_CenterPosition.x, m_CenterPosition.y * 0.7f);
	m_DrawManager.DrawMidText("1. 메뉴", m_CenterPosition.x, m_CenterPosition.y * 0.9f);
	m_DrawManager.DrawMidText("2. 게임 종료", m_CenterPosition.x, m_CenterPosition.y * 1.1f);
	m_DrawManager.BoxDraw(m_CenterPosition.x * 0.5f, m_CenterPosition.y * 1.3f, 10, 3);
	gotoxy(m_CenterPosition.x, m_CenterPosition.y * 1.4f);
	cin >> iSelect;

	return iSelect;
}

GameManager::GameManager()
{
	m_MapSize.left = 0;
	m_MapSize.right = WIDTH;
	m_MapSize.top = 0;
	m_MapSize.bottom = HEIGHT;

	m_CenterPosition.x = m_MapSize.right; // 해당 프로젝트에서는 특수문자가 2칸을 차지하는 레거시 콘솔을 사용하며, 격자는 특수문자로 이루어져 있다. 때문에, 바둑판의 너비는 실제보다 2배 넓으며, 이로인해 맵 상의 중앙 위치는 너비와 같다고 볼 수 있다.
	m_CenterPosition.y = m_MapSize.bottom * 0.5f;	// 곱하기 연산이 나누기 연산보다 빠르다.

	SetConsoleSize();

}

GameManager::~GameManager()
{
}

void GameManager::RunGame()
{
	int menu = 0;
	m_DrawManager.GridDraw(0, 0, m_MapSize.right, m_MapSize.bottom);
	menu = MainMenu();

	if (menu == 1)
	{
		Game* OneGame = new Game;
		Player* winner = OneGame->PlayGame();
		m_DrawManager.GridDraw(0, 0, m_MapSize.right, m_MapSize.bottom);
		switch (WinningWindow(winner))
		{
		case 2:
			gotoxy(0, HEIGHT);
			exit(0);
		case 1:
		default:
			delete OneGame;
			return;
		}


	}
	else if (menu == 2)
	{

	}
	else if (menu == 3)
	{
		system("cls");
		exit(0);
	}
}
