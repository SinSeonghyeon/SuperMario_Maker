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
	//DebugPrint("카메라에 들어옴");
}

void CameraCheck::EnterTrigger(Collider* other)
{
	if (other->gameObject->tag != "cam")
	{
		other->gameObject->isActive = true;
		other->gameObject->isView = true;
		DebugPrint("카메라에 들어옴 %s\n", other->gameObject->name.c_str());
	}
}

void CameraCheck::OnCollide(Collider* other)
{
	if (other->gameObject->tag != "cam")
	{
		other->gameObject->isActive = true;
		other->gameObject->isView = true;
		DebugPrint("카메라에 들어옴 %s\n", other->gameObject->name.c_str());
	}
}

void CameraCheck::ExitTrigger(Collider* other)
{
	if (other->gameObject->tag != "cam")
	{
		other->gameObject->isActive = false;
		other->gameObject->isView = false;
		DebugPrint("카메라에서 나감 %s\n", other->gameObject->name.c_str());
	}
}

void CameraCheck::ExitCollide(Collider* other)
{
	if (other->gameObject->tag != "cam")
	{
		other->gameObject->isActive = false;
		other->gameObject->isView = false;
		DebugPrint("카메라에 나감 %s\n", other->gameObject->name.c_str());
	}
}
