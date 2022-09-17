#pragma once

class CoinParticle
{
public:
	CoinParticle(int _x, int _y);
	~CoinParticle();

public:
	bool m_isPlay;
	bool turn = false;
	double origin_y;

	int particle_index = 0;

	int current_x, current_y;

	Bitmap* m_Effect[4];
	Bitmap* bitmap;

	void Play(int x, int y);
	void Update();
	void Render();
};