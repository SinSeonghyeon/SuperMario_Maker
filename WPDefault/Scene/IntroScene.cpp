#include "Framework.h"
#include "IntroScene.h"
IntroScene::IntroScene()
{
	m_Num = 0;
	GameManager::GetInstance()->m_SoundManager.StopMusic();
	GameManager::GetInstance()->m_SoundManager.Playsound(SoundTrack::BGM);
	GameManager::GetInstance()->m_UIManager.CreateInGame();
	BackGround = new Bitmap(IDB_BITMAP4);
	m_Cursor = new Bitmap(IDB_Cursor);
	LOGO = new Bitmap(IDB_LOGO);
	LOGO->position[0] = 240;
	LOGO->position[1] = 70;

	m_Cursor->position[0] = 230;
	m_Cursor->position[1] = 340;
}
IntroScene::~IntroScene()
{
	delete BackGround;
	delete m_Cursor;
	delete LOGO;
	
}

	// Scene을(를) 통해 상속됨
void IntroScene::Update()
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
			GameManager::GetInstance()->m_UIManager.Start();
			Program::ChangeScene(new TestScene());
			//scene 변경 추가할 곳.
		}
		else
		{
			// 나가기
			SendMessage(Renderer::Get()->GetHWnd(), WM_DESTROY, 0, 0);
		}
		GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::Coin);
		return;
	}
		BackGround->Update();
		LOGO->Update();
		m_Cursor->Update();
		GameManager::GetInstance()->m_UIManager.Update();

}

void IntroScene::Render()
{
	
	BackGround->Render();
	LOGO->Render();
	m_Cursor->Render();
	GameManager::GetInstance()->m_UIManager.Render();
}

