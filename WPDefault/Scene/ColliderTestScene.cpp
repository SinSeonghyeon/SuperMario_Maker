#include "Framework.h"
#include "ColliderTestScene.h"
#include "GameObject/TestRect/TestRect.h"

ColliderTestScene::ColliderTestScene()
{

	rect = new TestRect();
	rect->name = "A";
	other = new TestRect();
	other->name = "B";

	theOther = new TestRect();
	other->collider->isTrigger = true;


	other->position = { 100.0f, 100.0f };
	theOther->position = { 300.0f, 300.0f };
}

ColliderTestScene::~ColliderTestScene()
{
	delete theOther;
	delete other;
	delete rect;
}

void ColliderTestScene::Update()
{
	Renderer::Get()->GetCamera()->Update();
	rect->Update();
	other->Update();
	theOther->Update();
	static int i = 0;
	Direction D_t;

	if (rect->collider->CheckCollider(other->collider, &D_t))
	{
		switch (D_t)
		{
			case Left:
			{
				DebugPrint("����");
			}break;
			case Right:
			{
				DebugPrint("������");
			}break;
			case Up:
			{
				DebugPrint("��");
			}break;
			case Down:
			{
				DebugPrint("�Ʒ�");
			}break;
		}

	}

	if (KEYBOARD->Press('W'))
	{
		rect->position[1] -= 50.0f * TIME->Delta();
	}
	if (KEYBOARD->Press('S'))
	{
		rect->position[1] += 50.0f * TIME->Delta();
	}
	if (KEYBOARD->Press('A'))
	{
		rect->position[0] -= 50.0f * TIME->Delta();
	}
	if (KEYBOARD->Press('D'))
	{
		rect->position[0] += 50.0f * TIME->Delta();
	}
}

void ColliderTestScene::Render()
{
	rect->Render();
	other->Render();
	theOther->Render();
}
