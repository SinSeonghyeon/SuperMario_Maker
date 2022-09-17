#pragma once

class Block_getcoinFake : public MonoBehavior
{
public:
	Block_getcoinFake(GameObject* gameObject);
	~Block_getcoinFake();
	void GetCoin();
	void BlockUpdown();
	void BlockDisable();
	//void OnCollide(Collider* other);

private:
	bool IsTouched = false;
	bool IsTouchable = true;
	bool ColDillay = false;
	bool IsTimerStarted = false;
	int Timer = 0;
	int upcheck = 0;
	int touchcount = 0;
	double origin_y;

	friend class GameObjectManager;
	void OnCollide(Collider* other) override;
	void FixedUpdate() override;
	void Update() override;
};