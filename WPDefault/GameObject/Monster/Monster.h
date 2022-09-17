#pragma once

class Monster : public GameObject
{
public:
	typedef enum
	{
		IDLE,
		DEAD,

	}STATE;

	Monster(float x, float y);
	~Monster();

	// GameObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

	void GenerateAnimations();

private:
	Animation* idle;
	Animation* run;
	Animation* dead;
};