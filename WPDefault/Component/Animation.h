#pragma once

class Animation : public Component
{
public:
	Animation(GameObject* gameObject, vector<Bitmap*> inputClip);
	~Animation();

	void Update();

	void Render();
	//현재 클립을 그림

	//시간을 체크 함

	//시간이 정해놓은 시간보다 커지면 다음 클립으로 넘김

	void Filp();

	void Reset() { timeElapsed = 0.0f; clipIndex = 0; currentClip = clips[0]; }//애니메이션 재시작시에

	vector<Bitmap*> clips;
	Bitmap* currentClip;

private:
	int clipIndex;
	int animSize;
	float frameRate;//클립을 넘길 간격
	float timeElapsed;//누적 시간 체크
};