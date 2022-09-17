#pragma once

class Mario : public GameObject
{
public:
	typedef enum
	{
		SMALL_IDLE,
		SMALL_RUN,
		SMALL_HESITATE,
		SMALL_JUMP,
		SMALL_CLIMB,
		SMALL_DEAD,
		SMALL_R_IDLE,
		SMALL_R_RUN,
		SMALL_R_HESITATE,
		SMALL_R_JUMP,
		SMALL_R_CLIMB,
		SMALL_R_DEAD,
		BIG_IDLE,
		BIG_RUN,
		BIG_HESITATE,
		BIG_JUMP,
		BIG_CLIMB,
		BIG_CROUCH,
		BIG_R_IDLE,
		BIG_R_RUN,
		BIG_R_HESITATE,
		BIG_R_JUMP,
		BIG_R_CLIMB,
		BIG_R_CROUCH,
	}STATE;

	Mario();
	~Mario();

	// GameObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

	void GenerateAnimations();

	void GetBig();

	void GetSmall();


	bool Life = true;
	int marioLevel;

private:
	//------------------SMALL
	Animation* s_idle;
	Animation* s_run;
	Animation* s_hesitate;
	Animation* s_jump;
	Animation* s_climb;
	Animation* s_dead;

	Animation* s_rIdle;
	Animation* s_rRun;
	Animation* s_rHesitate;
	Animation* s_rJump;
	Animation* s_rClimb;
	Animation* s_rDead;
	//------------------BIG
	Animation* b_idle;
	Animation* b_run;
	Animation* b_hesitate;
	Animation* b_jump;
	Animation* b_climb;
	Animation* b_crouch;
			   
	Animation* b_rIdle;
	Animation* b_rRun;
	Animation* b_rHesitate;
	Animation* b_rJump;
	Animation* b_rClimb;
	Animation* b_rCrouch;
	//------------------
};