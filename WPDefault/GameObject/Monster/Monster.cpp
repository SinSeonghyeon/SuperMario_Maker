#include "Framework.h"

#include "GameObject/Monster/Monster_Move.h"

Monster::Monster(float x, float y)
	:GameObject("Monster", "Monster")
{
	animator = new Animator(this);
	collider = new Collider(this,28,32);
	rigidBody = new RigidBody(this);
	rigidBody->gravity = 400.0f;
	collider->position[0] += 2;
	GenerateAnimations();

	monoBehaviors.push_back(new Monster_Move(this));
	position = { x,y };
	Init();
}

Monster::~Monster()
{
}

void Monster::Update()
{
	UpdateWorld();

	animator->Update();
	rigidBody->Update();
	collider->Update();
}

void Monster::Render()
{
	collider->Render();
	animator->Play();
}

void Monster::GenerateAnimations()
{
	vector<Bitmap*> idleAnim;
	idleAnim.push_back(new Bitmap("./Resource/Image/Sprite/Tile/Enemies/Goomba0.bmp"));
	idleAnim.push_back(new Bitmap("./Resource/Image/Sprite/Tile/Enemies/Goomba1.bmp"));
	idle = new Animation(this, idleAnim);

	vector<Bitmap*> deadAnim;
	deadAnim.push_back(new Bitmap("./Resource/Image/Sprite/Tile/Enemies/GoombaDie.bmp"));
	dead = new Animation(this, deadAnim);
	animator->SetAnimation(0);
	animator->AddAnimation(IDLE, idle);
	animator->AddAnimation(DEAD, dead);

	
	//m_Item[(int)EItem::Flower]->animator->AddAnimation(0, Flower);
	//animator->SetAnimation(Monster::STATE::IDLE);

}
