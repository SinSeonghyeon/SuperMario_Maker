#pragma once

class MushroomBlock : public GameObject
{
public:

	typedef enum
	{
		IDLE,
		EMPTY
	}STATE;

	MushroomBlock();
	~MushroomBlock();
	MushroomBlock(POINT position);

	// GameObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

	void GenerateAnimations();

private:
	Bitmap* bitmap;

	Animation* idle;
	Animation* empty;
};