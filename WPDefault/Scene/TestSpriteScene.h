#pragma once
#include "GameObject/TestCollider/TestCollider.h"
#include "GameObject/Block/UnbreakableBlock.h"

class TestSpriteScene : public Scene
{
public:
	TestSpriteScene();
	~TestSpriteScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	Bitmap* bitmap;
	UnbreakableBlock* unbreakableBlock;
	TestCollider* col;
};
