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
	m_DrawManager.DrawMidText("* ���� *", m_CenterPosition.x, m_CenterPosition.y*0.5f);
	m_DrawManager.DrawMidText("1. ���� ����", m_CenterPosition.x, m_CenterPosition.y * 0.7f);
	m_DrawManager.DrawMidText("2. �ɼ� ����", m_CenterPosition.x, m_CenterPosition.y * 0.9f);
	m_DrawManager.DrawMidText("3. ���� ����", m_CenterPosition.x, m_CenterPosition.y * 1.1f);
	m_DrawManager.BoxDraw(m_CenterPosition.x * 0.5f, m_CenterPosition.y * 1.3f, 10, 3);
	gotoxy(m_CenterPosition.x, m_CenterPosition.y * 1.4f);
	cin >> iSelect;

	return iSelect;
}

int GameManager::WinningWindow(Player* p)
{
	int iSelect;
	char buf[256];
	sprintf_s(buf, "%d�� ���� ����ϼ̽��ϴ�!", p->GetId());
	m_DrawManager.DrawMidText("�����մϴ�!", m_CenterPosition.x, m_CenterPosition.y * 0.5f);
	m_DrawManager.DrawMidText(buf, m_CenterPosition.x, m_CenterPosition.y * 0.7f);
	m_DrawManager.DrawMidText("1. �޴�", m_CenterPosition.x, m_CenterPosition.y * 0.9f);
	m_DrawManager.DrawMidText("2. ���� ����", m_CenterPosition.x, m_CenterPosition.y * 1.1f);
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

	m_CenterPosition.x = m_MapSize.right; // �ش� ������Ʈ������ Ư�����ڰ� 2ĭ�� �����ϴ� ���Ž� �ܼ��� ����ϸ�, ���ڴ� Ư�����ڷ� �̷���� �ִ�. ������, �ٵ����� �ʺ�� �������� 2�� ������, �̷����� �� ���� �߾� ��ġ�� �ʺ�� ���ٰ� �� �� �ִ�.
	m_CenterPosition.y = m_MapSize.bottom * 0.5f;	// ���ϱ� ������ ������ ���꺸�� ������.

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
