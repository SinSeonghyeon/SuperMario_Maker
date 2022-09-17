#pragma once

class Block_spawnmushroom : public MonoBehavior
{
public:
	Block_spawnmushroom(GameObject* gameObject);
	~Block_spawnmushroom();
	void SpawnMushroom();
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
