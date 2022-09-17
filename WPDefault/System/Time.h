#pragma once

class Time
{
private:
	__int64 ticksPerSecond;//ÃÊ´ç Æ½
	__int64 curTicks;//ÇöÀç Æ½
	__int64 lastTicks;//Áö³­ Ã¼Å© ÁöÁ¡ÀÇ Æ½
	__int64 lastFPSUpdate;

	unsigned int frameCount;
	float runningTime;//Time °´Ã¼ »ý¼ºÀÌÈÄ ½Ã°£ÀÌ ¾ó¸¶³ª Èê·¶³ª ÀúÀå
	float framePerSecond;//ÃÊ´ç ÇÁ·¹ÀÓ

	float secondsPerTick;//1Æ½´ç ¸î ÃÊ
	float timeElapsed;//1ÇÁ·¹ÀÓ´ç ¸î ÃÊ

	static Time* instance;
	Time();
	~Time();

public:
	static Time* Get() { return instance; }
	static void Create() { instance = new Time(); }
	static void Delete() { delete instance; }

	void Update();


	float Delta() { return timeElapsed; }
	float FPS() { return framePerSecond; }
	float Running() { return runningTime; }
};