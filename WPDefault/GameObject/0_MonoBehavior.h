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
	virtual void EnterTrigger(Collider* other) {}//처음 진입할 시
	virtual void StayTrigger(Collider* other) {}//안에 있을 시
	virtual void ExitTrigger(Collider* other) {}// 밖으로 나갈 시
};