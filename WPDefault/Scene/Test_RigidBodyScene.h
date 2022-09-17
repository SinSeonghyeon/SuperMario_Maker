#pragma once
#include "GameObject/TestCollider/TestCollider.h"
#include "GameObject/TestRect/TestRect.h"
#include "GameObject/Mario/Mario.h"
#include "GameObject/Block/UnbreakableBlock.h"
#include "GameObject/Block/BreakableBlock.h"
#include "GameObject/Block/CoinBlock.h"
#include "GameObject/Block/FakeCoinBlock.h"

class Test_RigidBodyScene : public Scene
{
public:
	Test_RigidBodyScene();
	~Test_RigidBodyScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
private:
	Bitmap* bitmap;
	Mario* mario;
	UnbreakableBlock* ub_Block;
	BreakableBlock* b_Block;
	CoinBlock* c_Block;
	FakeCoinBlock* fc_Block;
	MushroomBlock* mr_Block;
	TestRect* testRect;
	TestCollider* col;
};