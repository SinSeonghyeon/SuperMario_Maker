#include "Framework.h"
#include "Monster_Move.h"

Tutle::Tutle(float x, float y)
	:GameObject("Monster","Monster")
{
	animator = new Animator(this);
	collider = new Collider(this, 28, 32);
	rigidBody = new RigidBody(this);
	collider->position[1] += 15;
	collider->position[0] += 2;
	GenerateAnimations();

	monoBehaviors.push_back(new Monster_Move(this));
	position = { x,y };
	Init();
}

Tutle::~Tutle()
{
}

void Tutle::Update()
{
	UpdateWorld();

	animator->Update();
	rigidBody->Update();
	collider->Update();
	
}

void Tutle::Render()
{
	collider->Render();
	animator->Play();
}

void Tutle::GenerateAnimations()
{

	
	vector<Bitmap*> idleAnim;
	idleAnim.push_back(new Bitmap("./Resource/Image/Sprite/Tile/Enemies/TurtleL0.bmp"));
	idleAnim.push_back(new Bitmap("./Resource/Image/Sprite/Tile/Enemies/TurtleL1.bmp"));
	Lrun = new Animation(this, idleAnim);

	vector<Bitmap*> deadAnim;
	deadAnim.push_back(new Bitmap("./Resource/Image/Sprite/Tile/Enemies/TurtleDie0.bmp"));
	deadAnim.push_back(new Bitmap("./Resource/Image/Sprite/Tile/Enemies/TurtleDie1.bmp"));
	dead = new Animation(this, deadAnim);

	animator->SetAnimation(0);
	animator->AddAnimation(LRUN, Lrun);
	animator->AddAnimation(DEAD, dead);

}