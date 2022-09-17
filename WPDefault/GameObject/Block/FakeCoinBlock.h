#pragma once

class FakeCoinBlock : public GameObject
{
public:
	FakeCoinBlock();
	~FakeCoinBlock();
	FakeCoinBlock(POINT position);

	// GameObject��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

	void BlockDisable();

private:
	Bitmap* bitmap;
};