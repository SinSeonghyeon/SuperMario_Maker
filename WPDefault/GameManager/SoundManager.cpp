#include "Framework.h"



void SoundManager::Soundsetup()
{
	result = System_Create(&m_pSystem);
	result = m_pSystem->init(7, FMOD_INIT_NORMAL, 0);

	char str[128];
	//���� ���ҽ� �ּ� �Ҵ�.
	for (int i = 0; i < MAX_SIZE_SOUND; i++) {
		sprintf_s(str, "Resource/Sounds/bgm/%d.wav", i);
		m_pSystem->createSound(str, FMOD_LOOP_OFF, 0, &m_pSound[i]);
	}
	for (int i = 0; i < EFFECT_MAX_SIZE; i++) {
		sprintf_s(str, "Resource/Sounds/Effect/%d.wav", i);
		m_pSystem->createSound(str, FMOD_LOOP_OFF, 0, &m_pESound[i]);
	}
}

//���� ���
void SoundManager::Playsound(SoundTrack soundnum)
{
	StopMusic();
	m_pSystem->playSound(m_pSound[(int)soundnum], 0, false, &m_pChannel);
}

void SoundManager::PlayLoop(SoundTrack soundnum)
{
	bool playing = false;
	m_pChannel->isPlaying(&playing);
	if (!playing)
	{
		m_pSystem->playSound(m_pSound[(int)soundnum], 0, false, &m_pChannel);
	}
}

//ȿ����
void SoundManager::EPlaysound(ESoundTrack soundnum) {
	bool playing = false;

	for (int i = 0; i < 5; i++)
	{
		m_pEChannel[i]->isPlaying(&playing);
		if (!playing)
		{
			m_pSystem->playSound(m_pESound[(int)soundnum], 0, false, &m_pEChannel[i]);
			break;
		}
	}
}

//���� ����
void SoundManager::StopMusic()
{
	m_pChannel->stop();
}

//���� �Ͻ�����
void SoundManager::PauseMusic() {
	m_pChannel->setPaused(true);
}
//���� �簳
void SoundManager::RePlayMusic()
{
	m_pChannel->setPaused(false);
}

//�Ҹ���ȣ���
void SoundManager::Releasesound() {
	m_pSystem->release();
}



SoundManager::SoundManager()
{
	Soundsetup();
}

SoundManager::~SoundManager()
{
	Releasesound();
}