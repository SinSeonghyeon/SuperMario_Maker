#include "Framework.h"
#include "MushroomBlock.h"
#include "GameObject/Block/Block_spawnmushroom.h"

MushroomBlock::MushroomBlock()
{
	collider = new Collider(this, TILE_SIZE, TILE_SIZE);
	animator = new Animator(this);
	GenerateAnimations();
	animator->SetAnimation(CoinBlock::STATE::IDLE);
	//bitmap = new Bitmap(COINBLOCK_01, this);
	monoBehaviors.push_back(new Block_spawnmushroom(this));

	Init();
}

MushroomBlock::MushroomBlock(POINT position)
{
	collider = new Collider(this, TILE_SIZE, TILE_SIZE);
	animator = new Animator(this);
	GenerateAnimations();
	animator->SetAnimation(CoinBlock::STATE::IDLE);
	//bitmap = new Bitmap(COINBLOCK_01, this);
	monoBehaviors.push_back(new Block_spawnmushroom(this));

	this->position[0] = position.x;
	this->position[1] = position.y;

	Init();
}

MushroomBlock::~MushroomBlock()
{
	
}

void MushroomBlock::Update()
{
	//bitmap->Update();
	collider->Update();
	animator->Update();
	UpdateWorld();
}

void MushroomBlock::Render()
{
	//bitmap->Render();
	collider->Render();
	animator->Play();
}

void MushroomBlock::GenerateAnimations()
{
	vector<Bitmap*> idleAnim;
	idleAnim.push_back(new Bitmap(COINBLOCK01_BMP));
	idleAnim.push_back(new Bitmap(COINBLOCK02_BMP));
	idleAnim.push_back(new Bitmap(COINBLOCK03_BMP));
	idle = new Animation(this, idleAnim);

	vector<Bitmap*> emptyAnim;
	emptyAnim.push_back(new Bitmap(COINBLOCK_EMPTY_BMP));
	empty = new Animation(this, emptyAnim);

	animator->AddAnimation(IDLE, idle);
	animator->AddAnimation(EMPTY, empty);
}