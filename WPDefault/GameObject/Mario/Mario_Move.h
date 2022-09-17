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
	void Friction();//���� ����

	float accel;//���ӷ�
	float speed;//�� ���ǵ�
	float maxSpeed;//�ּ�
	float friction;//����, ����

	int jumpAddableInts;
	float jumpAddableTime;//�� «Ǫ �Է� ������ �ð�
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