#include "Framework.h"
#include "GameObject/Item/ItemCheck.h"

Item::Item(int _Image, EItem m_case) :GameObject("Item", "Item")
{
	position[1] = -100;
	
	
	image = new Bitmap(_Image, this);
	collider = new Collider(this, 28, 32);
	collider->position[0] += 2;
	rigidBody = new RigidBody(this);
	m_ItemCheck = new ItemCheck(this, m_case);
	monoBehaviors.push_back(m_ItemCheck);
	isCulling = false;
	
	Init();
}

Item::~Item()
{
}

void Item::Update()
{
	

	if (isCulling)
	{
		UpdateWorld();
		collider->Update();
		rigidBody->Update();
	
	if (animator == nullptr)
		image->Update();
	else
		animator->Update();
	}
	if (position[1] < 0)
		isCulling = false;
}

void Item::Render()
{
	if (isCulling)
	{
	collider->Render();
	if (animator == nullptr)
		image->Render();
	else
		animator->Play();
	}

}
