#include "Framework.h"
#include "Monster_Move.h"

Monster_Move::Monster_Move(GameObject* gameObject)
	:MonoBehavior(gameObject), speed(50), is_Right(true)
{
	gameObject->isView = false;
	state = 0;
}

Monster_Move::~Monster_Move()
{
}

void Monster_Move::OnCollide(Collider* other)
{

	if (other->gameObject->name == "Mario" && state == 0 )
	{
		if (dynamic_cast<Mario*>(other->gameObject)->marioLevel == 0)
		{
			if (other->gameObject->position[1] < gameObject->position[1] - 5)
			{
				StartX = gameObject->position[0];
				StartY = gameObject->position[1];
				state = 1;
				gameObject->collider->isTrigger = true;
				gameObject->animator->SetAnimation(1);
				GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::Stomp);
				//Á×À½.
			}
			else
			{
				dynamic_cast<Mario*>(other->gameObject)->Life = false;

				//¸¶¸®¿À Á×À½.
			}
		}
		else if (dynamic_cast<Mario*>(other->gameObject)->marioLevel == 1)
		{
			if (other->gameObject->position[1] < gameObject->position[1]-32 - 5)
			{
				StartX = gameObject->position[0];
				StartY = gameObject->position[1];
				state = 1;
				gameObject->collider->isTrigger = true;
				gameObject->animator->SetAnimation(1);
				GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::Stomp);
				//Á×À½.
			}
			else
			{
				dynamic_cast<Mario*>(other->gameObject)->GetSmall();
				StartX = gameObject->position[0];
				StartY = gameObject->position[1];
				state = 1;
				gameObject->collider->isTrigger = true;
				gameObject->animator->SetAnimation(1);
				GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::Stomp);
				//¸¶¸®¿À Á×À½.
			}
		}

	}
}

void Monster_Move::Update()
{
	
	switch (state)
	{
	case 0://IDLE
		Move();
		break;

	case 1://DIE
		DIE();

		break;
	default:
		break;
	}
	

}

void Monster_Move::Move()
{
	
	gameObject->position[0] -= speed * TIME->Delta();


	
}
void Monster_Move::DIE()
{
	if (gameObject->position[1] <= WINDOW_SIZE_Y)
	{
		gameObject->position[1] = 0.06 * ((gameObject->position[0] - StartX) * (gameObject->position[0] - StartX - 50)) + StartY;
		gameObject->position[0] += 130 * Time::Get()->Delta();
	

	}
	else
	{
		gameObject->isView = false;
		//È­¸é ¹Û
	}
}