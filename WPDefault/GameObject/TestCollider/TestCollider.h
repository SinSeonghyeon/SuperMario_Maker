#pragma once

class TestCollider : public GameObject
{
public:
	TestCollider(POINT position, POINT size = { 32,32 });
	~TestCollider();
	// GameObject��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
};