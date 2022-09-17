#pragma once
class ParticleManager
{
public:
	ParticleManager();
	~ParticleManager();

	Particle* m_Particle[10];
	CoinParticle* c_Particle[10];
	void Play(int x, int y);

	void CoinPlay(int x, int y);

	void Update();
	void Render();
};

