#include "Framework.h"
#include "MB_TestRect.h"

MB_TestRect::MB_TestRect(GameObject* gameObject)
	:MonoBehavior(gameObject)
{
}

void MB_TestRect::OnCollide(Collider* other)
{
	DebugPrint("%s : On Collide!", gameObject->name.c_str());
}

void MB_TestRect::EnterTrigger(Collider* other)
{
	DebugPrint("%s : Enter Trigger!", gameObject->name.c_str());
}

void MB_TestRect::StayTrigger(Collider* other)
{
	DebugPrint("%s : Stay Trigger!", gameObject->name.c_str());
}

void MB_TestRect::ExitTrigger(Collider* other)
{
	DebugPrint("%s : Exit Trigger!", gameObject->name.c_str());
}
