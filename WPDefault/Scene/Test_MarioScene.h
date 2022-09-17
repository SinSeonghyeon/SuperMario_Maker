#pragma once
#include "GameObject/TestCollider/TestCollider.h"
#include "GameObject/Block/BreakableBlock.h"
#include "GameObject/Block/UnbreakableBlock.h"

class Test_MarioScene : public Scene
{
public:
	Test_MarioScene();
	~Test_MarioScene();


	// Scene을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;
private:
	Mario* mario;
	UnbreakableBlock* ub_block;
	BreakableBlock* b_block;
	TestCollider* floor;
	TestCollider* test;

};