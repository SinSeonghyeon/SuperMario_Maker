#include "Framework.h"
#include "0_GameObjectManager.h"

GameObjectManager* GameObjectManager::instance = nullptr;

GameObjectManager::GameObjectManager()
	:one(nullptr) , two(nullptr)
{
}

GameObjectManager::~GameObjectManager()
{
}

void GameObjectManager::Update()
{
	UpdateCollisionInfos();
	UpdateMonobehaviors();

	for (GameObject* gameObject : allGameObjects)
	{
		//if (gameObject->isActive)
		{
			gameObject->Update();

			for (MonoBehavior* monoBehavior : gameObject->monoBehaviors)
			{
				monoBehavior->Update();
				monoBehavior->FixedUpdate();
			}
		}
	}

	//todo: UpdateWorld 여기서
}

void GameObjectManager::CollidePush(Collider* a, Collider* b, Direction dir, int diff)
{
	if (dir == Down)
	{
		a->gameObject->position[1] = (int)(a->gameObject->position[1] - diff);

	}
	else if (dir == Up)
	{
		a->gameObject->position[1] = (int)(a->gameObject->position[1] + diff);
	}
	else if (dir == Right)
	{
		a->gameObject->position[0] = (int)(a->gameObject->position[0] - diff);
	}
	else if (dir == Left)
	{
		a->gameObject->position[0] = (int)(a->gameObject->position[0] + diff);
	}

	a->gameObject->UpdateWorld();

	if (a->gameObject->collider != nullptr)
		a->gameObject->collider->UpdateWorld();
	if (a->gameObject->animator != nullptr)
		a->gameObject->animator->Update();
	if (a->gameObject->image != nullptr)
		a->gameObject->image->UpdateWorld();
}

void GameObjectManager::ClipToFloor(Collider* a, int diff)
{
}

void GameObjectManager::UpdateCollisionInfos()
{
	for (GameObject* rigidee : allRigidBodies)
	{
		if ((rigidee->tag != "cam") && !rigidee->isActive) continue;

		rigidee->rigidBody->isOnAir = true;
		for (GameObject* other : allGameObjects)
		{
			if ((rigidee->tag != "cam") && !other->isActive) continue;
			if (rigidee == other) continue;

			Direction dir = Direction::Down;
			int diff = 0;


			if (rigidee->collider->CheckCollider(other->collider, &dir, &diff))
			{

				if (dir == Direction::Down && !rigidee->collider->isTrigger && !other->collider->isTrigger)//물리적으로 밀어주는 곳
				{
					CollidePush(rigidee->collider, other->collider, Direction::Down, diff);
					rigidee->rigidBody->isOnAir = false;
				}
			}
		}
	}

	for (GameObject* rigidee : allRigidBodies)
	{
		if ((rigidee->tag != "cam") && !rigidee->isActive) continue;

		for (GameObject* other : allGameObjects)
		{
			if ((rigidee->tag != "cam") && !other->isActive) continue;


			if (rigidee == other) continue;

			Direction dir = Direction::Down;
			int diff = 0;

			//collideManager[make_pair(rigidee,other)].first = old, 전 프레임에서 충돌이 됐는지
			//collideManager[make_pair(rigidee, other)].second = new, 이번 프레임에서 충돌이 됐는지
			collideManager[make_pair(rigidee, other)].first =
				collideManager[make_pair(rigidee, other)].second;//과거의 충돌여부 갱신

			if (rigidee->collider->CheckCollider(other->collider, &dir, &diff))
			{
				collideManager[make_pair(rigidee, other)].second = true;//이번 프레임의 충돌여부 갱신

				if (dir != Direction::Down && !rigidee->collider->isTrigger && !other->collider->isTrigger)//물리적으로 밀어주는 곳
					CollidePush(rigidee->collider, other->collider, dir, diff);
			}
			else
				collideManager[make_pair(rigidee, other)].second = false;
		}
	}
}

