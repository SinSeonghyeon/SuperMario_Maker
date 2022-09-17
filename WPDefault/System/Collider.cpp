#include "Framework.h"
#include "Collider.h"

Collider::Collider()
{

}

// �Է� �� : �ݶ��̴� ���� ���� , �ݶ��̴� ���� ���� , �ݶ��̴� ���
Collider::Collider(int collider_width, int collider_height, ColldierShape colliderShape)
{
	width = collider_width;
	height = collider_height;
	Shape = colliderShape;
}

bool Collider::CheckCollider(Collider* other)
{
	// �Ѵ� ���� �ݶ��̴� �� ���,
	if (Shape == Circle && other->Shape == Circle)
	{
		return RectToCircle(other);
	}
	// �Ѵ� �簢�� �ݶ��̴� �� ���,
	else if (Shape == Rectangle && other->Shape == Rectangle)
	{
		return RectToRect(other);
	}
	// ���� ���� �ٸ� �ݶ��̴� �� ���,
	else
	{
		return RectToCircle(other);
	}

	return false;
}

// �簢�� �ݶ��̴��� �簢�� �ݶ��̴� �浹��
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

// �簢�� �ݶ��̴��� ���� �ݶ��̴� �浹��
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

// ���� �ݶ��̴��� ���� �ݶ��̴� �浹��
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

// ���� �浹 ������ ��ȯ�ϴ� �Լ�
CollisionDirection Collider::Return_CurrentCollisionDirection()
{
	return CollisionDirection();
}

void Collider::Update()
{

}
