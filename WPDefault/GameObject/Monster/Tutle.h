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

	// GameObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

	void GenerateAnimations();

private:
	Animation* run;
	Animation* Lrun;
	Animation* dead;
};

