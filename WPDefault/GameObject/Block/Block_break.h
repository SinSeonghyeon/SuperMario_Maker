#pragma once

class Block_break : public MonoBehavior
{
public:
	Block_break(GameObject* gameObject);
	~Block_break();
	void Break();
	void BlockUpdown();
	//void OnCollide(Collider* other);

private:
	friend class GameObjectManager;
	void OnCollide(Collider* other) override;
	void Update() override;
	void FixedUpdate();

	bool IsTouched = false;
	bool ColDillay = false;
	int upcheck = 0;
	double origin_y;
};