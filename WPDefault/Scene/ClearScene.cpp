#include "Framework.h"
#include "ClearScene.h"


ClearScene::ClearScene()
{
	GameManager::GetInstance()->m_SoundManager.Playsound(SoundTrack::stage_clear);

	GameManager::GetInstance()->m_UIManager.CreateGameOver();
	m_Num = 0;
	// 클리어 배경
	BackGround = new Bitmap(IDB_BITMAP6);
	m_Cursor = new Bitmap(IDB_Cursor);
	// 로고
	GameOverBmp = new Bitmap(CLEARBMP);
	GameOverBmp->position[0] = 240;
	GameOverBmp->position[1] = 50;

	m_Cursor->position[0] = 230;
	m_Cursor->position[1] = 340;
	// UI 추가. => 함수로 만들어줘도 될듯
}

ClearScene::~ClearScene()
{
	delete BackGround;
	delete m_Cursor;
	delete GameOverBmp;
}

void ClearScene::Update()
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
			// 첫 씬으로 복귀
			Program::ChangeScene(new IntroScene());
			//scene 변경 추가할 곳.
		}
		else
		{
			//scene 변경 추가할 곳. => 프로그램 종료
			SendMessage(Renderer::Get()->GetHWnd(), WM_DESTROY, 0, 0);
		}
		GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::Coin);
		return;
	}
	BackGround->Update();
	GameOverBmp->Update();
	m_Cursor->Update();
	// 게임씬 한정 Update와 Render라서 게임오버씬 한정 Update와 render를 만듦
	GameManager::GetInstance()->m_UIManager.GameoverUpdate();
}

void ClearScene::Render()
{
	BackGround->Render();
	GameOverBmp->Render();
	m_Cursor->Render();
	GameManager::GetInstance()->m_UIManager.GameoverRender();
}
