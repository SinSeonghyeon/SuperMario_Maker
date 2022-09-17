#pragma once

class GameObject;

class Collider;

class MonoBehavior
{
public:
	MonoBehavior(GameObject* gameObject)
		:gameObject(gameObject)
	{

	}

	GameObject* gameObject;

	virtual void Start() {}
	virtual void FixedUpdate() {}
	virtual void Update() {}
	virtual void OnCollide(Collider* other) {}
	virtual void StayCollide(Collider* other) {}
	virtual void ExitCollide(Collider* other) {}
	virtual void EnterTrigger(Collider* other) {}//ó�� ������ ��
	virtual void StayTrigger(Collider* other) {}//�ȿ� ���� ��
	virtual void ExitTrigger(Collider* other) {}// ������ ���� ��
};