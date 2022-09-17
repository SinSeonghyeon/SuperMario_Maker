#pragma once

class Mario_Move : public MonoBehavior
{
public:
	Mario_Move(GameObject* gameObject);
	~Mario_Move();

private:
	friend class GameObjectManager;
	void FixedUpdate() override;
	void Update() override;
	void OnCollide(Collider* other);
	void Move();
	void Jump();
	void Friction();//마찰 적용

	float accel;//가속력
	float speed;//현 스피드
	float maxSpeed;//최속
	float friction;//감속, 마찰

	int jumpAddableInts;
	float jumpAddableTime;//빅 짬푸 입력 가능한 시간
	float timer;

	//FakeCoinBlock* temp = dynamic_cast<FakeCoinBlock*>(gameObject);
	//temp->BlockDisable();

	bool is_Right;
	Mario* temp = dynamic_cast<Mario*>(gameObject);
};


//if (temp->marioLevel == 0)
//{
//	
//}
//else if (temp->marioLevel == 1)
//{
//
//}
//else
//{
//
//}