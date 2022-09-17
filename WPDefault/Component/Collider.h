#pragma once
// 콜라이더 모양 열거형
enum ColldierShape
{
	Circle,
	Rect//Rectangle, Window함수와 겹쳐서 이름 바꿈(안재우)
};

// 방향 열거형
typedef enum
{
	Up,
	Down,
	Left,
	Right
}Direction;

class Collider : public Transform, public Component
{
	// 가로넓이 , 세로길이
	int width, height;
	// 콜라이더 모양
	ColldierShape Shape;

public :
	Collider();
	Collider(GameObject* gameObject,int collider_width, int collider_height, ColldierShape colliderShape = Rect);

	bool CheckCollider(Collider* other, Direction* col_direction = nullptr, int* diff = 0);
	bool RectToRect(Collider* other, Direction* col_direction = nullptr, int* diff = 0);
	bool RectToCircle(Collider* other, Direction* col_direction = nullptr, int* diff = 0);
	bool CircleToCircle(Collider* other, Direction* col_direction = nullptr, int* diff = 0);

	void Update();
	void Render();
	void DebugRender();

	bool isTrigger;
	bool drawEnabled;//todo : 디버그용 콜라이더 그리기
};