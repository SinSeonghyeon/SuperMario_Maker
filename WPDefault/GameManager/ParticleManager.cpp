#include "Framework.h"
ParticleManager::ParticleManager()
{
	for (int i = 0; i < 10; i++)
	{
		m_Particle[i] = new Particle(0,0);
		c_Particle[i] = new CoinParticle(0,0);
	}
}

ParticleManager::~ParticleManager()
{
	for (int i = 0; i < 10; i++)
	{
		delete m_Particle[i];
		delete c_Particle[i];
	}
}

void ParticleManager::Play(int x, int y)
{
	GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::BreakBlock);
	for (int i = 0; i < 10; i ++)
	{
		if (!m_Particle[i]->m_isPlay)
		{
			m_Particle[i]->Play(x, y);
			break;
		}
	}
}

void ParticleManager::CoinPlay(int x, int y)
{
	//GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::BreakBlock);
	for (int i = 0; i < 10; i++)
	{
		if (!c_Particle[i]->m_isPlay)
		{
			c_Particle[i]->Play(x, y);
			break;
		}
	}
}

void ParticleManager::Update()
{
	for (int i = 0; i < 10; i++)
	{
		if (m_Particle[i]->m_isPlay)
		{
			m_Particle[i]->Update();
		}
		if (c_Particle[i]->m_isPlay)
		{
			c_Particle[i]->Update();
		}
	}
}

void ParticleManager::Render()
{
	for (int i = 0; i < 10; i++)
	{
		if (m_Particle[i]->m_isPlay)
		{
			m_Particle[i]->Render();
		}
		if (c_Particle[i]->m_isPlay)
		{
			c_Particle[i]->Render();
		}
	}
}
