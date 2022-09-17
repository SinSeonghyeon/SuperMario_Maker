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

	// GameObject��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

	void GenerateAnimations();

private:
	Animation* idle;
	Animation* run;
	Animation* dead;
};