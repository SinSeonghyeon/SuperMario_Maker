#include "Framework.h"

Time* Time::instance = nullptr;

Time::Time()
	: curTicks(0), lastFPSUpdate(0),
	frameCount(0), runningTime(0), framePerSecond(0)
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&ticksPerSecond);//초당 틱을 저장
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTicks);//시작시의 틱을 저장
	secondsPerTick = 1.0f / ticksPerSecond;//1틱당 몇 초
}

Time::~Time()
{
}

void Time::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&curTicks);//현재 틱을 받아온다
	timeElapsed = (float)(curTicks - lastTicks) * secondsPerTick;//지난 업데이트동안 몇 초가 흘렀는지, ex) 1틱당 0.2초라면 5틱이라면 1초
	runningTime += timeElapsed;//Time 객체 생성이후 시간이 얼마나 흘렀나 저장

	frameCount++;
	if (curTicks - lastFPSUpdate >= ticksPerSecond)//지난 업데이트로 부터의 틱이 초당 틱을 넘어가면 == 1초 마다 
	{
		float tempCurTime = (float)curTicks * secondsPerTick;//틱 카운트 시작시 부터 지금까지 몇초 지났는지
		float tempLastTime = (float)lastFPSUpdate * secondsPerTick;//틱 카운트 시작시부터 지난 FPS업데이트까지 몇초 지났는지
		framePerSecond = (float)frameCount / (tempCurTime - tempLastTime);//초당 프레임 수

		lastFPSUpdate = curTicks;//이번 업데이트가 몇 틱 째에 실행됐는지 저장
		frameCount = 0;//프레임 카운트 초기화
	}

	lastTicks = curTicks;//다음 업데이트에 사용할 틱 정보 저장


	//
	/*char FPS[3];
	memcpy(FPS, &framePerSecond, sizeof(float));
	char* FPSShow = FPS;
	Graphic->Print(560, 0, FPSShow);*/

}

