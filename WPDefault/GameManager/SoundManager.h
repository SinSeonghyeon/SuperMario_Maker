#pragma once


#define MAX_SIZE_SOUND 7
#define EFFECT_MAX_SIZE 9

//배경음
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
//효과음
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
	//배경음 관련
	Sound* m_pSound[MAX_SIZE_SOUND];
	Channel* m_pChannel;

	//효과음
	Sound* m_pESound[EFFECT_MAX_SIZE];
	Channel* m_pEChannel[5];

	FMOD_RESULT result;

	void Soundsetup();
};
