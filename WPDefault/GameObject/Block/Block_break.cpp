#include "Framework.h"
#include "Block_break.h"
#include "Component/Collider.h"

Block_break::Block_break(GameObject* gameObject)
	:MonoBehavior(gameObject)
{
	
}

Block_break::~Block_break()
{

}

void Block_break::Update()
{
	
}

void Block_break::FixedUpdate()
{
	if (IsTouched)
	{
		BlockUpdown();
	}
}

void Block_break::OnCollide(Collider* other)
{
	if (other->gameObject->tag == "Mario")
	{
		if (gameObject->WorldPos()[1] <= other->gameObject->WorldPos()[1] && gameObject->WorldPos()[0] - BLOCK_HIT_RANGE < other->gameObject->WorldPos()[0] && gameObject->WorldPos()[0] + 5 > other->gameObject->WorldPos()[0])
		{
			if (dynamic_cast<Mario*>(other->gameObject)->marioLevel > 0)
			{
				DebugPrint("Box CollisionDetected");
				Break();
			}
			else if(ColDillay == false)
			{
				origin_y = gameObject->position[1];
				DebugPrint("Box Up");
				IsTouched = true;
				ColDillay = true;
			}
			
		}
	}
}

void Block_break::Break()
{
	

	GameManager::GetInstance()->m_ParticleManager.Play(gameObject->WorldPos()[0], gameObject->WorldPos()[1]);
	gameObject->position[1] = 3500;
}

void Block_break::BlockUpdown()
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