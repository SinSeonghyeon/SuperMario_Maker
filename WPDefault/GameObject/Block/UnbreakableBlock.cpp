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
		// ���̸�
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
	// �������� �ݶ��̴��� �׷����� ����. or ù��° ��ġ���� �׷���..?
	switch (pipeNum)
	{
		// 0 - ���� ���
		case 0:
		{
			bitmap = new Bitmap(UPIPELUBMP, this);
			collider = new Collider(this, TILE_SIZE * 2, TILE_SIZE * 2);
			break;
		}
		// 1 - ���� ���
		case 1:
		{
			bitmap = new Bitmap(UPIPERUBMP, this);
			// �ݶ��̴� ������ �ϴµ� ����� 0��..
			collider = new Collider(this, 0, 0);
			break;
		}
		// 2 - ���� �ϴ�
		case 2:
		{
			bitmap = new Bitmap(UPIPELDBMP, this);
			collider = new Collider(this, 0, 0);
			break;
		}
		// 3 - ���� �ϴ�
		case 3:
		{
			bitmap = new Bitmap(UPIPERDBMP, this);
			collider = new Collider(this, 0, 0);
			break;
		}
		default:
		{
			// �⺻�����δ� �μ����� �ʴ� ��
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
