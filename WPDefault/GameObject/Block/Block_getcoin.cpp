#include "Framework.h"
#include "Block_getcoin.h"
#include "Component/Collider.h"
#include "CoinBlock.h"

Block_getcoin::Block_getcoin(GameObject* gameObject)
	:MonoBehavior(gameObject)
{

}

Block_getcoin::~Block_getcoin()
{

}

void Block_getcoin::Update()
{

}

void Block_getcoin::FixedUpdate()
{
	if (IsTouched)
	{
		BlockUpdown();
	}
}

void Block_getcoin::OnCollide(Collider* other)
{
	if (other->gameObject->tag == "Mario" && gameObject->WorldPos()[1] < other->gameObject->WorldPos()[1] && gameObject->WorldPos()[0] - BLOCK_HIT_RANGE < other->gameObject->WorldPos()[0] && gameObject->WorldPos()[0] + BLOCK_HIT_RANGE > other->gameObject->WorldPos()[0]&&!IsEmpty)
	{
		IsEmpty = true;
		origin_y = gameObject->position[1];
		DebugPrint("Box CollisionDetected");
		GetCoin();
	}
}

void Block_getcoin::GetCoin()
{
	GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::Coin);
	gameObject->animator->SetAnimation(CoinBlock::STATE::EMPTY);
	GameManager::GetInstance()->m_ParticleManager.CoinPlay(gameObject->WorldPos()[0], gameObject->WorldPos()[1]);
	IsTouched = true;
	GameManager::GetInstance()->m_Coin += 1;
	GameManager::GetInstance()->m_Score += 10;
}

void Block_getcoin::BlockUpdown()
{
	if (upcheck == 0)
	{
		gameObject->position[1] -= BLOCK_UP_AMOUNT;
		upcheck = BLOCK_UP_LIMIT;
	}
	else if (upcheck <= BLOCK_UP_LIMIT/2 + 1)
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