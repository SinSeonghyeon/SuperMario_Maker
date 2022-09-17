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
	float speed;//�� ���ǵ�
	EItem m_case; //���� ������
};

