#include "Framework.h"
#include "CoinBlock.h"
#include "GameObject/Block/Block_getcoin.h"

CoinBlock::CoinBlock()
{
	collider = new Collider(this, TILE_SIZE, TILE_SIZE);
	animator = new Animator(this);
	GenerateAnimations();
	animator->SetAnimation(CoinBlock::STATE::IDLE);
	//bitmap = new Bitmap(COINBLOCK_01, this);
	monoBehaviors.push_back(new Block_getcoin(this));

	Init();
}

CoinBlock::CoinBlock(POINT position)
{
	collider = new Collider(this, TILE_SIZE, TILE_SIZE);
	animator = new Animator(this);
	GenerateAnimations();
	animator->SetAnimation(CoinBlock::STATE::IDLE);
	//bitmap = new Bitmap(COINBLOCK_01, this);
	monoBehaviors.push_back(new Block_getcoin(this));

	this->position[0] = position.x;
	this->position[1] = position.y;

	Init();
}

CoinBlock::~CoinBlock()
{
	// 동시에 두 번 지워져서 에러 발생
}

void CoinBlock::Update()
{
	//bitmap->Update();
	collider->Update();
	animator->Update();
	UpdateWorld();
}

void CoinBlock::Render()
{
	//bitmap->Render();
	collider->Render();
	animator->Play();
}

void CoinBlock::GenerateAnimations()
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