#pragma once
#include <list>
class Monster;
class Tutle;
class MonsterManager
{

	list<Monster*> Goomba;
	list<Tutle*> _Tutle;
public:
	
	void CreateMonster(int i, float x, float y);
	void DeleteMonsert();
	void Update();
	void Render();
	
};

