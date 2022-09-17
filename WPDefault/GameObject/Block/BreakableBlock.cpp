#include "Framework.h"
#include "BreakableBlock.h"
#include "GameObject/Block/Block_break.h"

BreakableBlock::BreakableBlock()
{
	collider = new Collider(this, TILE_SIZE, TILE_SIZE);

	bitmap = new Bitmap(BRICKBMP, this);
	monoBehaviors.push_back(new Block_break(this));

	Init();
}

BreakableBlock::BreakableBlock(POINT position)
{
	collider = new Collider(this, TILE_SIZE, TILE_SIZE);
	bitmap = new Bitmap(BRICKBMP, this);
	monoBehaviors.push_back(new Block_break(this));

	this->position[0] = position.x;
	this->position[1] = position.y;

	Init();
}

BreakableBlock::~BreakableBlock()
{
}

void BreakableBlock::Update()
{
	bitmap->Update();
	collider->Update();
	UpdateWorld();
}

void BreakableBlock::Render()
{
	bitmap->Render();
	collider->Render();
}