void GameObjectManager::UpdateMonobehaviors()
{

	for (const auto& managees : collideManager)
	{
		GameObject* a = managees.first.first;
		GameObject* b = managees.first.second;

		if ((a->tag != "cam") && (!a->isActive || !b->isActive)) continue;

		const bool bOld = collideManager[make_pair(a, b)].first;
		const bool bNew = collideManager[make_pair(a, b)].second;

		//a의 함수 호출
		if (bOld == false && bNew == true)//EnterTrigger, OnCollide
		{
			if (b->collider->isTrigger)//충돌 대상이 트리거라면
			{
				for (MonoBehavior* mB : a->monoBehaviors)
				{
					mB->EnterTrigger(b->collider);
				}
			}
			else//트리거가 아니라면
			{
				for (MonoBehavior* mB : a->monoBehaviors)
				{
					mB->OnCollide(b->collider);
				}
			}

		}
		else if (bOld == true && bNew == true)//StayTrigger
		{
			if (b->collider->isTrigger)//충돌 대상이 트리거라면
			{
				for (MonoBehavior* mB : a->monoBehaviors)
				{
					mB->StayTrigger(b->collider);
				}
			}
			else
			{
				for (MonoBehavior* mB : a->monoBehaviors)
				{
					mB->StayCollide(b->collider);
				}
			}
		}
		else if (bOld == true && bNew == false)//ExitTrigger
		{
			if (b->collider->isTrigger)//충돌 대상이 트리거라면
			{
				for (MonoBehavior* mB : a->monoBehaviors)
				{
					mB->ExitTrigger(b->collider);
				}
			}
			else
			{
				for (MonoBehavior* mB : a->monoBehaviors)
				{
					mB->ExitCollide(b->collider);
				}
			}
		}
		//b의 함수 호출
		if (b->rigidBody) continue;
		if (bOld == false && bNew == true)//EnterTrigger, OnCollide
		{
			if (a->collider->isTrigger)//충돌 대상이 트리거라면
			{
				for (MonoBehavior* mB : b->monoBehaviors)
				{
					mB->EnterTrigger(a->collider);
				}
			}
			else//트리거가 아니라면
			{
				for (MonoBehavior* mB : b->monoBehaviors)
				{
					mB->OnCollide(a->collider);
				}
			}

		}
		else if (bOld == true && bNew == true)//StayTrigger
		{
			if (a->collider->isTrigger)//충돌 대상이 트리거라면
			{
				for (MonoBehavior* mB : b->monoBehaviors)
				{
					mB->StayTrigger(a->collider);
				}
			}
			else
			{
				for (MonoBehavior* mB : b->monoBehaviors)
				{
					mB->StayCollide(a->collider);
				}
			}
		}
		else if (bOld == true && bNew == false)//ExitTrigger
		{
			if (a->collider->isTrigger)//충돌 대상이 트리거라면
			{
				for (MonoBehavior* mB : b->monoBehaviors)
				{
					mB->ExitTrigger(a->collider);
				}
			}
			else
			{
				for (MonoBehavior* mB : b->monoBehaviors)
				{
					mB->ExitCollide(a->collider);
				}
			}
		}
	}
}

void GameObjectManager::Add(GameObject* gameObject)
{
	if (one == nullptr && gameObject->tag == "cam" && dynamic_cast<Camera*>(gameObject)->num == 0)
		one = gameObject;

	for (MonoBehavior* mB : gameObject->monoBehaviors)
	{
		mB->Start();
	}

	allGameObjects.insert(gameObject);

	for (GameObject* other : allRigidBodies)
	{
		if (gameObject->collider)//다른 오브젝트에 콜라이더가 있다면
		{
			collideManager.insert(map<pair<GameObject*, GameObject*>, pair<bool, bool>>::value_type
			(make_pair(other, gameObject), make_pair(false, false)));
			//== colliderManager[make_pair(other, gameObject)] = make_pair(false,false);
		}
	}

	if (gameObject->rigidBody)//리짓 바디가 있으면
	{
		allRigidBodies.insert(gameObject);
		for (GameObject* other : allGameObjects)
		{
			if (other == gameObject) continue;

			if (other->collider)//다른 오브젝트에 콜라이더가 있다면
			{
				collideManager.insert(map<pair<GameObject*, GameObject*>, pair<bool, bool>>::value_type
				(make_pair(gameObject, other), make_pair(false, false)));
				//== colliderManager[make_pair(gameObject, other)] = make_pair(false,false);
			}
		}
	}
}

void GameObjectManager::Sub(GameObject* gameObject)
{
	//allRigidBodies, allGameObjects, collideManager에서 gameObject가 포함된 원소들을 제거한다.

		allGameObjects.erase(gameObject);

	if (gameObject->rigidBody)
	{
		allRigidBodies.erase(gameObject);

		for (GameObject* other : allGameObjects)
		{
			collideManager.erase(make_pair(gameObject, other));
		}
	}

	for (GameObject* other : allRigidBodies)
	{
		collideManager.erase(make_pair(other, gameObject));
	}


}

void GameObjectManager::Clear()
{
	allGameObjects.clear();
	allRigidBodies.clear();
	collideManager.clear();

	allGameObjects.insert(one);
	allRigidBodies.insert(one);
}
