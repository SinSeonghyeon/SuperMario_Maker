#pragma once
// 콜라이더 모양 열거형
enum ColldierShape
{
	Circle,
	Rectangle
};

// 콜라이더 충돌 방향 열거형
enum CollisionDirection
{
	Up,
	Down,
	Left,
	Right
};

class Collider : public Transform 
{
	// 가로넓이 , 세로길이
	int width, height;
	// 콜라이더 모양
	ColldierShape Shape;
	// 콜라이더가 충돌한 방향( 충돌 상태가 아닐 경우 NULL )
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