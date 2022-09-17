#pragma once

class UnbreakableBlock : public GameObject
{
public:
	UnbreakableBlock();
	~UnbreakableBlock();
	UnbreakableBlock(POINT position);
	// 땅과 파이프를 위한 생성자
	UnbreakableBlock(POINT position, bool ground);
	UnbreakableBlock(POINT position, int pipeNum);

	// GameObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	Bitmap* bitmap;

};