#pragma once

class RigidBody : public Component
{
public:
	RigidBody(GameObject* gameObject);
	~RigidBody();

	void Update();

	void CalculateGravity();

	void AddForce(float length, float Vector[2]);//length = 힘,Vector[0] = x,  Vector[1] = y,
	float force[2];
private:
	bool forceXsign, forceYsign;//Addforce입력당시의 force  부호 저장, true = 양수, false = 음수

	void ConductGravity();//중력 적용시키는 함수
	void ConductForce();//힘을 적용 시키는 함수, Update에서 위치를 계속 변화시켜줌
	void ApplyFriction();//force 지속적으로 감소 시키는 함수

public:
	float gravity;//떨어지는 속도

	bool isOnAir;

	float friction;//AddForce하고 느려지게 하는 그거

	//todo : AddForce구현, 중력 구현, Move 구현

private:
	class GameObject* self;//소속된 게임 오브젝트
	class Collider* collider;//게임 오브젝트의 콜라이더
};