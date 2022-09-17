#pragma once

class Camera : public GameObject
{
public:
	Camera(int num);

	// GameObject��(��) ���� ��ӵ�
	void Update() override;
	void Render() override;
	

	bool IsInCamera(Collider* other);
	int num;
private:
	void Move();
	float cameraSpeed;
};