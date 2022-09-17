#pragma once
// �ݶ��̴� ��� ������
enum ColldierShape
{
	Circle,
	Rectangle
};

// �ݶ��̴� �浹 ���� ������
enum CollisionDirection
{
	Up,
	Down,
	Left,
	Right
};

class Collider : public Transform 
{
	// ���γ��� , ���α���
	int width, height;
	// �ݶ��̴� ���
	ColldierShape Shape;
	// �ݶ��̴��� �浹�� ����( �浹 ���°� �ƴ� ��� NULL )
	CollisionDirection Col_direction;

public :

	Collider();
	Collider(int collider_width, int collider_height, ColldierShape colliderShape);

	bool CheckCollider(Collider* other);
	bool RectToRect(Collider* other);
	bool RectToCircle(Collider* other);
	bool CircleToCircle(Collider* other);
	CollisionDirection Return_CurrentCollisionDirection();

	void Update();
};