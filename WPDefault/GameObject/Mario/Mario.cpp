#include "Framework.h"
#include "Mario.h"
#include "GameObject/Mario/Mario_Move.h"

Mario::Mario()
	:GameObject("Mario", "Mario")
{
	animator = new Animator(this);

	collider = new Collider(this, MarioColliderSize_S_WIDTH, MarioColliderSize_S_HEIGHT);
	collider->position[0] += 10;

	rigidBody = new RigidBody(this);

	GenerateAnimations();


	monoBehaviors.push_back(new Mario_Move(this));

	position = { 50,50 };

	marioLevel = 0;

	Init();
}

Mario::~Mario()
{
	delete rigidBody;
	delete collider;

	delete animator;
	delete s_idle;
	delete s_run;
	delete s_jump;
	delete s_climb;
	delete s_dead;
}

void Mario::Update()
{

	
	rigidBody->Update();
	collider->Update();
	animator->Update();
	UpdateWorld();
	if (position[0] < RENDERER->GetCamera()->position[0])
	{
		position[0] = RENDERER->GetCamera()->position[0];
	}

}

void Mario::Render()
{
	collider->Render();
	animator->Play();
}

void Mario::GenerateAnimations()
{
	vector<Bitmap*> idleAnim;
	idleAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Left_Move/Left_Move1.bmp"));
	s_idle = new Animation(this, idleAnim);

	vector<Bitmap*> runAnim;
	runAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Left_Move/Left_Move2.bmp"));//todo : 경로 잘못 썼거나 경로로 리소스 잘 안불러지는 듯
	runAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Left_Move/Left_Move3.bmp"));
	runAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Left_Move/Left_Move4.bmp"));
	s_run = new Animation(this, runAnim);

	vector<Bitmap*> hesitateAnim;
	hesitateAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Left_Move/Left_Move5.bmp"));
	s_hesitate = new Animation(this, hesitateAnim);

	vector<Bitmap*> jumpAnim;
	jumpAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Left_Move/Left_Move6.bmp"));
	s_jump = new Animation(this, jumpAnim);

	vector<Bitmap*> climbAnim;
	climbAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Left_Move/Left_Move7.bmp"));
	climbAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Left_Move/Left_Move8.bmp"));
	s_climb = new Animation(this, climbAnim);


	vector<Bitmap*> deadAnim;
	deadAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Left_Move/Left_Move9.bmp"));
	s_dead = new Animation(this, deadAnim);

	/// <summary>
	/// 반대
	/// </summary>
	vector<Bitmap*> r_idleAnim;
	r_idleAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Right_Move/Right_Move1.bmp"));
	s_rIdle = new Animation(this, r_idleAnim);

	vector<Bitmap*> r_runAnim;
	r_runAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Right_Move/Right_Move2.bmp"));//todo : 경로 잘못 썼거나 경로로 리소스 잘 안불러지는 듯
	r_runAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Right_Move/Right_Move3.bmp"));
	r_runAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Right_Move/Right_Move4.bmp"));
	s_rRun = new Animation(this, r_runAnim);

	vector<Bitmap*> r_hesitateAnim;
	r_hesitateAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Right_Move/Right_Move5.bmp"));
	s_rHesitate = new Animation(this, r_hesitateAnim);

	vector<Bitmap*> r_jumpAnim;
	r_jumpAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Right_Move/Right_Move6.bmp"));
	s_rJump = new Animation(this, r_jumpAnim);

	vector<Bitmap*> r_climbAnim;
	r_climbAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Right_Move/Right_Move7.bmp"));
	r_climbAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Right_Move/Right_Move8.bmp"));
	s_rClimb = new Animation(this, r_climbAnim);


	vector<Bitmap*> r_deadAnim;
	r_deadAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Small/Right_Move/Right_Move9.bmp"));
	s_rDead = new Animation(this, r_deadAnim);

	//---------------------------------------------------------------------------------------------------------------
	vector<Bitmap*> B_idleAnim;
	B_idleAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Left_Move/Left_Move9.bmp"));
	b_idle = new Animation(this, B_idleAnim);
	
	vector<Bitmap*> B_runAnim;
	B_runAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Left_Move/Left_Move1.bmp"));//todo : 경로 잘못 썼거나 경로로 리소스 잘 안불러지는 듯
	B_runAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Left_Move/Left_Move2.bmp"));
	B_runAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Left_Move/Left_Move3.bmp"));
	b_run = new Animation(this, B_runAnim);
	
	vector<Bitmap*> B_hesitateAnim;
	B_hesitateAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Left_Move/Left_Move4.bmp"));
	b_hesitate = new Animation(this, B_hesitateAnim);
	
	vector<Bitmap*> B_jumpAnim;
	B_jumpAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Left_Move/Left_Move5.bmp"));
	b_jump = new Animation(this, B_jumpAnim);
	
	vector<Bitmap*> B_climbAnim;
	B_climbAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Left_Move/Left_Move6.bmp"));
	B_climbAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Left_Move/Left_Move7.bmp"));
	b_climb = new Animation(this, B_climbAnim);
	
	
	vector<Bitmap*> B_crouchAnim;
	B_crouchAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Left_Move/Left_Move8.bmp"));
	b_crouch = new Animation(this, B_crouchAnim);
	
	/// <summary>
	/// 반대
	/// </summary>
	vector<Bitmap*> B_r_idleAnim;
	B_r_idleAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Right_Move/Right_Move9.bmp"));
	b_rIdle = new Animation(this, B_r_idleAnim);
	
	vector<Bitmap*> B_r_runAnim;
	B_r_runAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Right_Move/Right_Move1.bmp"));//todo : 경로 잘못 썼거나 경로로 리소스 잘 안불러지는 듯
	B_r_runAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Right_Move/Right_Move2.bmp"));
	B_r_runAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Right_Move/Right_Move3.bmp"));
	b_rRun = new Animation(this, B_r_runAnim);
	
	vector<Bitmap*> B_r_hesitateAnim;
	B_r_hesitateAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Right_Move/Right_Move4.bmp"));
	b_rHesitate = new Animation(this, B_r_hesitateAnim);
	
	vector<Bitmap*> B_r_jumpAnim;
	B_r_jumpAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Right_Move/Right_Move5.bmp"));
	b_rJump = new Animation(this, B_r_jumpAnim);
	
	vector<Bitmap*> B_r_climbAnim;
	B_r_climbAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Right_Move/Right_Move6.bmp"));
	B_r_climbAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Right_Move/Right_Move7.bmp"));
	b_rClimb = new Animation(this, B_r_climbAnim);
	
	
	vector<Bitmap*> B_r_crouchAnim;
	B_r_crouchAnim.push_back(new Bitmap("./Resource/Image/Sprite/Character/Big/Right_Move/Right_Move8.bmp"));
	b_rCrouch = new Animation(this, B_r_crouchAnim);
	
	
	
	animator->AddAnimation(BIG_IDLE, b_idle);
	animator->AddAnimation(BIG_RUN, b_run);
	animator->AddAnimation(BIG_HESITATE, b_hesitate);
	animator->AddAnimation(BIG_JUMP, b_jump);
	animator->AddAnimation(BIG_CLIMB, b_climb);
	animator->AddAnimation(BIG_CROUCH, b_crouch);
						   
	animator->AddAnimation(BIG_R_IDLE, b_rIdle);
	animator->AddAnimation(BIG_R_RUN, b_rRun);
	animator->AddAnimation(BIG_R_HESITATE, b_rHesitate);
	animator->AddAnimation(BIG_R_JUMP, b_rJump);
	animator->AddAnimation(BIG_R_CLIMB, b_rClimb);
	animator->AddAnimation(BIG_R_CROUCH, b_rCrouch);
	//---------------------------------------------------------------------------------------------------------------

	animator->AddAnimation(SMALL_IDLE, s_idle);
	animator->AddAnimation(SMALL_RUN, s_run);
	animator->AddAnimation(SMALL_HESITATE, s_hesitate);
	animator->AddAnimation(SMALL_JUMP, s_jump);
	animator->AddAnimation(SMALL_CLIMB, s_climb);
	animator->AddAnimation(SMALL_DEAD, s_dead);

	animator->AddAnimation(SMALL_R_IDLE, s_rIdle);
	animator->AddAnimation(SMALL_R_RUN, s_rRun);
	animator->AddAnimation(SMALL_R_HESITATE, s_rHesitate);
	animator->AddAnimation(SMALL_R_JUMP, s_rJump);
	animator->AddAnimation(SMALL_R_CLIMB, s_rClimb);
	animator->AddAnimation(SMALL_R_DEAD, s_rDead);

}

void Mario::GetBig()
{
	marioLevel = 1;
	position[1] -= 10;
	collider = new Collider(this, MarioColliderSize_B_WIDTH, MarioColliderSize_B_HEIGHT);
	collider->position[0];
}

void Mario::GetSmall()
{
	
	marioLevel = 0;
	position[1] += 10;
	collider = new Collider(this, MarioColliderSize_S_WIDTH, MarioColliderSize_S_HEIGHT);
	collider->position[0] += 10;
	
}