#include "Framework.h"

GameManager* GameManager::Instance = NULL;

void GameManager::Die()
{
	GameManager::GetInstance()->m_SoundManager.Playsound(SoundTrack::die);
	//Sleep 뺴고 바꿔줘야함!
	// 가능하면 이 때 애들 다 없애줘야..
	GameManager::GetInstance()->m_UIManager.MarioDie();
	// 게임 오브젝트 클리어 되면 됨!!
	GOM->Clear();
	GameManager::GetInstance()->m_MonsterManager.DeleteMonsert();
	Program::ChangeScene(new GameoverScene());
}

GameManager* GameManager::GetInstance()
{
	if (Instance == NULL)
	{
		Instance = new GameManager();
	}
	return Instance;
}


GameManager::GameManager()
{
	 m_Coin = 0;
	 m_Time = 0;
	 m_Score = 0;
}

GameManager::~GameManager()
{

}