#pragma once

class ItemManger;


class GameManager
{
public:
	void Die();
	UIManager m_UIManager;
	SoundManager m_SoundManager;
	ParticleManager m_ParticleManager;
	ItemManager m_ItemManager;
	MonsterManager m_MonsterManager;

	static GameManager* GetInstance();

	GameManager();
	~GameManager();
	
	int m_Coin;
	int m_Time;
	int m_Score = 10;

private:
	static GameManager* Instance;
};


