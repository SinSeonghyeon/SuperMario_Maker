#pragma once

class CoinBlock : public GameObject
{
public:

	typedef enum
	{
		IDLE,
		EMPTY
	}STATE;

	CoinBlock();
	~CoinBlock();
	CoinBlock(POINT position);

	// GameObject��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

	void GenerateAnimations();

private:
	Bitmap* bitmap;

	Animation* idle;
	Animation* empty;
};
