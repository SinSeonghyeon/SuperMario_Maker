#pragma once

class Block_getcoin : public MonoBehavior
{
public:
	Block_getcoin(GameObject* gameObject);
	~Block_getcoin();
	void GetCoin();
	void BlockUpdown();
	//void OnCollide(Collider* other);

private:
	bool IsEmpty = false;
	bool IsTouched = false;
	int upcheck = 0;
	double origin_y;

	friend class GameObjectManager;
	void OnCollide(Collider* other) override;
	void FixedUpdate() override;
	void Update() override;
};