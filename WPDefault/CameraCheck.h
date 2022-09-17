#pragma once
class CameraCheck : public MonoBehavior
{
public:
	CameraCheck();
	~CameraCheck();
private:

	void Update() override;


	void EnterTrigger(Collider* other) override;
	void OnCollide(Collider* other) override;
	 void ExitTrigger(Collider* other)  override;
	 void ExitCollide(Collider* other)  override;

};

