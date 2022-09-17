#include "Framework.h"
#include "GameoverScene.h"

GameoverScene::GameoverScene()
{
	GameManager::GetInstance()->m_SoundManager.Playsound(SoundTrack::gameover);

	GameManager::GetInstance()->m_UIManager.CreateGameOver();
	m_Num = 0;
	BackGround = new Bitmap(GAMEOVERBGBMP);
	m_Cursor = new Bitmap(IDB_Cursor);
	GameOverBmp = new Bitmap(GAMEOVERBMP);
	GameOverBmp->position[0] = 240;
	GameOverBmp->position[1] = 50;

	m_Cursor->position[0] = 230;
	m_Cursor->position[1] = 340;
	// UI �߰�. => �Լ��� ������൵ �ɵ�
}

GameoverScene::~GameoverScene()
{
	delete BackGround;
	delete m_Cursor;
	delete GameOverBmp;
}

void GameoverScene::Update()
{
	Renderer::Get()->GetCamera()->Update();
	if (KEYBOARD->Down(VK_UP))
	{
		m_Num = 0;
		m_Cursor->position[1] = 340;
		GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::Coin);
	}
	if (KEYBOARD->Down(VK_DOWN))
	{
		m_Num = 1;
		m_Cursor->position[1] = 390;
		GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::Coin);
	}
	if (KEYBOARD->Down(VK_RETURN))
	{
		if (m_Num == 0)
		{
			GameManager::GetInstance()->m_UIManager.ReStart();
			// ù ������ ����
			Program::ChangeScene(new IntroScene());
			//scene ���� �߰��� ��.
		}
		else
		{
			//scene ���� �߰��� ��. => ���α׷� ����
			SendMessage(Renderer::Get()->GetHWnd(), WM_DESTROY, 0, 0);
		}
		GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::Coin);
		return;
	}
	BackGround->Update();
	GameOverBmp->Update();
	m_Cursor->Update();
	// ���Ӿ� ���� Update�� Render�� ���ӿ����� ���� Update�� render�� ����
	GameManager::GetInstance()->m_UIManager.GameoverUpdate();
}

void GameoverScene::Render()
{
	BackGround->Render();
	GameOverBmp->Render();
	m_Cursor->Render();
	GameManager::GetInstance()->m_UIManager.GameoverRender();
}
