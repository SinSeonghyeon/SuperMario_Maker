#pragma once
#include "list"
#define MAX_SIZE 5

enum class EItem
{
	Mushroom,
	lifeMushroom,
	Star,
	Flower,
	Coin,
};
class ItemManager
{
	Item* m_Item[MAX_SIZE];
	list<Item*>m_Coin;
	Animation* Star;
	Animation* Coin;
	Animation* Flower;
	

public:
	ItemManager();
	~ItemManager();
	void InitItem();

	void CreateItem(int x, int y, EItem _item);

	void DeleteItem(Item* _item);
	void DeleteItem();
	void Update();
	void Render();

};

