#pragma once

class Monster_Move : public MonoBehavior
{
public:
	Monster_Move(GameObject* gameObject);
	~Monster_Move();
	void OnCollide(Collider* other) override;
private:
	int StartX;
	int StartY;
	friend class GameObjectManager;
	int state;
	
	void Update() override;

	void Move();

	void DIE();
	
	float speed;//현 스피드


	bool is_Right;
};