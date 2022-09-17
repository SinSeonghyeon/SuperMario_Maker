#include "Framework.h"
#include "Collider.h"

Collider::Collider()
{

}

// 입력 값 : 콜라이더 가로 넓이 , 콜라이더 세로 높이 , 콜라이더 모양
Collider::Collider(int collider_width, int collider_height, ColldierShape colliderShape)
{
	width = collider_width;
	height = collider_height;
	Shape = colliderShape;
}

bool Collider::CheckCollider(Collider* other)
{
	// 둘다 원형 콜라이더 일 경우,
	if (Shape == Circle && other->Shape == Circle)
	{
		return RectToCircle(other);
	}
	// 둘다 사각형 콜라이더 일 경우,
	else if (Shape == Rectangle && other->Shape == Rectangle)
	{
		return RectToRect(other);
	}
	// 둘이 서로 다른 콜라이더 일 경우,
	else
	{
		return RectToCircle(other);
	}

	return false;
}

// 사각형 콜라이더와 사각형 콜라이더 충돌시
bool Collider::RectToRect(Collider* other)
{
	if (WorldPos()[0] + width / 2 >= other->WorldPos()[0] - other->width / 2 &&
		WorldPos()[0] - width / 2 <= other->WorldPos()[0] + other->width / 2 &&
		WorldPos()[1] + height / 2 >= other->WorldPos()[1] - other->height / 2 &&
		WorldPos()[1] - height / 2 <= other->WorldPos()[1] - other->height / 2)
	{
		return true;
	}

	return false;
}

// 사각형 콜라이더와 원형 콜라이더 충돌시
bool Collider::RectToCircle(Collider* other)
{
	Collider RectCol, CirCol;
	if (Shape == Rectangle)
	{
		RectCol = *this;
		CirCol = *other;
	}
	else
	{
		CirCol = *this;
		RectCol = *other;
	}

	return false;
}

// 원형 콜라이더와 원형 콜라이더 충돌시
bool Collider::CircleToCircle(Collider* other)
{
	if (((WorldPos()[0] - other->WorldPos()[0]) * (WorldPos()[0] - other->WorldPos()[0])) +
		((WorldPos()[1] - other->WorldPos()[1]) * (WorldPos()[1] - other->WorldPos()[1])) <=
		(width + other->width) * (width + other->width))
	{
		return true;
	}
	return false;
}

// 현재 충돌 방향을 반환하는 함수
CollisionDirection Collider::Return_CurrentCollisionDirection()
{
	return CollisionDirection();
}

void Collider::Update()
{

}
