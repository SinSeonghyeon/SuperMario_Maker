#include "Framework.h"
void MonsterManager::CreateMonster(int i, float x, float y) // 0 = ±À¹Ù    .   1  == °ÅºÏÀÌ
{
	if (i == 0)
	{
		Goomba.push_back(new Monster(x, y));
	}
	else if (i == 1)
	{

		_Tutle.push_back(new Tutle(x, y));

	}
	else
	{

	}


}

void MonsterManager::DeleteMonsert()
{

	list<Tutle*>::iterator iter;
	for (iter = _Tutle.begin(); iter != _Tutle.end(); iter++)
	{
		delete (*iter);
	}

	list<Monster*>::iterator iter2;

	for (iter2 = Goomba.begin(); iter2 != Goomba.end(); iter2++)
	{
		delete (*iter2);
	}

	_Tutle.clear();
	Goomba.clear();
}

void MonsterManager::Update()
{
	list<Tutle*>::iterator iter;
	for (iter = _Tutle.begin(); iter != _Tutle.end(); iter++)
	{
		if ((*iter)->isView)
			(*iter)->Update();
	}

	list<Monster*>::iterator iter2;

	for (iter2 = Goomba.begin(); iter2 != Goomba.end(); iter2++)
	{
		if ((*iter2)->isView)
			(*iter2)->Update();
	}
}

void MonsterManager::Render()
{
	list<Tutle*>::iterator iter;

	for (iter = _Tutle.begin(); iter != _Tutle.end(); iter++)
	{
		if ((*iter)->isView)
			(*iter)->Render();
	}

	list<Monster*>::iterator iter2;

	for (iter2 = Goomba.begin(); iter2 != Goomba.end(); iter2++)
	{
		if ((*iter2)->isView)
			(*iter2)->Render();
	}


}