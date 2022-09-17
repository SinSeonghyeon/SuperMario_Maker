#include "Framework.h"
// 타일 비트맵 변경을 위한 파일경로 변수
extern char* g_tileStr;
extern int g_tileMode;

void Button::OnClickDown()
{
	//버튼입력
	GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::Stomp);

	isClick = true;
}
void Button::OnClickUp()
{
	//버튼입력
	isClick = false;
}



UIManager::UIManager()
{

}
UIManager::~UIManager()
{
	for (int i = 0; i < 10; i++)
	{
		delete m_UIList[i];
	}
}
void UIManager::CreateInGame()
{
	CreateUI(11, 7, "MARIO");
	CreateUI(9, 32, "000000");//Score 1
	CreateUI(250, 32, "x 00"); //코인 2
	CreateUI(450, 7, "WORLD");
	CreateUI(450, 32, "1 - 1"); //Stage 4
	CreateUI(800, 7, "TIME");
	CreateUI(800, 32, " "); //타임 6
	CreateUI(280, 340, "P L A Y   G A M E"); 
	CreateUI(280, 390, "E X I T   G A M E");
	ButtonPanel = new Panel(0, 0, WINDOW_SIZE_X, 90, 0, 10);
	ButtonPanel->m_Button[0]->m_Image->SetBitmap(GROUNDBMP);
	ButtonPanel->m_Button[1]->m_Image->SetBitmap(ERASERBMP);
	ButtonPanel->m_Button[2]->m_Image->SetBitmap(BRICKBMP);
	ButtonPanel->m_Button[3]->m_Image->SetBitmap(NONBREAKBLOCKBMP);
	ButtonPanel->m_Button[4]->m_Image->SetBitmap(BRICKBMP);
	ButtonPanel->m_Button[5]->m_Image->SetBitmap(COINBLOCK01_BMP);
	ButtonPanel->m_Button[6]->m_Image->SetBitmap(COINBLOCK02_BMP);
}

void UIManager::CreateGameOver()
{
	// 게임 오버 화면에서 띄워줄 UI
	CreateUI(280, 240, "YOUR SCORE IS : ");
	CreateUI(570, 240, "000000");
	CreateUI(280, 340, "R E S T A R T");
	CreateUI(280, 390, "E X I T   G A M E");
}

void UIManager::ReStart()
{
	// 점수 초기화
	GameManager::GetInstance()->m_Score = 0;
	GameManager::GetInstance()->m_Coin = 0;
	for (int i = 0; i < index; i++)
	{
		delete m_UIList[i];
	}
	index = 0;
}

void UIManager::CreateUI(int x, int y, char* str)
{
	m_UIList[index++] = new UI(x, y, str);

}

void UIManager::Start()
{
	delete m_UIList[7];
	delete m_UIList[8];

	index--;
	index--;
}

void UIManager::MarioDie()
{
	// 가능하면 이 때 스코어 받아오기?
	// 마리오 죽었을 때 UI들 지워주기.
	delete ButtonPanel;
	for (int i = 0; i < index; i++)
	{
		delete m_UIList[i];
	}
	index = 0;
}

void UIManager::Update()
{

	wsprintf(m_UIList[1]->m_text, "%06d", GameManager::GetInstance()->m_Score);
	wsprintf(m_UIList[2]->m_text, "x %02d", GameManager::GetInstance()->m_Coin);
	wsprintf(m_UIList[6]->m_text, "%03d", GameManager::GetInstance()->m_Time);

}
void UIManager::ClickButton(int mousex, int mousey)
{
	if (ButtonPanel == NULL)
		return;
	if (mousey < 100 && mousey > 0)
	{ 
	
		//10 카운트
		int num = mousex / (960 / ButtonPanel->count);
		ButtonPanel->m_Button[num]->OnClickDown();
		g_tileMode = num;
		switch (num)
		{
			case 0:
			{
				g_tileStr = GROUNDBMP;
				break;
			}
			case 1:
			{
				g_tileStr = ERASERBMP;
				break;
			}
			case 2:
			{
				g_tileStr = BRICKBMP;
				break;
			}
			case 3:
			{
				g_tileStr = NONBREAKBLOCKBMP;
				break;
			}
			case 4:
			{
				g_tileStr = BRICKBMP;
				break;
			}
			case 5:
			{
				g_tileStr = COINBLOCK01_BMP;
				break;
			}
			case 6:
			{
				g_tileStr = COINBLOCK02_BMP;
				break;
			}
			default:
				break;
		}
	}
}
void UIManager::ClickButtonUp()
{
	if (ButtonPanel == NULL)
		return;
	for (int i = 0; i < ButtonPanel->count; i++)
	{
		ButtonPanel->m_Button[i]->OnClickUp();
	}

}
void UIManager::Render()
{
	
	ButtonPanel->Render();
	for (int i = 0; i < index; i++)
	{
		Renderer::Get()->DrawUI(*m_UIList[i]);
	}
}

void UIManager::GameoverUpdate()
{
	wsprintf(m_UIList[1]->m_text, "%06d", GameManager::GetInstance()->m_Score);
}

void UIManager::GameoverRender()
{
	for (int i = 0; i < index; i++)
	{
		Renderer::Get()->DrawUI(*m_UIList[i]);
	}
}
