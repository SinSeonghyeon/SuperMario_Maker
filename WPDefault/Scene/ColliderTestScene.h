#pragma once
class ColliderTestScene : public Scene
{
public:
	ColliderTestScene();
	~ColliderTestScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	class TestRect* rect;
	class TestRect* other;
	class TestRect* theOther;
};