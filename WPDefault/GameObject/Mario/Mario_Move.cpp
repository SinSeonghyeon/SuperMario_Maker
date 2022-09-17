#include "Framework.h"
#include "Mario_Move.h"

Mario_Move::Mario_Move(GameObject* gameObject)
	:MonoBehavior(gameObject), accel(2500.0f), speed(0), maxSpeed(500.0f), friction(1600.0f),
	jumpAddableTime(0.15f), timer(0.0f), jumpAddableInts(0), is_Right(true)
{
	gameObject->rigidBody->gravity = 500.0f;
}

Mario_Move::~Mario_Move()
{
}

void Mario_Move::FixedUpdate()
{
}

void Mario_Move::Update()
{
	Move();
	Jump();
	Friction();



	if (!gameObject->rigidBody->isOnAir)
	{
		if (speed == 0.0f)
		{
			if (temp->marioLevel == 0)
			{
				gameObject->animator->SetAnimation(Mario::STATE::SMALL_IDLE + 6 * is_Right);
			}
			else if (temp->marioLevel == 1)
			{
				gameObject->animator->SetAnimation(Mario::STATE::BIG_IDLE + 6 * is_Right);
			}
			else
			{
				//gameObject->animator->SetAnimation(Mario::STATE::SMALL_IDLE + 6 * is_Right);
			}
		}
		else
		{
			if (KEYBOARD->Press('A') && speed >= 0)
			{
				if (temp->marioLevel == 0)
				{
					gameObject->animator->SetAnimation(Mario::STATE::SMALL_HESITATE);
				}
				else if (temp->marioLevel == 1)
				{
					gameObject->animator->SetAnimation(Mario::STATE::BIG_HESITATE);
				}
				else
				{

				}
			}
			else if (KEYBOARD->Press('D') && speed <= 0)
			{
				if (temp->marioLevel == 0)
				{
					gameObject->animator->SetAnimation(Mario::STATE::SMALL_R_HESITATE);
				}
				else if (temp->marioLevel == 1)
				{
					gameObject->animator->SetAnimation(Mario::STATE::BIG_R_HESITATE);
				}
				else
				{

				}
			}
			else
			{
				if (temp->marioLevel == 0)
				{
					gameObject->animator->SetAnimation(Mario::STATE::SMALL_RUN + 6 * is_Right);
				}
				else if (temp->marioLevel == 1)
				{
					gameObject->animator->SetAnimation(Mario::STATE::BIG_RUN + 6 * is_Right);
				}
				else
				{

				}
			}
				
		}
	}
	else
	{
		if (temp->marioLevel == 0)
		{
			gameObject->animator->SetAnimation(Mario::STATE::SMALL_JUMP + 6 * is_Right);
		}
		else if (temp->marioLevel == 1)
		{
			gameObject->animator->SetAnimation(Mario::STATE::BIG_JUMP + 6 * is_Right);
		}
		else
		{

		}
	}

}

void Mario_Move::OnCollide(Collider* other)
{



}

void Mario_Move::Move()
{
	if (KEYBOARD->Press('A'))
	{
		is_Right = false;
		speed -= accel * TIME->Delta();
	}
	if (KEYBOARD->Press('D'))
	{
		is_Right = true;
		speed += accel * TIME->Delta();
	}

	if (speed > maxSpeed)
		speed = maxSpeed;
	if (speed < -maxSpeed)
		speed = -maxSpeed;

	gameObject->position[0] += speed * TIME->Delta();
}

void Mario_Move::Jump()
{
	if ((KEYBOARD->Down('W') && !gameObject->rigidBody->isOnAir) || (KEYBOARD->Down(VK_SPACE) && !gameObject->rigidBody->isOnAir))//테스트 용
	{
		float a[2] = { 0.0f, -1.0f };
		gameObject->rigidBody->AddForce(1000.0f, a);

		gameObject->UpdateWorld();
		//gameObject->position = { 0,0 };
	}

	if (KEYBOARD->Press(VK_SPACE)|| KEYBOARD->Press('W'))//테스트 용
	{ 
     	timer += TIME->Delta();
		if (timer < jumpAddableTime)
		{
			float a[2] = { 0.0f, -1.0f };
			gameObject->rigidBody->AddForce(8000.0f * TIME->Delta(), a);
		}
		//gameObject->position = { 0,0 };
	}


	if (!gameObject->rigidBody->isOnAir)
	{
  		timer = 0.0f;
	}
}

void Mario_Move::Friction()
{
	if (gameObject->rigidBody->isOnAir) return;

	if (speed > 2.0f)
	{
		speed -= friction * TIME->Delta();
	}
	else if (speed < -2.0f)
	{
		speed += friction * TIME->Delta();
	}
	else
	{
		speed = 0.0f;
	}

}
