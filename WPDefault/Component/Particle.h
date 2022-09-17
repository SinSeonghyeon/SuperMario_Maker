#pragma once

class Particle
{
public:
	Particle(int _x, int _y);
	~Particle();

public:
	bool m_isPlay;
	double m_startx;
	double m_starty;
	Bitmap *m_Effect[4];

	void Play(int x, int y);
	void Update();
	void Render();
};