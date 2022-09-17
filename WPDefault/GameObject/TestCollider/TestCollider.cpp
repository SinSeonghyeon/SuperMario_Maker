#include "Framework.h"
#include "TestCollider.h"

TestCollider::TestCollider(POINT position, POINT size)
	:GameObject("Floor")
{
	this->position[0] = position.x;
	this->position[1] = position.y;
	collider = new Collider(this, size.x, size.y);


	Init();
}

TestCollider::~TestCollider()
{
	delete collider;
}

void TestCollider::Update()
{
	collider->Update();
	UpdateWorld();
}

void TestCollider::Render()
{
	collider->Render();
}
