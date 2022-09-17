#pragma once


#define MAX_SIZE_SOUND 7
#define EFFECT_MAX_SIZE 9

//�����
enum class SoundTrack
{
	BGM,
	Warning,
	gameover,
	die,
	pipe,
	flagpole,
	stage_clear
};
//ȿ����
enum class ESoundTrack
{
	SmallJump,
	BigJump,
	Coin,
	FireBall,
	PowerUp,
	PowerUp2,
	lifeUp,
	Stomp,
	BreakBlock,

};

using namespace FMOD;

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	void Playsound(SoundTrack soundnum);
	void PlayLoop(SoundTrack soundnum);
	void EPlaysound(ESoundTrack soundnum);
	
	void StopMusic();
	void PauseMusic();
	void RePlayMusic();
	void Releasesound();
	
private:
	System* m_pSystem;
	//����� ����
	Sound* m_pSound[MAX_SIZE_SOUND];
	Channel* m_pChannel;

	//ȿ����
	Sound* m_pESound[EFFECT_MAX_SIZE];
	Channel* m_pEChannel[5];

	FMOD_RESULT result;

	void Soundsetup();
};
