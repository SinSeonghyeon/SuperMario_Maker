#include "Framework.h"
#include "GameObject/Item/ItemCheck.h"
ItemManager::ItemManager()
{
	InitItem();
}

ItemManager::~ItemManager()
{
}

void ItemManager::InitItem()
{

	if (m_Item[(int)EItem::Mushroom] == nullptr)
	{
		m_Item[(int)EItem::Mushroom] = new Item(IDB_Mushroom, EItem::Mushroom);
		m_Item[(int)EItem::lifeMushroom] = new Item(IDB_LifeUpMushroom, EItem::lifeMushroom);
		m_Item[(int)EItem::Star] = new Item(IDB_Star0, EItem::Star);
		m_Item[(int)EItem::Coin] = new Item(IDB_Star0, EItem::Coin);
		m_Item[(int)EItem::Flower] = new Item(IDB_Star0, EItem::Flower);

		vector<Bitmap*> Anim;
		Anim.push_back(new Bitmap(IDB_Star0));
		Anim.push_back(new Bitmap(IDB_Star1));
		Anim.push_back(new Bitmap(IDB_Star2));
		Anim.push_back(new Bitmap(IDB_Star3));
		Star = new Animation(m_Item[(int)EItem::Star], Anim);
		m_Item[(int)EItem::Star]->animator = new Animator(m_Item[(int)EItem::Star]);
		m_Item[(int)EItem::Star]->animator->SetAnimation(0);
		m_Item[(int)EItem::Star]->animator->AddAnimation(0, Star);

		vector<Bitmap*> AnimCoin;
		AnimCoin.push_back(new Bitmap(IDB_COIN0));
		AnimCoin.push_back(new Bitmap(IDB_COIN1));
		AnimCoin.push_back(new Bitmap(IDB_COIN2));
		AnimCoin.push_back(new Bitmap(IDB_COIN3));
		Coin = new Animation(m_Item[(int)EItem::Coin], AnimCoin);
		m_Item[(int)EItem::Coin]->animator = new Animator(m_Item[(int)EItem::Coin]);
		m_Item[(int)EItem::Coin]->animator->SetAnimation(0);
		m_Item[(int)EItem::Coin]->animator->AddAnimation(0, Coin);

		vector<Bitmap*> AnimFlower;
		AnimFlower.push_back(new Bitmap(IDB_FLOWER0));
		AnimFlower.push_back(new Bitmap(IDB_FLOWER1));
		AnimFlower.push_back(new Bitmap(IDB_FLOWER2));
		AnimFlower.push_back(new Bitmap(IDB_FLOWER3));
		Flower = new Animation(m_Item[(int)EItem::Flower], AnimFlower);
		m_Item[(int)EItem::Flower]->animator = new Animator(m_Item[(int)EItem::Flower]);
		m_Item[(int)EItem::Flower]->animator->SetAnimation(0);
		m_Item[(int)EItem::Flower]->animator->AddAnimation(0, Flower);
	}

}

void ItemManager::CreateItem(int x, int y, EItem _item)
{
	if (EItem::Coin == _item)
	{
		Item* CreateCoin = new Item(IDB_COIN0, EItem::Coin);

		vector<Bitmap*> AnimCoin;
		AnimCoin.push_back(new Bitmap(IDB_COIN0));
		AnimCoin.push_back(new Bitmap(IDB_COIN1));
		AnimCoin.push_back(new Bitmap(IDB_COIN2));
		AnimCoin.push_back(new Bitmap(IDB_COIN3));
		Animation* _Coin = new Animation(CreateCoin, AnimCoin);


		CreateCoin->animator = new Animator(CreateCoin);
		CreateCoin->animator->SetAnimation(0);
		CreateCoin->animator->AddAnimation(0, _Coin);

		CreateCoin->position[0] = x;
		CreateCoin->position[1] = y;
		CreateCoin->isCulling = true;
		CreateCoin->m_ItemCheck->Create();

		m_Coin.push_back(CreateCoin);

		CreateCoin->Init();
		CreateCoin->UpdateWorld();

		return;

	}
	m_Item[(int)_item]->position[0] = x;
	m_Item[(int)_item]->position[1] = y;
	m_Item[(int)_item]->isCulling = true;
	InitItem();
	m_Item[(int)_item]->m_ItemCheck->Create();
}
void ItemManager::DeleteItem(Item* _item)
{
	_item->position[0] = -1000;
	_item->position[1] = -1000;
	_item->Update();
	_item->isCulling = false;
	
}

void ItemManager::DeleteItem()
{
	list<Item*>::iterator iter;
	for (iter = m_Coin.begin(); iter != m_Coin.end(); iter++)
	{
		delete (*iter);
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		delete m_Item[i];
		m_Item[i] = nullptr;
	}

	m_Coin.clear();
}

void ItemManager::Update()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (m_Item[i]->isCulling)
			m_Item[i]->Update();
	}
	list<Item*>::iterator iter;
	for (iter = m_Coin.begin(); iter != m_Coin.end(); iter++)
	{
		if ((*iter)->isCulling)
			(*iter)->Update();
	}

}

void ItemManager::Render()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (m_Item[i]->isCulling)
			m_Item[i]->Render();
	}
	list<Item*>::iterator iter;
	for (iter = m_Coin.begin(); iter != m_Coin.end(); iter++)
	{
		if ((*iter)->isCulling)
			(*iter)->Render();
	}
}
