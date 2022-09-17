#pragma once
class ColliderTestScene : public Scene
{
public:
	ColliderTestScene();
	~ColliderTestScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	class TestRect* rect;
	class TestRect* other;
	class TestRect* theOther;
};