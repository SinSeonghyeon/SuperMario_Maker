#include "Framework.h"
#include "TestRect.h"
#include "MB_TestRect.h"

TestRect::TestRect()
	:GameObject("TestRect")
{
	collider = new Collider(this,50,50, Rect);
	rigidBody = new RigidBody(this);

	monoBehaviors.push_back(new MB_TestRect(this));

	Init();
}

TestRect::~TestRect()
{
	delete rigidBody;
	delete collider;
}

void TestRect::Update()
{
	UpdateWorld();
	collider->Update();
	rigidBody->Update();
}

void TestRect::Render()
{
	collider->Render();
}
