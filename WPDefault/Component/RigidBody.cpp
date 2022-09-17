#include "Framework.h"

RigidBody::RigidBody(GameObject* gameObject)
	:Component(gameObject), gravity(800.0f), isOnAir(true), friction(7000.0f), forceXsign(true), forceYsign(true)
{
	assert(gameObject->collider != nullptr);//콜라이더가 없으면 에러
	collider = gameObject->collider;
}

RigidBody::~RigidBody()
{
}

void RigidBody::Update()
{

	CalculateGravity();
	ConductGravity();


	ConductForce();
	ApplyFriction();

}

void RigidBody::CalculateGravity()
{
}

void RigidBody::AddForce(float length, float Vector[2])
{
	float VectorLength = sqrt(pow(Vector[0], 2) + pow(Vector[1], 2));
	float normalizedVector[2] = { Vector[0] / VectorLength, Vector[1] / VectorLength };

	force[0] += normalizedVector[0] * length;
	force[1] += normalizedVector[1] * length;

	forceXsign = force[0] >= 0 ? true : false;
	forceYsign = force[1] >= 0 ? true : false;
 }

void RigidBody::ConductGravity()
{//todo : 클리핑, collider* temp 만들고 검사하기, gameObjectManager에서 하기?
	if (isOnAir)
		gameObject->position[1] += TIME->Delta() * gravity;
}

void RigidBody::ConductForce()
{
	gameObject->position[0] += TIME->Delta() * force[0];
	gameObject->position[1] += TIME->Delta() * force[1];
}

void RigidBody::ApplyFriction()
{
	float VectorLength = sqrt(pow(force[0], 2) + pow(force[1],2));
	float cos = force[0] / VectorLength;
	float sin = force[1] / VectorLength;

	bool sign = false;//부호 비교를 위한 temp

	force[0] -=  cos * friction * TIME->Delta();

	sign = force[0] >= 0 ? true : false;

	if (sign != forceXsign)
	{
		force[0] = 0.0f;
		forceXsign = true;
	}


	force[1] -= sin * friction * TIME->Delta();
	
	sign = force[1] >= 0 ? true : false;

	if (sign != forceYsign)
	{
		force[1] = 0.0f;
		forceYsign = true;
	}
}
