#pragma once

class TestCollider : public GameObject
{
public:
	TestCollider(POINT position, POINT size = { 32,32 });
	~TestCollider();
	// GameObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
};