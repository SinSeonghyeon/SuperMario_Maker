#include "Framework.h"
#include "Block_getcoinFake.h"
#include "Component/Collider.h"
#include "FakeCoinBlock.h"

Block_getcoinFake::Block_getcoinFake(GameObject* gameObject)
	:MonoBehavior(gameObject)
{

}

Block_getcoinFake::~Block_getcoinFake()
{

}

void Block_getcoinFake::Update()
{

}

void Block_getcoinFake::FixedUpdate()
{
	if (IsTouched)
	{
		BlockUpdown();
	}
	if (IsTimerStarted)
	{
		Timer++;
		if (Timer > 150)
		{
			touchcount = 11;
		}
	}
}

void Block_getcoinFake::OnCollide(Collider* other)
{
	if (other->gameObject->tag == "Mario" && gameObject->WorldPos()[1] < other->gameObject->WorldPos()[1] && gameObject->WorldPos()[0] - BLOCK_HIT_RANGE < other->gameObject->WorldPos()[0] && gameObject->WorldPos()[0] + BLOCK_HIT_RANGE > other->gameObject->WorldPos()[0] && IsTouchable && !ColDillay)
	{
		IsTimerStarted = true;
		Timer = 0;

		ColDillay = true;
		origin_y = gameObject->position[1];
		DebugPrint("Box CollisionDetected");
		GetCoin();
		touchcount += 1;
		upcheck = 0;
		if ( touchcount >= 12 )
		{
			BlockDisable();
		}
	}
}

void Block_getcoinFake::GetCoin()
{
	GameManager::GetInstance()->m_ParticleManager.CoinPlay(gameObject->WorldPos()[0], gameObject->WorldPos()[1]);
	GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::Coin);
	IsTouched = true;
	GameManager::GetInstance()->m_Coin += 1;
	GameManager::GetInstance()->m_Score += 10;
}

void Block_getcoinFake::BlockUpdown()
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
			ColDillay = false;
			gameObject->position[1] = origin_y;
		}
	}
	else
	{
		gameObject->position[1] -= BLOCK_UP_AMOUNT;
		upcheck -= BLOCK_UP_AMOUNT;
	}
}

void Block_getcoinFake::BlockDisable()
{
	IsTouchable = false;

	FakeCoinBlock* temp = dynamic_cast<FakeCoinBlock*>(gameObject);

	temp->BlockDisable();
}