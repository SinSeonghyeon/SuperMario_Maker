#include "Framework.h"

GameManager* GameManager::Instance = NULL;

void GameManager::Die()
{
	GameManager::GetInstance()->m_SoundManager.Playsound(SoundTrack::die);
	//Sleep ���� �ٲ������!
	// �����ϸ� �� �� �ֵ� �� �������..
	GameManager::GetInstance()->m_UIManager.MarioDie();
	// ���� ������Ʈ Ŭ���� �Ǹ� ��!!
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