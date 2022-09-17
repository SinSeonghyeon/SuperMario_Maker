#pragma once

class Collider;

class ItemCheck: public MonoBehavior
{
public:
	ItemCheck(Item* Item, EItem _case);
	~ItemCheck();
	void Create();
private:
	void Update() override;
	void OnCollide(Collider* other) override;

	void MuteCreate();
	
	void Move();
	Item* m_Item;
	float Time;
	float speed;//현 스피드
	EItem m_case; //무슨 아이템
};

