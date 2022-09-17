#pragma once

class RigidBody : public Component
{
public:
	RigidBody(GameObject* gameObject);
	~RigidBody();

	void Update();

	void CalculateGravity();

	void AddForce(float length, float Vector[2]);//length = ��,Vector[0] = x,  Vector[1] = y,
	float force[2];
private:
	bool forceXsign, forceYsign;//Addforce�Է´���� force  ��ȣ ����, true = ���, false = ����

	void ConductGravity();//�߷� �����Ű�� �Լ�
	void ConductForce();//���� ���� ��Ű�� �Լ�, Update���� ��ġ�� ��� ��ȭ������
	void ApplyFriction();//force ���������� ���� ��Ű�� �Լ�

public:
	float gravity;//�������� �ӵ�

	bool isOnAir;

	float friction;//AddForce�ϰ� �������� �ϴ� �װ�

	//todo : AddForce����, �߷� ����, Move ����

private:
	class GameObject* self;//�Ҽӵ� ���� ������Ʈ
	class Collider* collider;//���� ������Ʈ�� �ݶ��̴�
};