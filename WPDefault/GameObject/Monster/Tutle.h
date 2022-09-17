#pragma once
class Tutle : public GameObject
{
public:
	typedef enum
	{
		LRUN,
		DEAD,

	}STATE;

	Tutle(float x, float y);
	~Tutle();

	// GameObject��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

	void GenerateAnimations();

private:
	Animation* run;
	Animation* Lrun;
	Animation* dead;
};

