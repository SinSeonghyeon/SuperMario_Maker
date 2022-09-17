#include "Framework.h"
#include "UnbreakableBlock.h"

UnbreakableBlock::UnbreakableBlock()
{
	collider = new Collider(this, TILE_SIZE, TILE_SIZE);
	bitmap = new Bitmap("./Resource/Image/Sprite/Tile/BlocksAndItem/NonBreakableBlock.bmp", this);

	Init();
}

UnbreakableBlock::UnbreakableBlock(POINT position)
{
	collider = new Collider(this, TILE_SIZE, TILE_SIZE);
	bitmap = new Bitmap(NONBREAKBLOCKBMP, this);

	this->position[0] = position.x;
	this->position[1] = position.y;

	Init();
}

UnbreakableBlock::UnbreakableBlock(POINT position, bool ground)
{
	collider = new Collider(this, TILE_SIZE, TILE_SIZE);
	if (ground)
	{
		// 땅이면
		bitmap = new Bitmap(GROUNDBMP, this);
	}
	else
	{
		bitmap = new Bitmap(NONBREAKBLOCKBMP, this);
	}

	this->position[0] = position.x;
	this->position[1] = position.y;

	Init();
}

UnbreakableBlock::UnbreakableBlock(POINT position, int pipeNum)
{
	//collider = new Collider(this, TILE_SIZE, TILE_SIZE);
	// 파이프는 콜라이더를 그려주지 않음. or 첫번째 위치에만 그려줌..?
	switch (pipeNum)
	{
		// 0 - 좌측 상단
		case 0:
		{
			bitmap = new Bitmap(UPIPELUBMP, this);
			collider = new Collider(this, TILE_SIZE * 2, TILE_SIZE * 2);
			break;
		}
		// 1 - 우측 상단
		case 1:
		{
			bitmap = new Bitmap(UPIPERUBMP, this);
			// 콜라이더 생성은 하는데 사이즈가 0인..
			collider = new Collider(this, 0, 0);
			break;
		}
		// 2 - 좌측 하단
		case 2:
		{
			bitmap = new Bitmap(UPIPELDBMP, this);
			collider = new Collider(this, 0, 0);
			break;
		}
		// 3 - 우측 하단
		case 3:
		{
			bitmap = new Bitmap(UPIPERDBMP, this);
			collider = new Collider(this, 0, 0);
			break;
		}
		default:
		{
			// 기본적으로는 부서지지 않는 블럭
			collider = new Collider(this, TILE_SIZE, TILE_SIZE);
			bitmap = new Bitmap(NONBREAKBLOCKBMP, this);
			break;
		}
	}

	this->position[0] = position.x;
	this->position[1] = position.y;

	Init();
}

UnbreakableBlock::~UnbreakableBlock()
{
	
}

void UnbreakableBlock::Update()
{
	bitmap->Update();
	collider->Update();
	UpdateWorld();
}

void UnbreakableBlock::Render()
{
	bitmap->Render();
	collider->Render();
}
