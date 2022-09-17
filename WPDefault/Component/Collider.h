#pragma once
// �ݶ��̴� ��� ������
enum ColldierShape
{
	Circle,
	Rect//Rectangle, Window�Լ��� ���ļ� �̸� �ٲ�(�����)
};

// ���� ������
typedef enum
{
	Up,
	Down,
	Left,
	Right
}Direction;

class Collider : public Transform, public Component
{
	// ���γ��� , ���α���
	int width, height;
	// �ݶ��̴� ���
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
	bool drawEnabled;//todo : ����׿� �ݶ��̴� �׸���
};