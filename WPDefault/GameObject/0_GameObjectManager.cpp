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

	//todo: UpdateWorld ���⼭
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

				if (dir == Direction::Down && !rigidee->collider->isTrigger && !other->collider->isTrigger)//���������� �о��ִ� ��
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

			//collideManager[make_pair(rigidee,other)].first = old, �� �����ӿ��� �浹�� �ƴ���
			//collideManager[make_pair(rigidee, other)].second = new, �̹� �����ӿ��� �浹�� �ƴ���
			collideManager[make_pair(rigidee, other)].first =
				collideManager[make_pair(rigidee, other)].second;//������ �浹���� ����

			if (rigidee->collider->CheckCollider(other->collider, &dir, &diff))
			{
				collideManager[make_pair(rigidee, other)].second = true;//�̹� �������� �浹���� ����

				if (dir != Direction::Down && !rigidee->collider->isTrigger && !other->collider->isTrigger)//���������� �о��ִ� ��
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

		//a�� �Լ� ȣ��
		if (bOld == false && bNew == true)//EnterTrigger, OnCollide
		{
			if (b->collider->isTrigger)//�浹 ����� Ʈ���Ŷ��
			{
				for (MonoBehavior* mB : a->monoBehaviors)
				{
					mB->EnterTrigger(b->collider);
				}
			}
			else//Ʈ���Ű� �ƴ϶��
			{
				for (MonoBehavior* mB : a->monoBehaviors)
				{
					mB->OnCollide(b->collider);
				}
			}

		}
		else if (bOld == true && bNew == true)//StayTrigger
		{
			if (b->collider->isTrigger)//�浹 ����� Ʈ���Ŷ��
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
			if (b->collider->isTrigger)//�浹 ����� Ʈ���Ŷ��
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
		//b�� �Լ� ȣ��
		if (b->rigidBody) continue;
		if (bOld == false && bNew == true)//EnterTrigger, OnCollide
		{
			if (a->collider->isTrigger)//�浹 ����� Ʈ���Ŷ��
			{
				for (MonoBehavior* mB : b->monoBehaviors)
				{
					mB->EnterTrigger(a->collider);
				}
			}
			else//Ʈ���Ű� �ƴ϶��
			{
				for (MonoBehavior* mB : b->monoBehaviors)
				{
					mB->OnCollide(a->collider);
				}
			}

		}
		else if (bOld == true && bNew == true)//StayTrigger
		{
			if (a->collider->isTrigger)//�浹 ����� Ʈ���Ŷ��
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
			if (a->collider->isTrigger)//�浹 ����� Ʈ���Ŷ��
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
		if (gameObject->collider)//�ٸ� ������Ʈ�� �ݶ��̴��� �ִٸ�
		{
			collideManager.insert(map<pair<GameObject*, GameObject*>, pair<bool, bool>>::value_type
			(make_pair(other, gameObject), make_pair(false, false)));
			//== colliderManager[make_pair(other, gameObject)] = make_pair(false,false);
		}
	}

	if (gameObject->rigidBody)//���� �ٵ� ������
	{
		allRigidBodies.insert(gameObject);
		for (GameObject* other : allGameObjects)
		{
			if (other == gameObject) continue;

			if (other->collider)//�ٸ� ������Ʈ�� �ݶ��̴��� �ִٸ�
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
	//allRigidBodies, allGameObjects, collideManager���� gameObject�� ���Ե� ���ҵ��� �����Ѵ�.

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
