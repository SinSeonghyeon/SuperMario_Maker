#include "Framework.h"

Particle::Particle(int _x, int _y)
{
	m_isPlay = false;
	m_Effect[0] = new Bitmap(IDB_PARTICLERU);
	m_Effect[1] = new Bitmap(IDB_PARTICLERD);
	m_Effect[2] = new Bitmap(IDB_PARTICLELU);
	m_Effect[3] = new Bitmap(IDB_PARTICLELD);
	m_startx = _x;
	m_starty = _y;
	for (int i = 0; i < 4; i++)
	{
		m_Effect[i]->position[0] = m_startx;
		m_Effect[i]->position[1] = m_starty;

	}
	
}

Particle::~Particle()
{
	for (int i = 0; i < 4; i++)
	{
		delete m_Effect[i];
	}
}
void Particle::Play(int x, int y)
{
	m_isPlay = true;
	m_startx = x;
	m_starty = y;
	for (int i = 0; i < 4; i++)
	{
		m_Effect[i]->position[0] = m_startx;
		m_Effect[i]->position[1] = m_starty;
		m_Effect[i]->Update();
	}
}
void Particle::Update()
{
	if (m_Effect[1]->position[1] <= 800 && m_isPlay)
	{
		m_Effect[0]->position[1] = 0.06 * ((m_Effect[0]->position[0] - m_startx) * (m_Effect[0]->position[0] - m_startx - 50)) + (double)m_starty;
		m_Effect[0]->position[0] += 130 * Time::Get()->Delta();
		m_Effect[1]->position[1] = 0.025 * ((m_Effect[1]->position[0] - m_startx) * (m_Effect[1]->position[0] - m_startx - 100)) + (double)m_starty;
		m_Effect[1]->position[0] += 200 * Time::Get()->Delta();

		m_Effect[2]->position[1] = m_Effect[0]->position[1];
		m_Effect[2]->position[0] = m_startx + (m_startx - m_Effect[0]->position[0]);
		m_Effect[3]->position[1] = m_Effect[1]->position[1];
		m_Effect[3]->position[0] = m_startx + (m_startx - m_Effect[1]->position[0]);

		for (int i = 0; i < 4; i++)
		{
			m_Effect[i]->Update();
		}
	}
	else
	{
		m_isPlay = false;
	}
}

void Particle::Render()
{
	if (m_isPlay)
	{
		for (int i = 0; i < 4; i++)
		{
			m_Effect[i]->Render();
		}
	}
	else
	{
		
	}
}


