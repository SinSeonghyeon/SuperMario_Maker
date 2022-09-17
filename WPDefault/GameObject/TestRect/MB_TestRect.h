#pragma once

class MB_TestRect : public MonoBehavior
{
public:
	MB_TestRect(GameObject* gameObject);

	void OnCollide(Collider* other) override;

	void EnterTrigger(Collider* other) override;
	void StayTrigger(Collider* other) override;
	void ExitTrigger(Collider* other) override;

};