#include "Framework.h"
#include "FakeCoinBlock.h"
#include "GameObject/Block/Block_getcoinFake.h"

FakeCoinBlock::FakeCoinBlock()
{
	collider = new Collider(this, TILE_SIZE, TILE_SIZE);
	bitmap = new Bitmap(BRICKBMP, this);
	monoBehaviors.push_back(new Block_getcoinFake(this));

	Init();
}

FakeCoinBlock::FakeCoinBlock(POINT position)
{
	collider = new Collider(this, TILE_SIZE, TILE_SIZE);
	bitmap = new Bitmap(BRICKBMP, this);
	monoBehaviors.push_back(new Block_getcoinFake(this));

	this->position[0] = position.x;
	this->position[1] = position.y;

	Init();
}

FakeCoinBlock::~FakeCoinBlock()
{
	
}

void FakeCoinBlock::Update()
{
	bitmap->Update();
	collider->Update();
	UpdateWorld();
}

void FakeCoinBlock::Render()
{
	bitmap->Render();
	collider->Render();
}

void FakeCoinBlock::BlockDisable()
{
	bitmap = new Bitmap(COINBLOCK_EMPTY_BMP, this);
}
