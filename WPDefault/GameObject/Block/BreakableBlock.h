#pragma once

class BreakableBlock : public GameObject
{
public:
	BreakableBlock();
	~BreakableBlock();
	BreakableBlock(POINT position);

	// GameObject��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	Bitmap* bitmap;

};