#include "Framework.h"
#include "Collider.h"

extern bool testMode;

Collider::Collider()
	:Component(nullptr)
{
}

// 입력 값 : 콜라이더 가로 넓이 , 콜라이더 세로 높이 , 콜라이더 모양
Collider::Collider(GameObject* gameObject, int collider_width, int collider_height, ColldierShape colliderShape)
	:Component(gameObject), isTrigger(false), drawEnabled(testMode)
{
	SetParent(gameObject);

	width = collider_width;
	height = collider_height;
	Shape = colliderShape;
}

bool Collider::CheckCollider(Collider* other, Direction* col_direction, int* diff)
{
	// 둘다 원형 콜라이더 일 경우,
	if (Shape == Circle && other->Shape == Circle)
	{
		return CircleToCircle(other, col_direction, diff);
	}
	// 둘다 사각형 콜라이더 일 경우,
	else if (Shape == Rect && other->Shape == Rect)
	{
		return RectToRect(other, col_direction, diff);
	}
	// 둘이 서로 다른 콜라이더 일 경우,
	else
	{
		return RectToCircle(other, col_direction, diff);
	}

	return false;
}

// 사각형 콜라이더와 사각형 콜라이더 충돌시
bool Collider::RectToRect(Collider* other, Direction* col_direction, int* diff)
{
	int this_x1 = WorldPos()[0];
	int this_x2 = WorldPos()[0] + width;
	int this_y1 = WorldPos()[1];
	int this_y2 = WorldPos()[1] + height;

	int other_x1 = other->WorldPos()[0];
	int other_x2 = other->WorldPos()[0] + other->width;
	int other_y1 = other->WorldPos()[1];
	int other_y2 = other->WorldPos()[1] + other->height;


	// 하단에서 대상콜라이더와 충돌
	if (this_x2 >= other_x1 &&
		this_x1 <= other_x2 &&
		this_y2 >= other_y1 &&
		this_y1 <= other_y2)
	{

		//todo : 아랫쪽이 판별되는 기준을 넓게
		if (col_direction != nullptr)
		{
			int rightDiff = abs(this_x2 - other_x1);
			int leftDiff = abs(this_x1 - other_x2);
			int upDiff = abs(this_y1 - other_y2);
			int downDiff = abs(this_y2 - other_y1);

			int minDiff = min(min(rightDiff, leftDiff), min(upDiff, downDiff));

			if(diff != nullptr)
				*diff = minDiff;

			if (minDiff == downDiff)
				*col_direction = Down;
			else if (minDiff == rightDiff)
				*col_direction = Right;
			else if (minDiff == leftDiff)
				*col_direction = Left;
			else if (minDiff == upDiff)
				*col_direction = Up;
		}

		return true;
	}

	return false;
}

// 사각형 콜라이더와 원형 콜라이더 충돌시
bool Collider::RectToCircle(Collider* other, Direction* col_direction, int* diff)
{
	//todo : 이부분 주석 처리 해둠
	/*Collider RectCol, CirCol;
	if (Shape == Rect)
	{
		RectCol = *this;
		CirCol = *other;
	}
	else
	{
		CirCol = *this;
		RectCol = *other;
	}*/

	return false;
}

// 원형 콜라이더와 원형 콜라이더 충돌시
bool Collider::CircleToCircle(Collider* other, Direction* col_direction, int* diff)
{
	if (((WorldPos()[0] - other->WorldPos()[0]) * (WorldPos()[0] - other->WorldPos()[0])) +
		((WorldPos()[1] - other->WorldPos()[1]) * (WorldPos()[1] - other->WorldPos()[1])) <=
		(width + other->width) * (width + other->width))
	{
		return true;
	}
	return false;
}

void Collider::Update()
{
	UpdateWorld();
	if (KEYBOARD->Down('Q'))
	{
		drawEnabled = true;
	}
	if (KEYBOARD->Down('E'))
	{
		drawEnabled = false;
	}
}

void Collider::Render()
{
	if (drawEnabled && Shape == Rect)
	{
		//RENDERER->DrawRect(WorldPos(), { width,height });
		//Renderer2::Get()->DrawRect(WorldPos(), { width,height });
	}
	DebugRender();
}

// 디버그용 콜라이드 렌더 ( 연두색 속이빈 사각형 )
void Collider::DebugRender()
{
	if (drawEnabled && Shape == Rect)
	{
		int Colors[3];
		Colors[0] = 0, Colors[1] = 255, Colors[2] = 0;
		vector<float> xy_from(2);
		vector<float> xy_to(2);
		xy_from[0] = WorldPos()[0];
		xy_from[1] = WorldPos()[1];
		xy_to[0] = WorldPos()[0] + width;
		xy_to[1] = WorldPos()[1];
		RENDERER->DrawLine(xy_from,xy_to, Colors);
		RENDERER2->DrawLine(xy_from,xy_to, Colors);
		xy_from[0] = WorldPos()[0] + width;
		xy_from[1] = WorldPos()[1];
		xy_to[0] = WorldPos()[0] + width;
		xy_to[1] = WorldPos()[1] + height;
		RENDERER->DrawLine(xy_from, xy_to, Colors);
		RENDERER2->DrawLine(xy_from, xy_to, Colors);
		xy_from[0] = WorldPos()[0] + width;
		xy_from[1] = WorldPos()[1] + height;
		xy_to[0] = WorldPos()[0];
		xy_to[1] = WorldPos()[1] + height;
		RENDERER->DrawLine(xy_from, xy_to, Colors);
		RENDERER2->DrawLine(xy_from, xy_to, Colors);
		xy_from[0] = WorldPos()[0];
		xy_from[1] = WorldPos()[1] + height;
		xy_to[0] = WorldPos()[0];
		xy_to[1] = WorldPos()[1];
		RENDERER->DrawLine(xy_from, xy_to, Colors);
		RENDERER2->DrawLine(xy_from, xy_to, Colors);
	}		
}
