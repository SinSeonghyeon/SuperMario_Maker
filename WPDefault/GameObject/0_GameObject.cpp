#include "Framework.h"
#include "0_GameObject.h"

GameObject::GameObject(string tag, string name)
	:tag(tag), collider(nullptr), rigidBody(nullptr), image(nullptr),name(name)
{
}

GameObject::~GameObject()
{
	GOM->Sub(this);//게임 오브젝트에서 더이상 관리하지 않음!

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
	GOM->Add(this);//게임 오브젝트 매니저에 등록
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
