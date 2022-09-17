#pragma once

class Camera : public GameObject
{
public:
	Camera(int num);

	// GameObject을(를) 통해 상속됨
	void Update() override;
	void Render() override;
	

	bool IsInCamera(Collider* other);
	int num;
private:
	void Move();
	float cameraSpeed;
};