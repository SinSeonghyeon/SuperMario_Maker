#include "Framework.h"
#include "0_GameObject.h"

GameObject::GameObject(string tag, string name)
	:tag(tag), collider(nullptr), rigidBody(nullptr), image(nullptr),name(name)
{
}

GameObject::~GameObject()
{
	GOM->Sub(this);//���� ������Ʈ���� ���̻� �������� ����!

	if (animator != nullptr)
		delete animator;

	if (image != nullptr)
		delete image;
	
	if (collider != nullptr)
		delete collider;
	if (rigidBody != nullptr)
		delete rigidBody;
	for (MonoBehavior* mB : monoBehaviors)
		delete mB;
}

void GameObject::Init()
{
	UpdateWorlds();
	GOM->Add(this);//���� ������Ʈ �Ŵ����� ���
}

void GameObject::UpdateWorlds()
{
	UpdateWorld();

	if (animator != nullptr)
		animator->Update();

	if (image != nullptr)
		image->UpdateWorld();

	if (collider != nullptr)
		collider->UpdateWorld();
}
