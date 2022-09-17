#include "Framework.h"
#include "Block_spawnmushroom.h"
#include "Component/Collider.h"
#include "MushroomBlock.h"

Block_spawnmushroom::Block_spawnmushroom(GameObject* gameObject)
	:MonoBehavior(gameObject)
{
	
}

Block_spawnmushroom::~Block_spawnmushroom()
{

}

void Block_spawnmushroom::Update()
{

}

void Block_spawnmushroom::FixedUpdate()
{
	if (IsTouched)
	{
		BlockUpdown();
	}
}

void Block_spawnmushroom::OnCollide(Collider* other)
{
	if (other->gameObject->tag == "Mario" && gameObject->WorldPos()[1] < other->gameObject->WorldPos()[1] && gameObject->WorldPos()[0] - BLOCK_HIT_RANGE < other->gameObject->WorldPos()[0] && gameObject->WorldPos()[0] + BLOCK_HIT_RANGE > other->gameObject->WorldPos()[0] && !IsEmpty)
	{
		IsEmpty = true;
		origin_y = gameObject->position[1];
		DebugPrint("Box CollisionDetected");
		SpawnMushroom();
	}
}

void Block_spawnmushroom::SpawnMushroom()
{
	//ÁÂÇ¥°¡ ¹®Á¦
	GameManager::GetInstance()->m_ItemManager.CreateItem((int)gameObject->position[0], (int)gameObject->position[1], EItem::Mushroom);
	gameObject->animator->SetAnimation(CoinBlock::STATE::EMPTY);
	IsTouched = true;
	GameManager::GetInstance()->m_Score += 10;
}

void Block_spawnmushroom::BlockUpdown()
{
	if (upcheck == 0)
	{
		gameObject->position[1] -= BLOCK_UP_AMOUNT;
		upcheck = BLOCK_UP_LIMIT;
	}
	else if (upcheck <= BLOCK_UP_LIMIT / 2 + 1)
	{
		gameObject->position[1] += BLOCK_UP_AMOUNT;
		upcheck -= BLOCK_UP_AMOUNT;
		if (upcheck <= BLOCK_UP_AMOUNT)
		{
			IsTouched = false;
			gameObject->position[1] = origin_y;
		}
	}
	else
	{
		gameObject->position[1] -= BLOCK_UP_AMOUNT;
		upcheck -= BLOCK_UP_AMOUNT;
	}
}