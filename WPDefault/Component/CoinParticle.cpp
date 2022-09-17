#include "Framework.h"
#include "CoinParticle.h";

CoinParticle::CoinParticle(int _x, int _y)
{
	m_isPlay = false;

	bitmap = new Bitmap(COIN01_BMP);

	//m_Effect[0] = new Bitmap(COIN01_BMP);
	//m_Effect[1] = new Bitmap(COIN02_BMP);
	//m_Effect[2] = new Bitmap(COIN03_BMP);
	//m_Effect[3] = new Bitmap(COIN04_BMP);

	origin_y = _y;

	bitmap->position[0] = _x;
	bitmap->position[1] = _y;
}

CoinParticle::~CoinParticle()
{
	for (int i = 0; i < 4; i++)
	{
		delete m_Effect[i];
	}
	delete bitmap;
}
void CoinParticle::Play(int x, int y)
{
	origin_y = y;

	m_isPlay = true;

	particle_index = 0;
	current_x = x;
	current_y = y;

	turn = false;

	bitmap->position[0] = current_x;
	bitmap->position[1] = current_y;
	bitmap->Update();
}

void CoinParticle::Update()
{
	if (m_isPlay)
	{
		if (bitmap->position[1] <= origin_y - COINPARTICLE_UP_LIMIT && !turn)
		{
			turn = true;
		}
		else if (bitmap->position[1] >= origin_y - COINPARTICLE_UP_LIMIT/4 && turn)
		{
			m_isPlay = false;
		}

		if (turn)
		{
			current_y += COINPARTICLE_UP_AMOUNT * Time::Get()->Delta();
		}
		else
		{
			current_y -= COINPARTICLE_UP_AMOUNT * Time::Get()->Delta();
		}

		particle_index += 1;
		
		particle_index %= 7;

		switch (particle_index)
		{
			case 0:
			{
				bitmap = new Bitmap(COIN01_BMP);
			}break;
			case 1:
			{
				bitmap = new Bitmap(COIN02_BMP);
			}break;
			case 2:
			{
				bitmap = new Bitmap(COIN03_BMP);
			}break;
			case 3:
			{
				bitmap = new Bitmap(COIN04_BMP);
			}break;
		}

		//bitmap = m_Effect[particle_index];

		bitmap->position[0] = current_x;
		bitmap->position[1] = current_y;
		bitmap->Update();
	}
	else
	{
		m_isPlay = false;
	}
}

void CoinParticle::Render()
{
	if (m_isPlay)
	{
		bitmap->Render();
	}
	else
	{

	}
}

