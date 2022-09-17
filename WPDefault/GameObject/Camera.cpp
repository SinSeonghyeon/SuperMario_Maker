#include "Framework.h"
#include "Camera.h"
#include "CameraCheck.h"
Camera::Camera(int num)
	:GameObject("cam"), cameraSpeed(100.0f)
{
	if (num == 0)
	{
		collider = new Collider(this, WINDOW_SIZE_X*2, WINDOW_SIZE_Y);
		rigidBody = new RigidBody(this);
		collider->isTrigger = true;
		monoBehaviors.push_back(new CameraCheck());
		rigidBody->gravity = 0;
	
	Init();
	}
}

void Camera::Update()
{
	Move();
	if (num == 0)
	{
		collider->Update();
		rigidBody->Update();
	
	UpdateWorld();
	}
}
void Camera::Render()
{
	if (num == 0)
	{
		collider->Render();
	}
}

void Camera::Move()
{

}
