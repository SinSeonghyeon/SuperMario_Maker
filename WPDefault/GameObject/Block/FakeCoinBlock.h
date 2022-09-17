#pragma once

class FakeCoinBlock : public GameObject
{
public:
	FakeCoinBlock();
	~FakeCoinBlock();
	FakeCoinBlock(POINT position);

	// GameObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

	void BlockDisable();

private:
	Bitmap* bitmap;
};