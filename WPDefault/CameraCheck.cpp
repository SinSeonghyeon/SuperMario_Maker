#include "Framework.h"
#include "CameraCheck.h"

CameraCheck::CameraCheck() :MonoBehavior(gameObject)
{

}

CameraCheck::~CameraCheck()
{
}

void CameraCheck::Update()
{
	//DebugPrint("ī�޶� ����");
}

void CameraCheck::EnterTrigger(Collider* other)
{
	if (other->gameObject->tag != "cam")
	{
		other->gameObject->isActive = true;
		other->gameObject->isView = true;
		DebugPrint("ī�޶� ���� %s\n", other->gameObject->name.c_str());
	}
}

void CameraCheck::OnCollide(Collider* other)
{
	if (other->gameObject->tag != "cam")
	{
		other->gameObject->isActive = true;
		other->gameObject->isView = true;
		DebugPrint("ī�޶� ���� %s\n", other->gameObject->name.c_str());
	}
}

void CameraCheck::ExitTrigger(Collider* other)
{
	if (other->gameObject->tag != "cam")
	{
		other->gameObject->isActive = false;
		other->gameObject->isView = false;
		DebugPrint("ī�޶󿡼� ���� %s\n", other->gameObject->name.c_str());
	}
}

void CameraCheck::ExitCollide(Collider* other)
{
	if (other->gameObject->tag != "cam")
	{
		other->gameObject->isActive = false;
		other->gameObject->isView = false;
		DebugPrint("ī�޶� ���� %s\n", other->gameObject->name.c_str());
	}
}
