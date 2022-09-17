#pragma once

class BreakableBlock : public GameObject
{
public:
	BreakableBlock();
	~BreakableBlock();
	BreakableBlock(POINT position);

	// GameObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	Bitmap* bitmap;

};