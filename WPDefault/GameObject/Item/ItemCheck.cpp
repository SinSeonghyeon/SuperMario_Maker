#include "Framework.h"
#include "ItemCheck.h"

ItemCheck::ItemCheck(Item* Item, EItem _case) :MonoBehavior(gameObject)
{
	m_Item = Item;
	m_case = _case;
	m_Item->rigidBody->gravity = 0;
	speed = 100;
	Time = 0;
	m_Item->collider->isTrigger = true;
}

ItemCheck::~ItemCheck()
{

}


void ItemCheck::Update()
{
	Move();

}


//������ �Ҹ� ���
void ItemCheck::OnCollide(Collider* other)
{

	if (other->gameObject->name == "Mario" && Time >= 0.4f)
	{
		switch (m_case)
		{
		case EItem::Mushroom:
		if (dynamic_cast<Mario*>(other->gameObject)->marioLevel == 0)
			dynamic_cast<Mario*>(other->gameObject)->GetBig();
			GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::PowerUp);
			break;
		case EItem::lifeMushroom:
			GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::lifeUp);
			break;
		case EItem::Star:
			GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::Coin);
			break;
		case EItem::Coin:
			
			GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::Coin);
			GameManager::GetInstance()->m_Coin += 1;
			
			//������ delete �߰� ����.
			break;
		case EItem::Flower:
			GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::PowerUp);
			break;
		default:
			break;
		}
		GameManager::GetInstance()->m_Score += 10;
		GameManager::GetInstance()->m_ItemManager.DeleteItem(m_Item);
		if (EItem::Coin == m_case)
		{
			delete gameObject;
		}


	}
	else if (m_Item->collider->isTrigger == false && m_case == EItem::Star)
	{
		float a[2] = { 0.0f, -1.0f };
		m_Item->rigidBody->AddForce(1500.0f, a);
	}
}
//�Ҹ����� ����
void ItemCheck::MuteCreate()
{
	m_Item->collider->isTrigger = true;
	m_Item->rigidBody->gravity = 0;
	Time = 0;
}

//�����ϸ鼭 �Ҹ� ���
void ItemCheck::Create()
{
	if (m_case != EItem::Coin)
		GameManager::GetInstance()->m_SoundManager.EPlaysound(ESoundTrack::PowerUp2);

	m_Item->collider->isTrigger = true;
	m_Item->rigidBody->gravity = 0;
	Time = 0;
}

//���� �� �ൿ
void ItemCheck::Move()
{
	if (Time <= 0.4f)
	{
		Time += 1 * TIME->Delta();

		if (m_case != EItem::Coin)
			m_Item->position[1] -= speed * TIME->Delta();
	}
	else
	{

		switch (m_case)
		{
		case EItem::Mushroom:
		case EItem::lifeMushroom:
			m_Item->collider->isTrigger = false;
			m_Item->rigidBody->gravity = 500;
			m_Item->position[0] += speed * TIME->Delta();
			break;
		case EItem::Star:
			m_Item->collider->isTrigger = false;
			m_Item->rigidBody->gravity = 300;
			m_Item->position[0] += speed * 2 * TIME->Delta();

			break;
		case EItem::Coin:
		case EItem::Flower:
			m_Item->collider->isTrigger = true;
			break;
		default:
			break;
		}
	}


}


